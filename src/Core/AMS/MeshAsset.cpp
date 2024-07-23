#include "Core/AMS/MeshAsset.h"

void Crimson::MeshAsset::AddSubMeshAsset(GeometryData subMeshAsset) {
    subMeshAssets.push_back(subMeshAsset);
}

void Crimson::MeshAsset::SetVertices(std::vector<Vertex> vertices, int subMeshIndex) {
    subMeshAssets[subMeshIndex].vertices = vertices;
}

void Crimson::MeshAsset::SetIndices(std::vector<unsigned int> indices, int subMeshIndex) {
    subMeshAssets[subMeshIndex].indices = indices;
    subMeshAssets[subMeshIndex].indexed = indices.size() > 0;
}

void Crimson::MeshAsset::SetMaterialId(int index, std::string id) {
    materialIds[index] = id;
}

void Crimson::MeshAsset::SetSubmeshCount(int count) {
    for(int i=0;i<count;++i)
    {
        subMeshAssets.push_back(GeometryData());
    }
}
