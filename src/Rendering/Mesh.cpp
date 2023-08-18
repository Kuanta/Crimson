//
// Created by erdem on 26.12.2022.
//

#include "Mesh.h"

Crimson::Mesh::Mesh(Crimson::Geometry *geometry, Crimson::Material *material) {
    this->geometry = geometry;
    this->material = material;
}


void Crimson::Mesh::Update(float deltaTime) {

}

void Crimson::Mesh::Render() {
//    if(transform == nullptr) return;
//    material->shader->use();
//    material->shader->setMat4("model", transform->GetModelMatrix());
//    material->Draw();
//    geometry->Draw(material->shader);
 }
