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

void Crimson::SceneManager::Update() {
    EngineModule::Update();
    CurrentScene->Update();
}

void Crimson::SceneManager::Render() {
    EngineModule::Render();
    CurrentScene->Render();
}

void Crimson::SceneManager::LateUpdate() {
    EngineModule::LateUpdate();
    CurrentScene->LateUpdate();
}

Crimson::Scene *Crimson::SceneManager::GetCurrentScene() {
    return CurrentScene;
}
