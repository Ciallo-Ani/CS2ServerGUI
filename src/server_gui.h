#include <bridge/sm_extension.h>
#include "config/config.h"

class ServerGUI : public CSmExtension {
public:
	// Called on Source2Mod injected, just after the server launch and before Source2Mod initialized.
	virtual bool OnLoad();

	// Called on extension unload.
	virtual void OnUnload();

	// Called on all extensions loaded.
	virtual void OnAllLoaded();

	// Called on Source2Mod initialized (OnMapStart).
	virtual void OnSDKInitialized();

	void OnDependenciesDropped() override;
public:
	PluginConfig m_config;
};

extern ServerGUI g_ServerGUI;