//
// Created by erdem on 26.12.2022.
//

#include "Rendering/MeshRenderer.h"
#include "Rendering/MeshInstance.h"
#include "Core/Actor.h"
#include "Core/Transform.h"

void Crimson::MeshRenderer::Render() {
    if(mesh == nullptr) return;
    Transform* parentTransform = ((Actor*)ParentEntity)->transform;
    if(parentTransform == nullptr) return;
    glm::mat4 modelMatrix = ((Actor*)ParentEntity)->transform->GetModelMatrix();
    mesh->Render(modelMatrix);
 }

void Crimson::MeshRenderer::SetMesh(Crimson::MeshInstance *mesh) {
    this->mesh = mesh;
}
