//
// Created by erdem on 18.08.2023.
//

#include "Core/ECS/SceneManager.h"
#include "Core/ECS/Scene.h"

bool Crimson::SceneManager::Initialize() {
    return true;
}

void Crimson::SceneManager::ChangeScene(Crimson::Scene *newScene) {
    if(CurrentScene != nullptr)
    {
        CurrentScene->OnRemove();
    }
    CurrentScene = newScene;
    CurrentScene->OnSetup();
}

void Crimson::SceneManager::Update(float deltaTime) {
    EngineModule::Update(deltaTime);
    CurrentScene->Update(deltaTime);
}

void Crimson::SceneManager::Render() {
    EngineModule::Render();
    CurrentScene->Render();
}

void Crimson::SceneManager::LateUpdate(float deltaTime) {
    EngineModule::LateUpdate(deltaTime);
    CurrentScene->LateUpdate(deltaTime);
}
