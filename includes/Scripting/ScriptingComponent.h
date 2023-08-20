//
// Created by erdem on 20.08.2023.
//

#ifndef CRIMSON_SCRIPTINGCOMPONENT_H
#define CRIMSON_SCRIPTINGCOMPONENT_H

#include <string>

#include "Core/ECS/Component.h"

extern "C"
{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
};

namespace Crimson
{
    static const char* ENTITY_KEY = "Entity";

    class Entity;
    class ScriptingComponent : public Component{
    public:

        ScriptingComponent(const std::string& filePath);
        void OnAttach() override;
        void Initialize() override;
        void Update() override;
        void Cleanup() override;
        void CallFunction(lua_State* luaState, const std::string& funcName);

    private:
        void SetEntityReference();
        void RegisterMethods(lua_State* luaState);
        void RegisterMethod(lua_State* luaState, lua_CFunction func, const std::string& luaFuncName);
        static Entity* GetEntityFromLuaState(lua_State* L);
    private:
        std::string scriptFilePath;
        lua_State *luaState;

        //Exposed methods
        static int l_GetName(lua_State* L);
        static int l_GetElapsedTime(lua_State* L);
        static int l_GetDeltaTime(lua_State* L);
        static int l_SetPosition(lua_State* L);
        static int l_SetRotation(lua_State* L);
        static int l_SetScale(lua_State* L);
    };

}


#endif //CRIMSON_SCRIPTINGCOMPONENT_H
