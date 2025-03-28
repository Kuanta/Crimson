#ifndef CRIMSON_TIMEMANAGER_H
#define CRIMSON_TIMEMANAGER_H

#include <chrono>
#include "Core/Modules/EngineModule.h"


extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
};


namespace Crimson
{
    class TimeManager : public EngineModule
    {
        public:
            static double DeltaTime;
            static double ElapsedTime;
        private:
            std::chrono::high_resolution_clock::time_point startTime;
            std::chrono::high_resolution_clock::time_point lastFrameTimePoint;



        public:
            TimeManager() {
                startTime = std::chrono::high_resolution_clock::now();
                lastFrameTimePoint = startTime;
            }

            bool Initialize() override;
            void Update() override;

            static double GetDeltaTime(){
                return DeltaTime;
            }

            static double GetElapsedTime(){
                return ElapsedTime;
            }

        static int Lua_GetDeltaTime(lua_State* L) {
            lua_pushnumber(L, DeltaTime);
            return 1;  // We are returning 1 value to Lua.
        }

        static int Lua_GetElapsedTime(lua_State* L) {
            lua_pushnumber(L, ElapsedTime);
            return 1;  // We are returning 1 value to Lua.
        }

    };
}
#endif //CRIMSON_TIMEMANAGER_H
