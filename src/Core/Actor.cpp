#include "Core/Actor.h"
#include "Core/Transform.h"
#include "Core/ECS/Component.h"

void Crimson::Actor::Initialize() {
    Entity::Initialize();
    transform = new Transform();
    transform->owner = this;
}

void Crimson::Actor::LateUpdate(float deltaTime) {
    Entity::LateUpdate(deltaTime);
    if(transform == nullptr) return;
    transform->UpdateModel();
}

Crimson::Actor::Actor(const string &name) : Entity(name) {
    Initialize();
}

Crimson::Actor::Actor() : Entity("Actor"){
    Initialize();
}

void Crimson::Actor::AddComponent(Crimson::Component *component) {
    Entity::AddComponent(component);
    component->transform = this->transform;
}
