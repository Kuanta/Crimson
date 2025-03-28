//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_MATERIAL_H
#define CRIMSON_MATERIAL_H


#include <unordered_map>
#include "Rendering/Shader.h"
#include "Rendering/MaterialParameter.h"

namespace Crimson
{
    class Material {
    public:
        Material(){}
        Shader* shader;
        void AddParameter(const std::string& parameterName, MaterialParameter materialParameter);
        Material(Shader* shader);
        void Render();

    public:
        std::unordered_map<std::string, MaterialParameter> parameters;
    };
}



#endif //CRIMSON_MATERIAL_H
