#include "Core/Camera.h"
#include "Core/Actor.h"
#include "Core/Transform.h"
#include "Core/ECS/Scene.h"


Crimson::Camera::Camera(float fov, float aspectRatio, float near, float far) {
    this->projection = glm::perspective(glm::radians(fov), aspectRatio, near, far);
}

glm::mat4 Crimson::Camera::getViewMatrix() {

    Transform*  transform = ((Actor*)ParentEntity)->transform;
    return glm::lookAt(transform->position, transform->GetForwardDirection(), glm::vec3(0.0f, 1.0f, 0.0f));
}

Crimson::Camera::Camera() {
    this->projection = glm::perspective(glm::radians(60.0f), 1.0f, 0.1f, 1000.0f);
}

glm::mat4 Crimson::Camera::getProjectionMatrix() {
    return projection;
}

void Crimson::Camera::OnAttach() {
    Component::OnAttach();
    if(ParentEntity->ParentScene != nullptr)
    {
        ParentEntity->ParentScene->SetMainCamera(this);
    }
}
