
#include "Core/Transform.h"
#include "Core/Actor.h"

Crimson::Transform::Transform() {
    position = glm::vec3(0,0,0);
    rotation = glm::quat (1,0,0,0);
    scale = glm::vec3(1,1,1);
    requireModelUpdate = true;
}

void Crimson::Transform::Update(float deltaTime) {
    if(requireModelUpdate)
    {
        UpdateModel();
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
    model *= glm::toMat4(rotation);
    model = glm::scale(model, this->scale);
    this->localMatrix = model;
}

void Crimson::Transform::UpdateModel() {
    if(!requireModelUpdate) return;
    UpdateLocalMatrix();
    glm::mat4 model = GetLocalMatrix();
    Entity* entity = owner->ParentEntity;
    Crimson::Actor* parentActor = dynamic_cast<Crimson::Actor*>(entity);

    if(parentActor!= nullptr)
    {
        model = parentActor->transform->GetModelMatrix() * GetLocalMatrix();
    }
    SetModelMatrix(model);
    requireModelUpdate = false;

    // Update children recursively (depth-first):
    for(auto &childEntity : owner->Children.Elements) {
        if (childEntity == nullptr) continue;
        Crimson::Actor* childActor = dynamic_cast<Crimson::Actor*>(childEntity);
        if (childActor) {
            Transform* childTransform = childActor->transform;
            if(childTransform != nullptr) {
                childTransform->UpdateModel();
            }
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


