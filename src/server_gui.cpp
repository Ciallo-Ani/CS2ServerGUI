#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <thread>
#include "server_gui.h"
#include <core/sm_callfnptr.h>
#include <core/sm_interfaces.h>
#include <core/sm_entitylist.h>
#include <sdk/common/common.h>
#include <sdk/networkstringtabledefs.h>
#include "interfaces.h"
#include "networksystem/inetworkmessages.h"
#include "imgui/main.h"
#include "imgui/panels/eventlogger/eventlogger.h"
#include <sdk/protobuf/netmessages.pb.h>
#include <sdk/protobuf/usercmd.pb.h>
#include <sdk/protobuf/cs_usercmd.pb.h>
#include <sdk/tier0/CCvar.h>
#include <funchook.h>


ServerGUI g_ServerGUI;
SMEXT_LINK(g_ServerGUI);

std::thread g_thread;

typedef bool (*FilterMessage_t)(CServerSideClientBase* player, INetworkSerializable* pEvent, void* pData, void* pNetChan);
FilterMessage_t g_pFilterMessage = nullptr;
funchook_t* g_pHookFilterMessage = nullptr;

CON_COMMAND(gui, "Opens server GUI", FCVAR_LINKED_CONCOMMAND | FCVAR_SPONLY | FCVAR_SERVER_CAN_EXECUTE)
{
	if (!GUI::g_GUICtx.m_bIsGUIOpen)
	{
		g_thread = std::thread(GUI::InitializeGUI);
		g_thread.detach();
	}
}

template <typename T>
bool ReadPBFromBuffer(bf_read& buffer, T& pb)
{
	auto size = buffer.ReadVarInt32();

	if (size < 0 || size > 262140)
	{
		return false;
	}

	if (size > buffer.GetNumBytesLeft())
	{
		return false;
	}

	if ((buffer.GetNumBitsRead() % 8) == 0)
	{
		bool parseResult = pb.ParseFromArray(buffer.GetBasePointer() + buffer.GetNumBytesRead(), size);
		buffer.SeekRelative(size * 8);

		return true;
	}

	void* parseBuffer = stackalloc(size);
	if (!buffer.ReadBytes(parseBuffer, size))
	{
		return false;
	}

	if (!pb.ParseFromArray(parseBuffer, size))
	{
		return false;
	}

	return true;
}

bool Detour_FilterMessage(CServerSideClientBase* player, INetworkSerializable* pEvent, void* pData, void* pNetChan) {
	if (!GUI::g_GUICtx.m_WindowStates.m_bEventLogger)
		return g_pFilterMessage(player, pEvent, pData, pNetChan);

	NetMessageInfo_t* info = pEvent->GetNetMessageInfo();
	if (info)
	{
		if (info->m_MessageId == CLC_Messages::clc_Move)
		{
			CCLCMsg_Move* msg = (CCLCMsg_Move*)pData;

			if (msg->has_data() && msg->has_num_commands() && msg->num_commands() >= 1)
			{
				bf_read buffer(msg->data().data(), msg->data().size());

				for (int i = 0; i < msg->num_commands(); i++)
				{
					CSGOUserCmdPB userCmd;
					if (ReadPBFromBuffer(buffer, userCmd))
						GUI::EventLogger::AddEventLog(std::string(info->m_pBinding->GetName()), std::string(userCmd.DebugString().c_str()), true, std::string(player->GetClientName()));
				}
			}
		}
		else
		{
			CUtlString str;
			info->m_pBinding->ToString(pData, str);
			GUI::EventLogger::AddEventLog(std::string(info->m_pBinding->GetName()), std::string(str.String()), true, std::string(player->GetClientName()));
		}
	}

	return g_pFilterMessage(player, pEvent, pData, pNetChan);
}

void Hook_PostEvent(CGameEventSystem* pThis, CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64* clients,
	INetworkSerializable* pEvent, const void* pData, unsigned long nSize, NetChannelBufType_t bufType) {
	if (!GUI::g_GUICtx.m_WindowStates.m_bEventLogger)
		return;

	NetMessageInfo_t* info = pEvent->GetNetMessageInfo();
	if (info)
	{
		CUtlString str;
		info->m_pBinding->ToString(pData, str);

		GUI::EventLogger::AddEventLog(std::string(info->m_pBinding->GetName()), std::string(str.String()), false);
	}
}

bool SetupInterfaces() {
	Ifaces::eventSystem = Interfaces()->GetFactory<CGameEventSystem*>("engine2.dll", "GameEventSystemServerV001");
	Ifaces::engine = Interfaces()->GetFactory<CEngineServer*>("engine2.dll", "Source2EngineToServer001");
	Ifaces::cvar = Interfaces()->GetFactory<CCVar*>("tier0.dll", "VEngineCvar007");
	Ifaces::server = Interfaces()->GetFactory<CSource2Server*>("server.dll", "Source2Server001");
	Ifaces::networkMessages = Interfaces()->GetFactory<INetworkMessages*>("networksystem.dll", "NetworkMessagesVersion001");
	Ifaces::networkService = Interfaces()->GetFactory<CNetworkServerService*>("engine2.dll", "NetworkServerService_001");
	Ifaces::networkStringTableContainerServer = Interfaces()->GetFactory<INetworkStringTableContainer*>("engine2.dll", "Source2EngineToServerStringTable001");

	//GET_V_IFACE_ANY(GetServerFactory, Ifacesgameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
	//GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameResourceServiceServer, IGameResourceServiceServer, GAMERESOURCESERVICESERVER_INTERFACE_VERSION);

	return true;
}

bool SetupHook()
{
	const char* engineModule = "engine2" MODULE_EXT;
	const char Sig_FilterMessage[] = "40 53 48 83 EC 30 48 3B 15 ? ? ? ? 48 8B D9";
	g_pFilterMessage = (FilterMessage_t)libmem::SignScan(Sig_FilterMessage, engineModule);
	if (!g_pFilterMessage) {
		Logger()->PrintToConsole("Failed to find signature \'ServerGUI::g_pFilterMessage\'\n");
		return false;
	}

	g_pHookFilterMessage = funchook_create();
	funchook_prepare(g_pHookFilterMessage, (void**)&g_pFilterMessage, (void*)Detour_FilterMessage);
	funchook_install(g_pHookFilterMessage, 0);

	vmt::SetVMethod(16, Ifaces::eventSystem, Hook_PostEvent);
}

CGameEntitySystem* GameEntitySystem()
{
	return GameEntityList()->GetInstance();
}

CGlobalVars* GetGameGlobals()
{
	auto server = EngineServer();
	if (!server)
		return nullptr;

	return server->GlobalVars();
}

bool ServerGUI::OnLoad() {
	const std::filesystem::path path("../../csgo/addons/source2mod/configs/server_gui/config.json");
	m_config.SetPath(path);
	if (!m_config.LoadConfig()) {
		Logger()->PrintToConsole("Failed to get config from \'%s\'", path.c_str());
		return false;
	}

	if (!SetupInterfaces()) {
		Logger()->PrintToConsole("Failed to get interface.");
		return false;
	}

	if (!SetupHook()) {
		return false;
	}

	return true;
}

void ServerGUI::OnUnload() {
	funchook_uninstall(g_pHookFilterMessage, 0);
	funchook_destroy(g_pHookFilterMessage);
}

void ServerGUI::OnAllLoaded() {
}

void ServerGUI::OnSDKInitialized() {

}

void ServerGUI::OnDependenciesDropped() {
}