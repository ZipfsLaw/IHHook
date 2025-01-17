#pragma once

#include "MinHook.h"
#include "MemoryUtils.h"
#include <map>

#include "Hooking.Patterns/Hooking.Patterns.h"//DEBUGNOW

namespace IHHook {
	extern std::map<std::string, int64_t> addressSet;
}

//DEBUGNOW put this somewhere or CULL
	//DEBUGNOW signatures are more robust to game updates/different game versions than straight addresses, but take a long time to search
	//since IHHook is started on it's own thread game initialisation will continue, and IHHook wont be ready in time to start up IH properly.
	//an alternative would be to do a hook to an early execution point of the game and init  ihhook there,
	//but given the low rate of updates of the game it's better to stick with direct addresses, but have signatures documented as a backup


//tex macros to declare the various accoutrement required for MH_Hook and straight hooks

// Function addresses are from IDA/Ghidra, which uses the ImageBase field in the exe as the base address (usually 0x140000000)
// the real base address changes every time the game is run though, so we have to remove that base address and add the real one
// so it's rebased when its set up (see GET_REBASED_ADDR for the simple rebasing math)

//Signatures currently grabbed using GH SigMaker
//https://guidedhacking.com/resources/guided-hacking-x64-cheat-engine-sigmaker-plugin-ce-7-2.319/
//DEBUGNOW only need one type sig&mask or pattern, but have yet to decide on which to use (sigmaker grabs both so there's no real issue on generating
//though I prefer pattern for easier manual comparing without having to jump back and forth between sig and mask, seems all the sigmatching funcs I have currently gathered so far are sig&mask

//DEBUGNOW update this
//also document isTargetExe

//for all hooks need:
//FUNCPTRDEF
//FUNC_DECL_ADDR

//then in runtime:
//just want to use original function
//CREATE_FUNCPTR

//or want to modify the function
//GET_REBASED_ADDR, or define name#Addr to the runtime address of the function gained from some other method
//CREATE_HOOK -- DEBUGNOW was CREATEDETOUR
//ENABLE_HOOK

//NOTE: You can just CREATE_FUNCPTR as a matter of course
//and CREATE_HOOK/ENABLE_HOOK after if you want a detour instead

#define STRINGIFY(x) #x
#define TOKENPASTE(x, y) STRINGIFY(x ## y)



