//
// Created by erdem on 26.12.2022.
//

#include "Core/ECS/Scene.h"
#include "Core/ECS/Entity.h"

Crimson::Scene::Scene() {
    Name = "DefaultScene";
    _root = new Entity();
}

Crimson::Scene::Scene(const string &name) {
    this->Name = name;
    _root = new Entity();
}


void Crimson::Scene::SetMainCamera(Crimson::Camera *camera) {
    mainCamera = camera;
}

Crimson::Camera *Crimson::Scene::GetMainCamera() {
    return mainCamera;
}

void Crimson::Scene::AddEntity(Entity *entity) {
    _root->Add(entity);
    entity->ParentScene = this;
}



void Crimson::Scene::OnSetup() {

}

void Crimson::Scene::OnRemove() {

}

void Crimson::Scene::Update(float deltaTime) {
    _root->Update(deltaTime);
}

void Crimson::Scene::Render() {
    _root->Render();
}

void Crimson::Scene::LateUpdate(float deltaTime) {
    _root->LateUpdate(deltaTime);
}

