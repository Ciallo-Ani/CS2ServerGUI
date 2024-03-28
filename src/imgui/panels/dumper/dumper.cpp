/**
 * =============================================================================
 * CS2ServerGUI
 * Copyright (C) 2024 Poggu
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "dumper.h"
#include "imgui/main.h"
#include "interfaces.h"
#include "server_gui.h"
#include "entitylist/entitylist.h"
#include "convarlist/convarlist.h"
#include "commandlist/commandlist.h"
#include <string>
#include <imgui.h>
#include <vector>
#include <iostream>


namespace GUI::Dumper
{

void Draw(bool* isOpen)
{
	const json& config = g_ServerGUI.m_config.GetConfig();
	const json::array_t& size = config["dumper"]["init_size"];
	const json::array_t& pos = config["dumper"]["init_pos"];

	ImGui::SetNextWindowSize(ImVec2(size[0], size[1]), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowPos(ImVec2(pos[0], pos[1]), ImGuiCond_FirstUseEver);
	ImGui::Begin("Dumper", isOpen);
	/*if (ImGui::Button("Check")) {
		auto winSize = ImGui::GetWindowSize();
		std::cout << "WindowSize: " << winSize.x << " | " << winSize.y << std::endl;

		auto winPos = ImGui::GetWindowPos();
		std::cout << "WindowPos: " << winPos.x << " | " << winPos.y << std::endl;
	}*/

	if (ImGui::BeginTabBar("DumperTabs"))
	{
		if (ImGui::BeginTabItem("Entity List"))
		{
			EntityList::Draw();
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("ConVar List"))
		{
			ConVarList::Draw();
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Command List"))
		{
			CommandList::Draw();
			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}

	ImGui::End();
}

} // namespace GUI::Dumper