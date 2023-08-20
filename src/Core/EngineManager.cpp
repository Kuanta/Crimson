//
// Created by erdem on 26.12.2022.
//

#include "Core/EngineManager.h"
#include "Core/Modules/EngineModule.h"
#include "Core/Modules/RenderModule.h"
#include "Core/ECS/SceneManager.h"
#include "Core/TimeManager.h"

void Crimson::EngineManager::RegisterModule(Crimson::EngineModule *module) {
    modulesMap[std::type_index(typeid(*module))] = module;
    module->ParentManager = this;
}

void Crimson::EngineManager::StartEngine() {


    while(!_engineShouldStop)
    {
        //Update
        for (auto& pair : modulesMap)
        {
            EngineModule* module = pair.second;
            if (module)
            {
                module->Update();
            }
        }

        Render();

        //LateUpdate
        for (auto& pair : modulesMap)
        {
            EngineModule* module = pair.second;
            if (module)
            {
                module->LateUpdate();
            }
        }
    }
}

void Crimson::EngineManager::Update() {
    for (auto& pair : modulesMap)
    {
        EngineModule* module = pair.second;
        if (module)
        {
            module->Update();
        }
    }
}

void Crimson::EngineManager::Render() {
    for (auto& pair : modulesMap)
    {
        EngineModule* module = pair.second;
        if (module)
        {
            module->PreRender();
        }
    }
    for (auto& pair : modulesMap)
    {
        EngineModule* module = pair.second;
        if (module)
        {
            module->Render();
        }
    }
    for (auto& pair : modulesMap)
    {
        EngineModule* module = pair.second;
        if (module)
        {
            module->PostRender();
        }
    }
}

void Crimson::EngineManager::LateUpdate() {
    for (auto& pair : modulesMap)
    {
        EngineModule* module = pair.second;
        if (module)
        {
            module->LateUpdate();
        }
    }
}

void Crimson::EngineManager::StopEngine() {
    _engineShouldStop = true;

    //todo: Cleanup modules
}

bool Crimson::EngineManager::InitializeEngine() {

    //Register modules
    RenderModule* windowModule = new RenderModule();
    SceneManager* sceneManager = new SceneManager();
    TimeManager* timeManager = new TimeManager();

    RegisterModule(windowModule);
    RegisterModule(sceneManager);
    RegisterModule(timeManager);


    for (auto& pair : modulesMap)
    {
        EngineModule* module = pair.second;
        if (module)
        {
            if(!module->Initialize()) return false;
        }
    }

    AssetManager.Initialize(); //Asset manager first
    MaterialLibrary.Initialize();
    return  true;
}

Crimson::EngineManager* Crimson::EngineManager::instance = nullptr;
