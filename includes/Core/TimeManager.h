//
// Created by erdem on 18.08.2023.
//

#ifndef CRIMSON_TIMEMANAGER_H
#define CRIMSON_TIMEMANAGER_H

#include <chrono>

namespace Crimson
{
    class TimeManager
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

            void Update() {
                auto now = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> elapsed = now - lastFrameTimePoint;
                DeltaTime = elapsed.count();

                elapsed = now - startTime;
                ElapsedTime = elapsed.count();

                lastFrameTimePoint = now;
            }

            static double GetDeltaTime(){
                return DeltaTime;
            }

            static double GetElapsedTime(){
                return ElapsedTime;
            }

    };
}
#endif //CRIMSON_TIMEMANAGER_H
