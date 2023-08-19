#include <iostream>
#include "Core/EngineManager.h"
#include "Core/ECS/SceneManager.h"
#include "Core/ECS/Scene.h"
#include "Core/ECS/Entity.h"
#include "../Testing/NotifierComponent.h"

using namespace Crimson;

int main() {

    Crimson::EngineManager em;
    std::cout<<"Welcome To Gray V2"<<std::endl;
    //Initialize Engine
    if(!em.InitializeEngine()) return 1;

    //Load Asset
    em.AssetManager.LoadAsset("SimpleShader");

    SceneManager* sceneMan = em.GetEngineModule<SceneManager>();
    Scene* defaultScene = new Scene("Sample Scene");
    sceneMan->ChangeScene(defaultScene);

    //Fill the scene
    Entity* dummyEntity = new Entity("Dummy_1");
    NotifierComponent* notComp = new NotifierComponent();
    dummyEntity->AddComponent(notComp);
    defaultScene->AddEntity(dummyEntity);
    em.StartEngine();

    return 0;
}
