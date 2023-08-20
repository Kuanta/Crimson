#include "ScriptingModule.h"
#include "Core/EngineManager.h"
#include "ScriptingComponent.h"
#include "Core/TimeManager.h"

bool Crimson::ScriptingModule::Initialize() {

    globalLuaState = luaL_newstate();
    luaL_openlibs(globalLuaState);

    // Load and run the EngineLoader script
    std::string scriptPath = "./EngineScripts/EngineLoader.lua";
    if(luaL_dofile(globalLuaState, scriptPath.c_str()) != LUA_OK) {
        fprintf(stderr, "Error loading script: %s\n", lua_tostring(globalLuaState, -1));
        return false;
    }

    // Ensure CrimsonEngine table exists (as before)
    lua_getglobal(globalLuaState, "CrimsonEngine");
    if (lua_isnil(globalLuaState, -1)) {
        lua_pop(globalLuaState, 1);  // Pop nil
        lua_newtable(globalLuaState); // Create a new table for CrimsonEngine
        lua_setglobal(globalLuaState, "CrimsonEngine");
    }
    return true;
}

lua_State *Crimson::ScriptingModule::GetGlobalLuaState() {
    return EngineManager::GetInstance()->GetEngineModule<ScriptingModule>()->globalLuaState;
}

void Crimson::ScriptingModule::Update() {
    EngineModule::Update();

    float elapsedTime = (float)TimeManager::GetElapsedTime();
    float deltaTime = (float)TimeManager::GetDeltaTime();

    // Send elapsedTime and deltaTime to lua within the CrimsonEngine table
    lua_getglobal(globalLuaState, "CrimsonEngine");  // get table "CrimsonEngine"

    lua_pushnumber(globalLuaState, elapsedTime);
    lua_setfield(globalLuaState, -2, "elapsedTime"); // CrimsonEngine.elapsedTime = elapsedTime

    lua_pushnumber(globalLuaState, deltaTime);
    lua_setfield(globalLuaState, -2, "deltaTime"); // CrimsonEngine.deltaTime = deltaTime

    lua_pop(globalLuaState, 1);  // pop CrimsonEngine table off the stack
}
