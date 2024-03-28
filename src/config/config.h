#include <filesystem>
#include <tools/json.h>

using json = nlohmann::json;

class PluginConfig
{
public:
	void SetPath(const std::filesystem::path& path) { m_path = path; }
public:
	bool LoadConfig();
	void SaveConfig();
	json GetConfig();
public:
	bool m_bWelcomeSeen = false;
private:
	std::filesystem::path m_path;
	json m_json;
};