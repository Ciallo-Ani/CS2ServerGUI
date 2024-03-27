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

#include "convarlist.h"
#include "imgui/main.h"
#include "interfaces.h"
#include "imgui/panels/dumper/commandlist/commandlist.h"
#include <string>
#include <imgui.h>
#include <vector>
#include <imgui-notify/ImGuiNotify.hpp>
#include <ImGuiFileDialog.h>
#include <tools/json.h>
#include <sdk/tier0/CCvar.h>

#define FCVAR_MISSING5	((uint64_t)1<<(uint64_t)30)
#define FCVAR_MISSING6	((uint64_t)1<<(uint64_t)31)
#define FCVAR_DEFENSIVE	((uint64_t)1<<(uint64_t)32)

using json = nlohmann::json;

namespace GUI::Dumper::ConVarList
{

std::string StringifyValue(ConVar* pCvar)
{
	auto value = pCvar->GetDefault();

	switch (pCvar->m_eVarType)
	{
	case ConVarType::Bool:
		return value->m_bValue ? "true" : "false";
	/*case ConVarType::Int16:
		return std::to_string(value->m_i16Value);
	case ConVarType::UInt16:
		return std::to_string(value->m_u16Value);*/
	case ConVarType::Int32:
		return std::to_string(value->m_i32Value);
	/*case ConVarType::UInt32:
		return std::to_string(value->m_u32Value);
	case ConVarType::Int64:
		return std::to_string(value->m_i64Value);
	case ConVarType::UInt64:
		return std::to_string(value->m_u64Value);*/
	case ConVarType::Float32:
		return std::to_string(std::round(value->m_flValue * 10000.0f) / 10000.0f);
	/*case ConVarType::Float64:
		return std::to_string(value->m_dbValue);*/
	case ConVarType::String:
		return value->m_pszString ? value->m_pszString : "";
	/*case ConVarType::Color:
		return std::format("{} {} {} {}", value->m_clrValue.r, value->m_clrValue.g, value->m_clrValue.b, value->m_clrValue.a);
	case ConVarType::Vector2:
		return std::format("{} {}", value->m_vec2Value.x, value->m_vec2Value.y);
	case ConVarType::Vector3:
		return std::format("{} {} {}", value->m_vec3Value.x, value->m_vec3Value.y, value->m_vec3Value.z);
	case ConVarType::Vector4:
		return std::format("{} {} {} {}", value->m_vec4Value.x, value->m_vec4Value.y, value->m_vec4Value.z, value->m_vec4Value.w);
	case ConVarType::Qangle:
		return std::format("{} {} {}", value->m_angValue.x, value->m_angValue.y, value->m_angValue.z);*/
	default:
		return "Unknown";
	}
}

void ValueToJson(ConVar* pCvar, json& j)
{
	auto value = pCvar->GetDefault();

	switch (pCvar->m_eVarType)
	{
	case ConVarType::Bool:
		j["default"] = value->m_bValue;
		break;
	/*case ConVarType::Int16:
		j["default"] = value->m_i16Value;
		if(pCvar->m_pMinValue)
			j["min"] = pCvar->m_pMinValue->m_i16Value;
		if (pCvar->m_pMaxValue)
			j["max"] = pCvar->m_pMaxValue->m_i16Value;
		break;
	case ConVarType::UInt16:
		j["default"] = value->m_u16Value;
		if (pCvar->m_pMinValue)
			j["min"] = pCvar->m_pMinValue->m_u16Value;
		if (pCvar->m_pMaxValue)
			j["max"] = pCvar->m_pMaxValue->m_u16Value;
		break;*/
	case ConVarType::Int32:
		j["default"] = value->m_i32Value;
		if (pCvar->m_pMinValue)
			j["min"] = pCvar->m_pMinValue->m_i32Value;
		if (pCvar->m_pMaxValue)
			j["max"] = pCvar->m_pMaxValue->m_i32Value;
		break;
	/*case ConVarType::UInt32:
		j["default"] = value->m_u32Value;
		if (pCvar->m_pMinValue)
			j["min"] = pCvar->m_pMinValue->m_u32Value;
		if (pCvar->m_pMaxValue)
			j["max"] = pCvar->m_pMaxValue->m_u32Value;
		break;
	case ConVarType::Int64:
		j["default"] = value->m_i64Value;
		if (pCvar->m_pMinValue)
			j["min"] = pCvar->m_pMinValue->m_i64Value;
		if (pCvar->m_pMaxValue)
			j["max"] = pCvar->m_pMaxValue->m_i64Value;
		break;
	case ConVarType::UInt64:
		j["default"] = value->m_u64Value;
		if (pCvar->m_pMinValue)
			j["min"] = pCvar->m_pMinValue->m_u64Value;
		if (pCvar->m_pMaxValue)
			j["max"] = pCvar->m_pMaxValue->m_u64Value;
		break;*/
	case ConVarType::Float32:
		j["default"] = (json::number_float_t)(round((int)(value->m_flValue * 10000)) / 10000);
		if (pCvar->m_pMinValue)
			j["min"] = (json::number_float_t)(round((int)(pCvar->m_pMinValue->m_flValue * 10000)) / 10000);
		if (pCvar->m_pMaxValue)
			j["max"] = (json::number_float_t)(round((int)(pCvar->m_pMaxValue->m_flValue * 10000)) / 10000);
		break;
	/*case ConVarType::Float64:
		j["default"] = value->m_dbValue;
		if (pCvar->m_pMinValue)
			j["min"] = pCvar->m_pMinValue->m_dbValue;
		if (pCvar->m_pMaxValue)
			j["max"] = pCvar->m_pMaxValue->m_dbValue;
		break;*/
	case ConVarType::String:
		j["default"] = value->m_pszString ? value->m_pszString : "";
		break;
	/*case ConVarType::Color:
		j["default"] = { value->m_clrValue.r, value->m_clrValue.g, value->m_clrValue.b, value->m_clrValue.a };
		break;
	case ConVarType::Vector2:
		j["default"] = { value->m_vec2Value.x, value->m_vec2Value.y };
		break;
	case ConVarType::Vector3:
		j["default"] = { value->m_vec3Value.x, value->m_vec3Value.y, value->m_vec3Value.z };
		break;
	case ConVarType::Vector4:
		j["default"] = { value->m_vec4Value.x, value->m_vec4Value.y, value->m_vec4Value.z, value->m_vec4Value.w };
		break;
	case ConVarType::Qangle:
		j["default"] = { value->m_angValue.x, value->m_angValue.y, value->m_angValue.z };
		break;*/
	default:
		j["default"] = "Unknown";
		break;
	}
}

void DumpToJSON(std::string& path)
{
	json jsonArray;
	ConVar* pCvar = nullptr;
	ConVarHandle hCvarHandle;
	hCvarHandle.Set(0);

	do
	{
		pCvar = Ifaces::cvar->GetConVar(hCvarHandle);

		hCvarHandle.Set(hCvarHandle.Get() + 1);

		if (!pCvar)
			continue;

		json cvar;
		cvar["name"] = pCvar->GetName();
		cvar["description"] = pCvar->GetHelpText();

		ValueToJson(pCvar, cvar);

		cvar["type"] = pCvar->m_eVarType;
		cvar["flags"] = CommandList::PrettifyFlags(static_cast<uint64_t>(pCvar->GetFlags()));
		cvar["flagsRaw"] = static_cast<uint64_t>(pCvar->GetFlags());
		jsonArray.push_back(cvar);
	} while (pCvar);

	std::ofstream file(path);
	file << jsonArray.dump();
	file.close();
}

void Draw()
{
	static ImGuiTextFilter m_nameFilter;

	m_nameFilter.Draw("Search");

	if (ImGui::Button("Dump to file"))
	{
		const char* filters = "JSON File (*.json){.json}";
		IGFD::FileDialogConfig config;
		config.path = ".";
		config.fileName = "convars.json";
		config.countSelectionMax = 1;
		config.flags = ImGuiFileDialogFlags_Default;
		ImGuiFileDialog::Instance()->OpenDialog("SaveConvarFileDlg", "Choose a File", filters, config);
	}

	if (ImGui::BeginTable("Convar List", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_RowBg))
	{
		ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 200.f);
		ImGui::TableSetupColumn("Default Value", ImGuiTableColumnFlags_WidthFixed, 40.f);
		ImGui::TableSetupColumn("Flags", ImGuiTableColumnFlags_WidthFixed, 70.f);
		ImGui::TableSetupColumn("Description", ImGuiTableColumnFlags_WidthFixed, 380.f);
		ImGui::TableHeadersRow();

		ConVar* pCvar = nullptr;
		ConVarHandle hCvarHandle;
		hCvarHandle.Set(0);

		do
		{
			pCvar = Ifaces::cvar->GetConVar(hCvarHandle);

			hCvarHandle.Set(hCvarHandle.Get() + 1);

			if (!pCvar)
				continue;

			if (!m_nameFilter.PassFilter(pCvar->GetName()))
				continue;

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			ImGui::Text("%s", pCvar->GetName());

			ImGui::TableNextColumn();
			ImGui::Text("%s", StringifyValue(pCvar).c_str());

			ImGui::TableNextColumn();
			ImGui::Text("%s", CommandList::PrettifyFlags(static_cast<uint64_t>(pCvar->GetFlags())).c_str());

			ImGui::TableNextColumn();
			ImGui::Text("%s", pCvar->GetHelpText());


		} while (pCvar);

		ImGui::EndTable();
	}	
}

} // namespace GUI::Dumper::ConVarList