//
// Created by erdem on 19.08.2023.
//

#ifndef CRIMSON_MESHASSET_H
#define CRIMSON_MESHASSET_H

#include "Core/AMS/Asset.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

namespace Crimson
{
    struct Vertex {
        // position
        glm::vec3 Position;
        // normal
        glm::vec3 Normal;
        // texCoords
        glm::vec2 UVs;
        glm::vec2 UV2s;
        // Color
        glm::vec3 Color;
        //Bone IDs
        int IDs[4];
        //Bone Weights
        float Weights[4];
        // tangent
        glm::vec3 Tangent;
        // bitangent
        glm::vec3 Bitangent;
    };

    struct GeometryData
    {
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        int materialIndex = 0;
        bool hasBones = false;
        bool indexed = false;
    };

    class MeshAsset : public Asset{

    public:
        MeshAsset();
        MeshAsset(const std::string &guid, const std::string &name, const std::string &path);

        void SetVertices(std::vector<Vertex> vertices, int subMeshIndex = 0);
        void SetIndices(std::vector<unsigned int> indices, int subMeshIndex = 0);
        void SetMaterialId(int index, std::string id);

    private:
        void ReadAsset();
        void AddSubMeshAsset(GeometryData subMeshAsset);

    public:
        std::vector<GeometryData> subMeshAssets;
        std::vector<std::string> materialIds;
    };
}
#endif //CRIMSON_MESHASSET_H
