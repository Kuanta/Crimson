//
// Created by erdem on 20.08.2023.
//

#ifndef CRIMSON_SCRIPTINGMODULE_H
#define CRIMSON_SCRIPTINGMODULE_H

#include "Core/Modules/EngineModule.h"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
};

namespace Crimson
{
    class ScriptingModule : EngineModule{

    public:
        bool Initialize() override;
        void Update() override;
        static lua_State* GetGlobalLuaState();

    private:
        lua_State* globalLuaState;
    };

}


#endif //CRIMSON_SCRIPTINGMODULE_H
