//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_MATERIAL_H
#define CRIMSON_MATERIAL_H

#include "Rendering/Shader.h"

namespace Crimson
{
    class Material {
    public:
        Shader* shader;

        Material(Shader* shader);
        void Draw();

    };
}



#endif //CRIMSON_MATERIAL_H
