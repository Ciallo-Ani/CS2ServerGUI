```
class INetworkMessageProcessingPreFilter {
	virtual void FilterMessages() = 0;
};

#pragma pack(push, 1)
class CServerSideClientBase : public INetworkMessageProcessingPreFilter {
public:
	INetChannel* GetNetChannel() const { return m_NetChannel; }
	int32_t GetPlayerSlot() const { return m_nClientSlot; }
	uint8_t GetUserID() const { return m_UserID; }
	int GetSignonState() const { return m_nSignonState; }
	CSteamID* GetClientSteamID() const { return (CSteamID*)&m_SteamID; }
	const char* GetClientName() const { return m_Name.Get(); }
	netadr_t* GetRemoteAddress() const { return (netadr_t*)&m_NetAdr; }

public:
	[[maybe_unused]] char pad1[0x38];		// index
	CNetworkGameServer* m_NetGameSrv;		// 64
	INetChannel* m_NetChannel;				// 72
	int32 m_unk01;							// 80
	int32 m_nSignonState;					// 84
	int64 m_unk02;							// 88
	CServerSideClient* m_pClient;			// 96 ... idk what to do
	[[maybe_unused]] char pad2[0x30];		// 104
	uint16 m_UserID;						// 152
	[[maybe_unused]] char pad3[0x1];		// 154
	CSteamID m_SteamID[4];					// 155
	[[maybe_unused]] char pad4[0x5];		// 187
	char* m_pszSteam3;						// 192
	int32 m_nClientSlot;					// 196
	int32 m_entityIndex;					// 200
	CUtlString m_Name;						// 208
	[[maybe_unused]] char pad5[0x20];		// 216
	netadr_t m_NetAdr;						// 248
	[[maybe_unused]] char pad6[0x40];		// 260
	int32 m_nDeltaTick;						// 324
}; // Size: 328
#pragma pack(pop)
static_assert(sizeof(CServerSideClientBase) == 328);
```
