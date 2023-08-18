//
// Created by erdem on 26.12.2022.
//

#include "Camera.h"

Crimson::Camera::Camera(float fov, float aspectRatio, float near, float far) {
    this->projection = glm::perspective(glm::radians(fov), aspectRatio, near, far);
}

glm::mat4 Crimson::Camera::getViewMatrix() {
    return glm::lookAt(this->transform->position, transform->GetForwardDirection(), glm::vec3(0.0f, 1.0f, 0.0f));
}

Crimson::Camera::Camera() : Object(){
    this->projection = glm::perspective(glm::radians(60.0f), 1.0f, 0.1f, 100.0f);
}

glm::mat4 Crimson::Camera::getProjectionMatrix() {
    return projection;
}
