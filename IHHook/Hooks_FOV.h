#pragma once

#include "lua/lua.h"

namespace IHHook {
	namespace Hooks_FOV {
		void CreateHooks(size_t RealBaseAddr);

		int l_SetCamHook(lua_State* L);
		int l_UpdateCamHook(lua_State* L);
	}//namespace Hooks_FOV
}//namespace IHHook