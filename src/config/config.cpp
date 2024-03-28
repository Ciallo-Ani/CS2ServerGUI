#include "config.h"
#include <tools/json.h>
#include <fstream>
#include <tier0/dbg.h>
#include <core/sm_log.h>

bool PluginConfig::LoadConfig()
{
	std::ifstream file(m_path);

	if (!file.is_open()) return false;

	try
	{
		m_json << file;
		file.close();
	}
	catch (const std::exception& e)
	{
		Logger()->PrintToConsole("Exception: %s", e.what());
		return false;
	}

	return true;
}
void PluginConfig::SaveConfig()
{
	/*std::ofstream file(m_path);

	if (!file.is_open())
		return;

	json j = {
		{"WelcomeSeen", m_bWelcomeSeen}
	};

	file << j.dump(2);
	file.close();*/
}

json PluginConfig::GetConfig()
{
	return m_json["server_gui"];
}
