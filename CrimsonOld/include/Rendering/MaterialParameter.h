//
// Created by erdem on 19.08.2023.
//

#ifndef CRIMSON_MATERIALPARAMETER_H
#define CRIMSON_MATERIALPARAMETER_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace Crimson
{
    class MaterialParameter
    {
    public:
        enum class Type
        {
            FLOAT, VECTOR2, VECTOR3, VECTOR4, TEXTURE2D
        };
        MaterialParameter();
        explicit MaterialParameter(float floatValue);
        explicit MaterialParameter(glm::vec2 vec2Value);
        explicit MaterialParameter(glm::vec3 vec3Value);
        explicit MaterialParameter(glm::vec4 vec4Value);

    public:
        Type type;
        float floatValue;
        glm::vec2 vec2Value;
        glm::vec3 vec3Value;
        glm::vec4 vec4Value;
    };
}
#endif //CRIMSON_MATERIALPARAMETER_H
