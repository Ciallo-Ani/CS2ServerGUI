#ifndef __EXTENSION_SERVERGUI_INTERFACES__
#define __EXTENSION_SERVERGUI_INTERFACES__

class CGameEventSystem;
class CEngineServer;
class CCVar;
class CSource2Server;
class INetworkMessages;
class CNetworkServerService;
class INetworkStringTableContainer;

namespace Ifaces
{
	inline CGameEventSystem* eventSystem = nullptr;
	inline CEngineServer* engine = nullptr;
	inline CCVar* cvar = nullptr;
	inline CSource2Server* server;
	inline INetworkMessages* networkMessages = nullptr;
	inline CNetworkServerService* networkService = nullptr;
	inline INetworkStringTableContainer* networkStringTableContainerServer;
} // namespace Ifaces

#endif