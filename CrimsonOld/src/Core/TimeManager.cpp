//
// Created by erdem on 18.08.2023.
//

#include <string>
#include "Core/TimeManager.h"

double Crimson::TimeManager::DeltaTime = 0.0f;
double Crimson::TimeManager::ElapsedTime = 0.0f;

bool Crimson::TimeManager::Initialize() {
    return true;
}

void Crimson::TimeManager::Update() {
    auto now = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = now - lastFrameTimePoint;
    DeltaTime = elapsed.count();

    elapsed = now - startTime;
    ElapsedTime = elapsed.count();

    lastFrameTimePoint = now;
}
