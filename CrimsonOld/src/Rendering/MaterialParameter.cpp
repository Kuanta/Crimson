#include "Rendering/MaterialParameter.h"

namespace Crimson
{

    MaterialParameter::MaterialParameter(float floatValue) : type(Type::FLOAT){
        floatValue = floatValue;
    }

    MaterialParameter::MaterialParameter(glm::vec2 vec2Value) : type(Type::VECTOR2){
        this->vec2Value = vec2Value;
    }

    MaterialParameter::MaterialParameter() : type(Type::FLOAT){
        floatValue = 0.0f;
    }

    MaterialParameter::MaterialParameter(glm::vec3 vec3Value) : type(Type::VECTOR3){
        vec3Value = vec3Value;
    }

    MaterialParameter::MaterialParameter(glm::vec4 vec4Value) : type(Type::VECTOR4) {
        vec4Value = vec4Value;
    }


}