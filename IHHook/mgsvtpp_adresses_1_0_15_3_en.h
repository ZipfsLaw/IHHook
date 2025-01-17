#pragma once
//GENERATED: by AddressCSVToMacroHeader.lua
//using D:\GitHub\IHHook\mgsvtpp_adresses_1_0_15_3_en.csv
// NOT_FOUND - default for a lapi we want to use, and should actually have found the address in prior exes, but aren't in the current exported address list
// NO_USE - something we dont really want to use for whatever reason - TODO addt to getllocf,setallocf, actually give reason why not (dont want to mess with allocator function)
// USING_CODE - using the default lapi code implementation instead of hooking

namespace IHHook {
	std::map<std::string, int64_t> mgsvtpp_adresses_1_0_15_3_en{
		{"_mainCRTStartup", 0x14c1b9710},
		{"FoxMain", 0x142e5cd30},
		{"StrCode64", 0x14c1bd730},
		{"GetFreeRoamLangId", 0x145e60f40},
		{"UpdateFOVLerp", 0x141116800},
		{"UnkSomePrintFunction", 0x142ef2bf0},//Some info printing function that has been stubbed out
		{"l_StubbedOut", 0x14024a8e0},
		{"UnkSomePlayerUpdateFunc", 0x146900690},
		{"UnkAnotherPlayerUpdateFuncButHuge", 0x1412cf110},
		{"nullsub_2", 0x1409c8f90},
		{"lua_newstate", 0x14c1fc960},//tex could use default implementation, but may want to hook if we want to see what the engine is up to
		{"lua_close", 0x14c1fc380},
		{"lua_newthread", 0x14c1d9d90},
		{"lua_atpanic", 0x14c1d5120},
//		{"lua_gettop", USING_CODE},
		{"lua_settop", 0x14c1ebbe0},
		{"lua_pushvalue", 0x14c1e87e0},
		{"lua_remove", 0x14c1ea0c0},
		{"lua_insert", 0x14c1d8150},
		{"lua_replace", 0x14c1ea370},
		{"lua_checkstack", 0x14c1d5900},
		{"lua_xmove", 0x14c1edcd0},
		{"lua_isnumber", 0x14c1d8c90},
		{"lua_isstring", 0x14c1d9250},
		{"lua_iscfunction", 0x141a11650},
//		{"lua_isuserdata", USING_CODE},
		{"lua_type", 0x14c1ed760},
//		{"lua_typename", USING_CODE},
//		{"lua_equal", NOT_FOUND},//DEBUGNOW NOT_FOUND//tex: lua implementation goes a bit deeper than I'm happy with to use at the moment. No calls in lua distro, so may be hard to find, or have been culled by compilation
		{"lua_rawequal", 0x14c1e8d70},
		{"lua_lessthan", 0x14c1d9890},
		{"lua_tonumber", 0x14c1ecdd0},
		{"lua_tointeger", 0x14c1ec760},//MINIMAL_HOOK 
		{"lua_toboolean", 0x14c1ebe40},
		{"lua_tolstring", 0x14c1eca70},//MINIMAL_HOOK 
		{"lua_objlen", 0x14c1da960},
		{"lua_tocfunction", 0x14c1ec560},
		{"lua_touserdata", 0x14c1ed4b0},
		{"lua_tothread", 0x14c1ed3c0},
		{"lua_topointer", 0x14c1ed230},
		{"lua_pushnil", 0x14c1e7cc0},//MINIMAL_HOOK 
		{"lua_pushnumber", 0x14c1e7dd0},
		{"lua_pushinteger", 0x14c1e6ef0},//MINIMAL_HOOK 
		{"lua_pushlstring", 0x14c1e7310},
		{"lua_pushstring", 0x14c1e7ee0},//MINIMAL_HOOK 
		{"lua_pushvfstring", 0x14c1e8b10},
		{"lua_pushfstring", 0x14c1e6a70},
		{"lua_pushcclosure", 0x14c1e67b0},
		{"lua_pushboolean", 0x14c1db230},//MINIMAL_HOOK 
		{"lua_pushlightuserdata", 0x14c1e71b0},
		{"lua_pushthread", 0x14c1e86a0},
		{"lua_gettable", 0x14c1d7c10},
		{"lua_getfield", 0x14c1d7320},//MINIMAL_HOOK 
		{"lua_rawget", 0x14c1e9190},
		{"lua_rawgeti", 0x14c1e9320},//via MACRO lua_getref
		{"lua_createtable", 0x14c1d6320},//MINIMAL_HOOK 
		{"lua_newuserdata", 0x14c1d9f80},
		{"lua_getmetatable", 0x14c1d79b0},
		{"lua_getfenv", 0x14c1d7160},
		{"lua_settable", 0x14c1eb2b0},
		{"lua_setfield", 0x14c1eabb0},//MINIMAL_HOOK 
		{"lua_rawset", 0x14c1e9cf0},
		{"lua_rawseti", 0x14c1e9ff0},//MINIMAL_HOOK 
		{"lua_setmetatable", 0x14c1eb040},
		{"lua_setfenv", 0x14c1eaa00},
		{"lua_call", 0x14c1d5690},
		{"lua_pcall", 0x14c1daff0},
		{"lua_cpcall", 0x146c7dd00},
		{"lua_load", 0x14c1d99c0},
		{"lua_dump", 0x14c1d6690},
//		{"lua_yield", USING_CODE},
		{"lua_resume", 0x14c1f0d80},
//		{"lua_status", USING_CODE},//tex DEBUGNOW hmm, address range. ida finds this as sig though, but the prior functions have entries in .pdata which put them in the same range (0x14cdb)
		{"lua_gc", 0x141a11220},
		{"lua_error", 0x14c1d6c90},
		{"lua_next", 0x14c1da770},
		{"lua_concat", 0x14c1d5d50},
//		{"lua_getallocf", NO_USE},//tex don't really want to mess with allocator function anyway, DEBUGNOW no calls in lua distro, so may be hard to find, or have been culled by compilation
//		{"lua_setallocf", NO_USE},//tex don't really want to mess with allocator function anyway
//		{"lua_setlevel", NO_USE},//tex: labeled by lua as a hack to be removed in lua 5.2
		{"lua_getstack", 0x14c20fbd0},
		{"lua_getinfo", 0x14c20f650},
		{"lua_getlocal", 0x14c20f880},
		{"lua_setlocal", 0x14c20fff0},
		{"lua_getupvalue", 0x14c1d7ea0},
		{"lua_setupvalue", 0x141a12240},
		{"lua_sethook", 0x14c20fde0},
//		{"lua_gethook", USING_CODE},
//		{"lua_gethookmask", USING_CODE},
//		{"lua_gethookcount", USING_CODE},
		{"luaI_openlib", 0x14c201610},//MINIMAL_HOOK 
//		{"luaL_register", USING_CODE},
		{"luaL_getmetafield", 0x14c200d50},
		{"luaL_callmeta", 0x14c1fec20},
		{"luaL_typerror", 0x141a184c0},
		{"luaL_argerror", 0x14c1fe5f0},
		{"luaL_checklstring", 0x14c1ff790},
		{"luaL_optlstring", 0x14c201de0},
		{"luaL_checknumber", 0x14c1ffb30},
//		{"luaL_optnumber", USING_CODE},
		{"luaL_checkinteger", 0x14c1ff430},
		{"luaL_optinteger", 0x14c201a70},
		{"luaL_checkstack", 0x14c200010},
		{"luaL_checktype", 0x14c2004c0},
		{"luaL_checkany", 0x14c1ff2f0},
		{"luaL_newmetatable", 0x14c2013c0},
		{"luaL_checkudata", 0x14c200630},
		{"luaL_where", 0x14c203350},
		{"luaL_error", 0x14c2008f0},
		{"luaL_checkoption", 0x14c1ffd60},
//		{"luaL_ref", USING_CODE},//tex: Unsure on this address, see lauxlib_Creathooks CREATE_FUNCPTR(luaL_ref) for more info
//		{"luaL_unref", USING_CODE},
		{"luaL_loadfile", 0x141a17b90},
		{"luaL_loadbuffer", 0x14c200f90},
//		{"luaL_loadstring", USING_CODE},
		{"luaL_newstate", 0x14c201490},
		{"luaL_gsub", 0x141a17710},
		{"luaL_findtable", 0x14c200aa0},
//		{"luaL_buffinit", USING_CODE},
		{"luaL_prepbuffer", 0x14c202140},
		{"luaL_addlstring", 0x141a16e70},
//		{"luaL_addstring", USING_CODE},
		{"luaL_addvalue", 0x14c1fd9b0},
		{"luaL_pushresult", 0x14c202280},
		{"luaopen_base", 0x14c21d5c0},
		{"luaopen_table", 0x14c21d8d0},
		{"luaopen_io", 0x14c21da00},
		{"luaopen_os", 0x14c21e020},
		{"luaopen_string", 0x14c21e720},
		{"luaopen_math", 0x14c21e800},
		{"luaopen_debug", 0x14c21ea00},
		{"luaopen_package", 0x14c21ee20},
		{"luaL_openlibs", 0x14c1fd0c0},
	};//map mgsvtpp_adresses_1_0_15_3_en
}//namespace IHHook