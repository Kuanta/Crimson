//
// Created by erdem on 26.12.2022.
//

#include "Material.h"

Crimson::Material::Material(Crimson::Shader *shader) {
    this->shader = shader;
}

void Crimson::Material::Draw() {
    if(shader == nullptr) return;
    shader->use();
}
