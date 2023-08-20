//
// Created by erdem on 26.12.2022.
//

#include "../../includes/Core/Object.h"

Crimson::Object::Object() {
    transform = new Transform();
}

Crimson::Object::~Object() {

}

void Crimson::Object::Update(float deltaTime) {
    //Update components
    for (vector<Component*>::iterator iter = this->components.begin(); iter != this->components.end(); iter++)
    {
       //(*iter)->Update(deltaTime);
    }

    //Update transform. It will also update its children
    transform->Update(deltaTime);
}

void Crimson::Object::Render() {
    for (vector<Component*>::iterator iter = this->components.begin(); iter != this->components.end(); iter++)
    {
        (*iter)->Render();
    }

}

void Crimson::Object::LateUpdate(float deltaTime) {
    //Update components
    for (vector<Component*>::iterator iter = this->components.begin(); iter != this->components.end(); iter++)
    {
       // (*iter)->LateUpdate(deltaTime);
    }

}

void Crimson::Object::FixedUpdate(float fixedDeltaTime) {
    //Update components
    for (vector<Component*>::iterator iter = this->components.begin(); iter != this->components.end(); iter++)
    {
       //(*iter)->FixedUpdate(fixedDeltaTime);
    }

}


void Crimson::Object::Cleanup() {
    for (vector<Component*>::iterator iter = this->components.begin(); iter != this->components.end(); iter++)
    {
        (*iter)->Cleanup();
    }
}

void Crimson::Object::AddComponent(Crimson::Component *component) {
    components.push_back(component);
}

void Crimson::Object::RemoveComponent(Crimson::Component *component) {
    vector<Component*>::iterator it = components.begin();
    bool found = false;
    for(it = components.begin(); it != components.end(); ++it)
    {
        if(*it == component)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        component->Cleanup();
        components.erase(it);
    }
}


