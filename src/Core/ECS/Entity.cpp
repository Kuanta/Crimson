#include "Core/ECS/Entity.h"
#include "Core/ECS/Component.h"

void Crimson::Entity::Add(Crimson::Entity *entity) {
    int sceneId = Children.AddElement(entity);
    entity->SceneId = sceneId;
}

void Crimson::Entity::Remove(int sceneId) {
    Children.RemoveElement(sceneId);

}

void Crimson::Entity::Remove(Crimson::Entity *entity) {
    Children.RemoveElement(entity->SceneId);
}

void Crimson::Entity::Destroy() {

}

void Crimson::Entity::Update(float deltaTime) {
    //Components
    for (auto & component : Components)
    {
        if (component == nullptr) continue;
        component->Update(deltaTime);
    }

    //Children
    for (auto & Element : Children.Elements)
    {
        if (Element == nullptr) continue;
        Element->Update(deltaTime);
    }
}

void Crimson::Entity::Render() {
    //Components
    for (auto & component : Components)
    {
        if (component == nullptr) continue;
        component->Render();
    }

    for (auto & Element : Children.Elements)
    {
        if (Element == nullptr) continue;
        Element->Render();
    }
}

void Crimson::Entity::LateUpdate(float deltaTime) {
    //Components
    for (auto & it : Components)
    {
        if (it == nullptr) continue;
        it->LateUpdate(deltaTime);
    }

    //Children
    for (auto & Element : Children.Elements)
    {
        if (Element == nullptr) continue;
        Element->LateUpdate(deltaTime);
    }
}

Crimson::Entity::Entity(const string &name) {
    this->Name = name;
}

void Crimson::Entity::AddComponent(Crimson::Component *component) {
    Components.push_back(component);
    component->ParentEntity = this;
}

