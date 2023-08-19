//
// Created by erdem on 26.12.2022.
//

#include "Core/EngineManager.h"
#include "Core/Modules/EngineModule.h"
#include "Core/Modules/RenderModule.h"
#include "Core/ECS/SceneManager.h"

void Crimson::EngineManager::RegisterModule(Crimson::EngineModule *module) {
    modulesMap[std::type_index(typeid(*module))] = module;
    module->ParentManager = this;
}

void Crimson::EngineManager::StartEngine() {


    while(!_engineShouldStop)
    {
        //Update
        this->TimeManager.Update();
        float deltaTime = 0.5f;
        for (auto& pair : modulesMap)
        {
            EngineModule* module = pair.second;
            if (module)
            {
                module->Update(deltaTime);
            }
        }

        //Render
        for (auto& pair : modulesMap)
        {
            EngineModule* module = pair.second;
            if (module)
            {
                module->Render();
            }
        }

        //LateUpdate
        for (auto& pair : modulesMap)
        {
            EngineModule* module = pair.second;
            if (module)
            {
                module->LateUpdate(deltaTime);
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
            module->Update(0.0f);
        }
    }
}

void Crimson::EngineManager::Render() {
    for (auto& pair : modulesMap)
    {
        EngineModule* module = pair.second;
        if (module)
        {
            module->Render();
        }
    }
}

void Crimson::EngineManager::LateUpdate() {
    for (auto& pair : modulesMap)
    {
        EngineModule* module = pair.second;
        if (module)
        {
            module->LateUpdate(1.0f);
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
    AssetManager.Initialize();

    RegisterModule(windowModule);
    RegisterModule(sceneManager);

    for (auto& pair : modulesMap)
    {
        EngineModule* module = pair.second;
        if (module)
        {
            if(!module->Initialize()) return false;
        }
    }
    return  true;
}
