//
// Created by erdem on 19.08.2023.
//

#ifndef CRIMSON_MESHINSTANCE_H
#define CRIMSON_MESHINSTANCE_H

#include <string>
#include <vector>
#include <memory>
#include <glm/detail/type_mat4x4.hpp>

namespace Crimson
{
    class SubMesh;
    class Material;
    class MeshAsset;

    class MeshInstance {

    public:
        MeshInstance();
        void SetMeshAsset(std::shared_ptr<MeshAsset> meshAsset);
        void Render(glm::mat4 modelMatrix);

    public:
        std::string guid;
        MeshAsset* meshAsset;

    private:
        std::vector<SubMesh*> submeshes;
        std::vector<Material*> materials;
    };

}


#endif //CRIMSON_MESHINSTANCE_H
