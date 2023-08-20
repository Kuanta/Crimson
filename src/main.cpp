#include <iostream>
#include "Core/EngineManager.h"
#include "Core/ECS/SceneManager.h"
#include "Core/ECS/Scene.h"
#include "Rendering/MeshRenderer.h"
#include "Rendering/MeshInstance.h"
#include "Core/Actor.h"
#include "Core/Camera.h"
#include "Scripting/ScriptingComponent.h"

using namespace Crimson;

std::shared_ptr<MeshAsset> CreatePlaneMeshAsset(int width, int height, float uvScale = 1.0f);

int main() {

    Crimson::EngineManager* em = EngineManager::GetInstance();
    std::cout<<"Welcome To Crimson!"<<std::endl;

    //Initialize Engine
    if(!em->InitializeEngine()) return 1;

    SceneManager* sceneMan = em->GetEngineModule<SceneManager>();
    Scene* defaultScene = new Scene("Sample Scene");
    sceneMan->ChangeScene(defaultScene);

    //Fill the scene
    //1) Camera
    Actor* cameraActor = new Actor("Camera");
    defaultScene->AddEntity(cameraActor); //Add to the scene before adding any component

    cameraActor->AddComponent(new Camera());
    cameraActor->transform->SetPosition(glm::vec3(0,0,5));
    cameraActor->transform->SetForwardDirection(glm::vec3(0,0,-1));

    //2) Actor
    Actor* dummyEntity = new Actor("Dummy Actor");
    dummyEntity->transform->SetRotation(glm::vec3(0,0,45.0f));
    MeshRenderer* meshRenderer = new MeshRenderer();
    MeshInstance* mesh = new MeshInstance();
    ScriptingComponent* sc = new ScriptingComponent("./Assets/Scripts/EngineScripts/name_displayer.lua");

    std::shared_ptr<Crimson::MeshAsset> meshAsset = CreatePlaneMeshAsset(1, 1, 1.0f);

    mesh->SetMeshAsset(meshAsset);
    meshRenderer->SetMesh(mesh);
    defaultScene->AddEntity(dummyEntity);
    dummyEntity->AddComponent(meshRenderer);
    dummyEntity->AddComponent(sc);


    em->StartEngine();

    return 0;
}

std::shared_ptr<MeshAsset> CreatePlaneMeshAsset(int width, int height, float uvScale)
{
    std::shared_ptr<MeshAsset> meshAsset = std::make_shared<MeshAsset>();
    float vertexPoints[] = {
            -0.5f * width, -0.5f * height, 0,
            0.5f * width, -0.5f * height, 0,
            -0.5f * width, 0.5f * height, 0,
            0.5f * width, 0.5f * height, 0
    };
    float uvs[] = {
            0.0f, 0.0f,0.0f,
            1.0f*uvScale, 0.0f,0.0f,
            0.0f, 1.0f * uvScale,0.0f,
            1.0f*uvScale, 1.0f * uvScale,0.0f
    };
    float normals[] = {
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f
    };
    float tangents[] =
            {
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f
            };
    std::vector<unsigned int> indices = {
            0, 1, 2, 1, 3, 2
    };

    int vertexCount = 12;
    std::vector<Vertex> vertices;

    for (int i = 0; i < vertexCount - 2; i += 3) {
        Vertex vert;
        vert.Position = glm::vec3(vertexPoints[i], vertexPoints[i + 1], vertexPoints[i + 2]);
        vert.UVs = glm::vec2(uvs[i], uvs[i + 1]);
        vert.Normal = glm::vec3(normals[i], normals[i + 1], normals[i + 2]);
        vert.Tangent = glm::vec3(tangents[i], tangents[i + 1], tangents[i + 2]);
        vertices.push_back(vert);
    }
    meshAsset->SetVertices(vertices);
    meshAsset->SetIndices(indices);
    return meshAsset;
}