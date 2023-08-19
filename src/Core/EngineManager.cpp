//
// Created by erdem on 26.12.2022.
//

#include "Core/EngineManager.h"
#include "Core/Modules/EngineModule.h"
#include "Core/Modules/RenderWindowModule.h"
#include "Core/ECS/SceneManager.h"

//
//bool Crimson::EngineManager::Initialize() {
//    renderer = new Renderer();
//    inputManager = new InputManager();
//
//    renderer->Initialize();
//    inputManager->Initialize(renderer->window->glfwWindow);
//    return true;
//}
//
//bool Crimson::EngineManager::Run() {
//
//    /*
// * Renders the window
// */
//    while(!renderer->window->ShouldClose())
//    {
//        currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        if(currentScene != nullptr)
//        {
//            currentScene->GetMainCamera()->Update(0.0f);
//            renderer->SetMainCamera(currentScene->GetMainCamera());
//            Update();
//            renderer->PreRender();
//            Render();
//            renderer->PostRender();
//            LateUpdate();
//        }
//        Render();
//
//    }
//    return true;
//}
//
//void Crimson::EngineManager::Render() {
//    if(currentScene != nullptr)
//        currentScene->Render();
//}
//
//void Crimson::EngineManager::Update() {
//    currentScene->Update(deltaTime);
//}
//
//void Crimson::EngineManager::LateUpdate() {
//    currentScene->LateUpdate(deltaTime);
//}
//
//Crimson::Scene* Crimson::EngineManager::GetCurrentScene() {
//    return currentScene;
//}
//
//void Crimson::EngineManager::SetScene(Crimson::Scene *newScene) {
//    if(currentScene != nullptr)
//    {
//        currentScene->Cleanup();
//        delete currentScene;
//    }
//    currentScene = newScene;
//}

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
    RenderWindowModule* windowModule = new RenderWindowModule();
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
