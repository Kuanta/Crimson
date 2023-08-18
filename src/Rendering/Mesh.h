//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_MESH_H
#define CRIMSON_MESH_H

#include "Core/ECS/Component.h"
#include "Geometry.h"
#include "Material.h"

namespace Crimson
{
    class Mesh : public Component{
    public:
        Geometry* geometry;
        Material* material;

        Mesh(Geometry* geometry, Material* material);
        void Update(float deltaTime) override;
        void Render() override;

    };
}



#endif //CRIMSON_MESH_H
