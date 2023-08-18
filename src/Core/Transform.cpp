//
// Created by erdem on 26.12.2022.
//

#include "../../includes/Core/Transform.h"
#include "../../includes/Core/Object.h"

Crimson::Transform::Transform() {
    position = glm::vec3(0,0,0);
    rotation = glm::quat (0,0,0,1);
    scale = glm::vec3(1,1,1);
    parent = nullptr;
}

void Crimson::Transform::Update(float deltaTime) {
    if(requireModelUpdate)
    {
        UpdateModel();
    }

    for (vector<Transform *>::iterator it = this->children.Elements.begin(); it != this->children.Elements.end(); it++)
    {
        if ((*it) != nullptr)
        {
            (*it)->ParentObject->Update(deltaTime);
        }
    }
}

void Crimson::Transform::LateUpdate(float deltaTime) {
    for (vector<Transform *>::iterator it = this->children.Elements.begin(); it != this->children.Elements.end(); it++)
    {
        if ((*it) != nullptr)
        {
            (*it)->ParentObject->LateUpdate(deltaTime);
        }
    }
}

void Crimson::Transform::FixedUpdate(float fixedDeltaTime) {
    for (vector<Transform *>::iterator it = this->children.Elements.begin(); it != this->children.Elements.end(); it++)
    {
        if ((*it) != nullptr)
        {
            (*it)->ParentObject->FixedUpdate(fixedDeltaTime);
        }
    }
}


void Crimson::Transform::OnRender() {
    for (vector<Transform *>::iterator it = this->children.Elements.begin(); it != this->children.Elements.end(); it++)
    {
        if ((*it) != nullptr)
        {
            (*it)->ParentObject->Render();
        }
    }
}

void Crimson::Transform::SetPosition(glm::vec3 position) {
    this->position = position;
    requireModelUpdate = true;
}

void Crimson::Transform::SetRotation(glm::quat rotation) {
    this->rotation = rotation;
    requireModelUpdate = true;
}

void Crimson::Transform::SetScale(glm::vec3 scale) {
    this->scale = scale;
    requireModelUpdate = true;
}

void Crimson::Transform::SetRotation(glm::vec3 eulerAngles) {
    this->rotation = glm::quat(eulerAngles);
    requireModelUpdate = true;
}

void Crimson::Transform::UpdateLocalMatrix() {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, this->position);
    glm::vec3 eulerAngles = glm::eulerAngles(this->rotation); //returns degrees
    model = glm::rotate(model, glm::radians(this->rotation.y), glm::vec3(0, 1, 0)); //Yaw
    model = glm::rotate(model, glm::radians(this->rotation.x), glm::vec3(1, 0, 0)); //Pitch
    model = glm::rotate(model, glm::radians(this->rotation.z), glm::vec3(0, 0, 1)); //Roll
    model = glm::scale(model, this->scale);
    this->localMatrix = model;

    //Children also need model update
    for (vector<Transform *>::iterator it = this->children.Elements.begin(); it != this->children.Elements.end(); it++)
    {
        if ((*it) != nullptr)
        {
            (*it)->requireModelUpdate = true;
        }
    }
}

void Crimson::Transform::UpdateModel() {
    glm::mat4 model = glm::mat4(1.0f);
    Transform* parent = this->parent;
    while(parent != nullptr)
    {
        model *= parent->GetLocalMatrix();
        parent = parent->parent;
    }
    model *= this->localMatrix;
    this->modelMatrix = model;
    UpdateChildren(model);
    requireModelUpdate = false;
}

void Crimson::Transform::UpdateChildren(glm::mat4 parentModelMatrix) {
    for (auto & Element : this->children.Elements)
    {
        if (Element != nullptr)
        {
            glm::mat4 childModel = parentModelMatrix * Element-> GetLocalMatrix();
            Element->SetModelMatrix(childModel);
            Element->UpdateChildren(childModel);
        }
    }
}

void Crimson::Transform::Cleanup() {
    for (auto & Element : this->children.Elements)
    {
        if (Element != nullptr)
        {
            Element->ParentObject->Cleanup();
        }
    }
}

glm::mat4 Crimson::Transform::GetLocalMatrix() {
    return this->localMatrix;
}

glm::mat4 Crimson::Transform::GetModelMatrix() {
    return modelMatrix;
}

void Crimson::Transform::SetModelMatrix(glm::mat4 modelMatrix) {
    this->modelMatrix = modelMatrix;
}

void Crimson::Transform::SetForwardDirection(glm::vec3 forward) {
    glm::vec3 zVec = glm::vec3(0,0,1);
    glm::vec3 up = glm::vec3(0,1,0);
    glm::vec3 right = glm::vec3(1,0,0);
    glm::vec3 horizontal = forward;
    horizontal.y = 0;
    horizontal = glm::normalize(horizontal);

    glm::vec3 vertical = forward;
    vertical.x = 0;
    vertical = glm::normalize(vertical);

    float yaw = glm::orientedAngle(zVec, horizontal, up);
    float pitch = glm::orientedAngle(zVec, vertical, right);
    float roll = 0.0f;
    glm::vec3 eulerAngles(pitch, yaw, roll);
    rotation = glm::quat(eulerAngles);
}

glm::vec3 Crimson::Transform::GetForwardDirection() {

     return this->rotation * glm::vec3(0,0,1);
}

glm::vec3 Crimson::Transform::GetRightDirection(glm::vec3 upVector) {
    return glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), GetForwardDirection()));
}