//typedef for the function pointer, 
//and an extern function pointer of the type
//so you can include a header with the hookfunc in other files and use the function
#define FUNCPTRDEF(ret, name, ...)\
typedef ret ( __fastcall name##Func ) (__VA_ARGS__);\
extern name##Func* name;\
extern intptr_t* name##BaseAddr;\
extern intptr_t* name##Addr;\
extern const char* name##Sig;\
extern const char* name##Mask;\
extern const char* name##Pattern;
//Example use:
//FUNCPTRDEF(lua_newstate, 0x14cdd7ab0, LuaState*, lua_Alloc f, void *ud);
//Expands to:
//typedef lua_State* (__fastcall *lua_newstateFunc)(lua_Alloc f, void *ud);
//extern lua_newstateFunc lua_newstate;
//extern intptr_t* lua_newstateBaseAddr;
//extern intptr_t* lua_newstateAddr;
//extern const char* lua_newstateSig;
//extern const char * lua_newstateMask;
//extern const char * lua_newstatePattern;

//Define signature and mask
#define FUNC_DECL_SIG(name, sig, mask)\
const char * name##Sig = sig;\
const char * name##Mask = mask;
//Example use:
//FUNC_DECL_SIG(lua_newstate, 
//FUNC_DECL_SIG(lua_newstate,
//	"\x4C\x8B\x00\x49\x89\x00\x00\x55\x56\x57\x41\x00\x41",
//	"xx?xx??xxxx?x")
//Expands to:
//const char* lua_newstateSig = "\x4C\x8B\x00\x49\x89\x00\x00\x55\x56\x57\x41\x00\x41";
//const char * lua_newstateMask = "xx?xx??xxxx?x";

//Define pattern
#define FUNC_DECL_PATTERN(name, pattern)\
const char * name##Pattern = pattern;
//Example use:
//FUNC_DECL_PATTERN(lua_newstate, "4C 8B ? 49 89 ? ? 55 56 57 41 ? 41")
//Expands to:
//const char * lua_newstate = "4C 8B ? 49 89 ? ? 55 56 57 41 ? 41";

//base address of func, and actually declare the function pointer -- can be in header or code (as long as later code using it can see its declaration)
#define FUNC_DECL_ADDR(name)\
name##Func* name;\
intptr_t* name##Addr;
//Example use:
//FUNC_DECL_ADDR(lua_newstate);
//Expands to:
//lua_newstateFunc lua_newstate;
//lua_newstateFunc lua_newstateBaseAddr;

//DEBUGNOW rename CREATE addrs (sig as well) GET_<>_ADDR
//Rebases an address an puts it in var for CREATE_HOOK macro
#define GET_REBASED_ADDR(name)\
name##Addr = (intptr_t*)((addressSet[#name] - BaseAddr) + RealBaseAddr);
//OLD name##Addr = (intptr_t*)((name##BaseAddr - BaseAddr) + RealBaseAddr);
//Example use:
//GET_REBASED_ADDR(lua_newstate);
//Expands to:
//lua_newstateAddr = (intptr_t*)((addressSet["lua_newstate"] - BaseAddr) + RealBaseAddr);

//ASSUMPTION name##Addr defined, FUNC_DECL_SIG declared
//sigscans for an address an puts it in var for CREATE_HOOK macro
#define GET_SIG_ADDR(name)\
name##Addr = (intptr_t*)MemoryUtils::sigscan(#name, name##Sig, name##Mask);
//ALT name##Addr = (intptr_t*)MemoryUtils::PatternScan(#name, name##Pattern);
//ALT name##Addr = (intptr_t*)MemoryUtils::ScanModIn(name##Sig, name##Mask, "mgsvtpp.exe");//DEBUG exeName?
//Example use:
//GET_SIG_ADDR(lua_newstate);
//Expands to:
//lua_newstateAddr = (intptr_t*)MemoryUtils::sigscan("lua_newstate", lua_newstateSig, lua_newstateMask);

//just want to use original function
//sets the pointer to the rebased address so the function pointer is usable
#define CREATE_FUNCPTR(name)\
name = (name##Func*)name##Addr;
//Example use:
//CREATE_FUNCPTR(lua_newstate);
//Expands to:
//lua_newstate = (lua_newstateFunc*)lua_newstateFuncAddr;

//detour and trampoline via MH_CreateHook
//original function is at the <name> function ptr (just like createptr)
//while the hook/detour is at <name>Hook function pointer.
//ASSUMPTION must have a name##Addr of the runtime location of the function, either via GET_REBASED_ADDR or some other means (like a sig scan or other method)
#define CREATE_HOOK(name)\
MH_STATUS name##CreateStatus = MH_CreateHook((LPVOID*)name##Addr, name##Hook, (LPVOID*)&name);\
if (name##CreateStatus != MH_OK) {\
	spdlog::error("MH_CreateHook failed for {} with code {}", #name, name##CreateStatus);\
} else {\
	spdlog::debug("MH_CreateHook MH_OK for {}", #name);\
}
//Example use:
//CREATE_HOOK(lua_newstate);
//Expands to:
//MH_STATUS lua_newstateCreateStatus = MH_CreateHook(lua_newstateAddr, lua_newstateHook, (LPVOID*)&lua_newstate);
//if (lua_newstateCreateStatus != MH_OK) {
//	spdlog::error("MH_CreateHook failed for {} with code {}", "lua_newstate", lua_newstateCreateStatus);\
//}

//ASSUMPTION name##Addr of runtime memory address has been defined
#define ENABLEHOOK(name)\
MH_STATUS name##EnableStatus = MH_EnableHook((LPVOID*)name##Addr);\
if (name##EnableStatus != MH_OK) {\
	spdlog::error("MH_EnableHook failed for {} with code {}", #name, name##EnableStatus);\
} else {\
	spdlog::debug("MH_EnableHook MH_OK for {}", #name);\
}
//Example use:
//ENABLEHOOK(lua_newstate);
//Expands to:
//MH_STATUS lua_newstateEnableStatus = MH_EnableHook(lua_newstateAddr);
//if (lua_newstateEnableStatus != MH_OK) {
//	spdlog::error("MH_EnableHook failed for {} with code {}", "lua_newstate", lua_newstateEnableStatus);\
//}

//ASSUMES CREATEDETOUR has defined name##Addr
#define DISABLEHOOK(name)\
MH_STATUS name##DisableStatus = MH_DisableHook((LPVOID*)name##Addr);\
if (name##DisableStatus != MH_OK) {\
	spdlog::error("MH_DisableHook failed for {} with code {}", #name, name##DisableStatus);\
} else {\
	spdlog::debug("MH_DisableHook MH_OK for {}", #name);\
}
//Example use:
//ENABLEHOOK(lua_newstate);
//Expands to:
//MH_STATUS lua_newstateDisableStatus = MH_DisableHook(lua_newstateAddr);
//if (DisableStatus != MH_OK) {
//	spdlog::error("MH_DisableHook failed for {} with code {}", "lua_newstate", lua_newstateDisableStatus);\
//}

