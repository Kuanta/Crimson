//
// Created by erdem on 26.12.2022.
//

#include "Rendering/Material.h"

Crimson::Material::Material(Crimson::Shader *shader) {
    this->shader = shader;
}

void Crimson::Material::Render() {
    if(shader == nullptr) return;
    shader->use();

    for (const auto& paramPair : parameters) {
        const std::string& name = paramPair.first;
        const MaterialParameter& param = paramPair.second;
        switch (param.type) {
            case MaterialParameter::Type::FLOAT:
                shader->setFloat(name, param.floatValue);
                break;
            case MaterialParameter::Type::VECTOR2:
                shader->setVec2(name, param.vec2Value);
                break;
            case MaterialParameter::Type::VECTOR3:
                shader->setVec3(name, param.vec3Value);
                break;
            case MaterialParameter::Type::VECTOR4:
                shader->setVec4(name, param.vec4Value);
                break;
        }
    }
}

void Crimson::Material::AddParameter(const std::string &parameterName, Crimson::MaterialParameter materialParameter) {
    parameters[parameterName] = materialParameter;
}

