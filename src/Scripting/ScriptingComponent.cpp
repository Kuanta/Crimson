#include "Scripting/ScriptingComponent.h"
#include "Scripting/ScriptingModule.h"
#include "Core/ECS/Entity.h"
#include "Core/TimeManager.h"
#include "Core/Actor.h"
#include "Core/Transform.h"


Crimson::ScriptingComponent::ScriptingComponent(const std::string &filePath) {
    scriptFilePath = filePath;
}

void Crimson::ScriptingComponent::Initialize() {
    Component::Initialize();
    luaState = luaL_newstate();
    luaL_openlibs(luaState);

    //Set package path
    lua_getglobal(luaState, "package");
    lua_pushstring(luaState, "./Assets/Scripts/EngineScripts/?.lua");
    lua_setfield(luaState, -2, "path");
    lua_pop(luaState, 1);  // pop 'package' table off the stack

    SetEntityReference();

    RegisterMethods(luaState);
    if(luaL_dofile(luaState, this->scriptFilePath.c_str()) != LUA_OK)
    {
        const char* errorMessage = lua_tostring(luaState, -1);
        fprintf(stderr, "Lua error: %s\n", errorMessage);
        lua_pop(luaState, 1);  // Remove the error message from the stack
    }
}

void Crimson::ScriptingComponent::RegisterMethods(lua_State *luaState) {

    RegisterMethod(luaState, l_SetPosition, "SetPosition");
    RegisterMethod(luaState, l_GetName, "GetName");
    RegisterMethod(luaState, l_GetDeltaTime, "GetDeltaTime");
    RegisterMethod(luaState, l_GetElapsedTime, "GetElapsedTime");
}

void Crimson::ScriptingComponent::Update() {
    Component::Update();

    CallFunction(luaState, "Update");
}

void Crimson::ScriptingComponent::CallFunction(lua_State *luaState, const std::string &funcName) {
    lua_getfield(luaState, -1, funcName.c_str()); // Get the function from the returned table
    // Check if it's a function
    if (!lua_isfunction(luaState, -1)) {
        fprintf(stderr, "%s is not a function or doesn't exist!\n", funcName.c_str());
        return;
    }

    if(lua_pcall(luaState, 0,0,0) != LUA_OK) {
        fprintf(stderr, "%s\n", lua_tostring(luaState, -1));
    }
}

int Crimson::ScriptingComponent::l_SetPosition(lua_State *L) {
    // Check the number of arguments passed from Lua
    int numArgs = lua_gettop(L);
    if (numArgs != 3) {
        return luaL_error(L, "SetPosition expects 3 arguments (x, y, z)");
    }

    // Extract x, y, and z arguments from the Lua stack
    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    float z = luaL_checknumber(L, 3);

    // Now you have x, y, and z values extracted from Lua
    // Use these values to set the position of the entity

    Entity* entity = GetEntityFromLuaState(L);
    if(entity == nullptr) {
        return 0;
    }
    if(Actor* actor = dynamic_cast<Actor*>(entity))
    {
        actor->transform->SetPosition(x,y,z);
    }
    return 0; // Return the number of values pushed onto the Lua stack
}

int Crimson::ScriptingComponent::l_SetRotation(lua_State *L) {
    return 0;
}

int Crimson::ScriptingComponent::l_SetScale(lua_State *L) {
    return 0;
}

void Crimson::ScriptingComponent::RegisterMethod(lua_State *luaState, lua_CFunction func, const std::string &funcName) {
    // Check if the "Crimson" table already exists
    lua_getglobal(luaState, "Crimson");
    if (lua_isnil(luaState, -1)) { // if it doesn't exist, create it
        lua_pop(luaState, 1);  // remove the nil from the stack
        lua_newtable(luaState);
        lua_setglobal(luaState, "Crimson");
    }
    lua_getglobal(luaState, "Crimson");
    lua_pushcfunction(luaState, func);  // push the function onto the stack
    lua_setfield(luaState, -2, funcName.c_str());  // set the function as a field of the "Crimson" table
    lua_pop(luaState, 1); // pop the "Crimson" table off the stack
}

Crimson::Entity *Crimson::ScriptingComponent::GetEntityFromLuaState(lua_State *L) {
    lua_pushlightuserdata(L, (void*)ENTITY_KEY);  // Push the unique key
    lua_gettable(L, LUA_REGISTRYINDEX);           // Get the value associated with that key from the registry
    Entity* entity = (Entity*) lua_touserdata(L, -1);  // Convert the userdata back to an Entity pointer
    lua_pop(L, 1);  // Pop the userdata off the stack
    return entity;
}

void Crimson::ScriptingComponent::SetEntityReference() {
    lua_pushlightuserdata(luaState, (void*)ENTITY_KEY);  // Push a unique key
    lua_pushlightuserdata(luaState, ParentEntity);             // Push the entity pointer
    lua_settable(luaState, LUA_REGISTRYINDEX);           // Set it in the registry
}

int Crimson::ScriptingComponent::l_GetName(lua_State *L) {
    Entity* entity = GetEntityFromLuaState(L);
    if(entity == nullptr) {
        lua_pushstring(L, "Null Entity");
        return luaL_error(L, "Couldn't get entity.");
    }
    std::string name = entity->Name;
    lua_pushstring(L, name.c_str());
    return 1;
}

int Crimson::ScriptingComponent::l_GetElapsedTime(lua_State *L) {
    lua_pushnumber(L, TimeManager::GetElapsedTime());
    return 1;
}

int Crimson::ScriptingComponent::l_GetDeltaTime(lua_State *L) {
    lua_pushnumber(L, TimeManager::GetDeltaTime());
    return 1;
}

void Crimson::ScriptingComponent::Cleanup() {
    Component::Cleanup();
    lua_close(luaState);
}

void Crimson::ScriptingComponent::OnAttach() {
    Component::OnAttach();
    Initialize();
}

