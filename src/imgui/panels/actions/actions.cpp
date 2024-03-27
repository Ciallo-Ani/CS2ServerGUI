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

#include "actions.h"
#include "imgui/main.h"
#include "interfaces.h"
#include <imgui.h>
#include <sdk/tier0/CCvar.h>

namespace GUI::Actions
{

static uint64_t g_iFlagsToRemove = (FCVAR_HIDDEN | FCVAR_DEVELOPMENTONLY | FCVAR_MISSING0 | FCVAR_MISSING1 | FCVAR_MISSING2 | FCVAR_MISSING3);

void Draw()
{
	if (ImGui::MenuItem("Unlock all commands"))
	{
		if (!Ifaces::cvar)
			return;

		int iUnhiddenConCommands = 0;

		CConCommand* pConCommand = nullptr;
		CConCommand* pInvalidCommand = Ifaces::cvar->GetCommand(CConCommandHandle());
		CConCommandHandle hConCommandHandle;
		hConCommandHandle.Set(0);

		do
		{
			pConCommand = Ifaces::cvar->GetCommand(hConCommandHandle);

			hConCommandHandle.Set(hConCommandHandle.Get() + 1);

			if (!pConCommand || pConCommand == pInvalidCommand || !(pConCommand->GetFlags() & g_iFlagsToRemove))
				continue;

			pConCommand->RemoveFlags(g_iFlagsToRemove);
			iUnhiddenConCommands++;
		} while (pConCommand && pConCommand != pInvalidCommand);
	}

	if (ImGui::MenuItem("Unlock all convars"))
	{
		if (!Ifaces::cvar)
			return;

		int iUnhiddenConVars = 0;

		ConVar* pCvar = nullptr;
		ConVarHandle hCvarHandle;
		hCvarHandle.Set(0);

		// Can't use FindFirst/Next here as it would skip cvars with certain flags, so just loop through the handles
		do
		{
			pCvar = Ifaces::cvar->GetConVar(hCvarHandle);
			
			hCvarHandle.Set(hCvarHandle.Get() + 1);

			if (!pCvar)
				continue;

			if (!(pCvar->m_nFlags & g_iFlagsToRemove))
				continue;

			pCvar->m_nFlags &= ~g_iFlagsToRemove;
			iUnhiddenConVars++;
		} while (pCvar);
	}
}

} // namespace GUI::PlayerList