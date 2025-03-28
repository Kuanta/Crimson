//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_MESHRENDERER_H
#define CRIMSON_MESHRENDERER_H

#include "Core/ECS/Component.h"
#include "Rendering/SubMesh.h"
#include "Rendering/Material.h"

namespace Crimson
{
    class MeshInstance;
    class MeshRenderer : public Component{
    public:

        void SetMesh(MeshInstance* mesh);
        void Render() override;

    public:
        MeshInstance* mesh;
    };
}

#endif //CRIMSON_MESHRENDERER_H
