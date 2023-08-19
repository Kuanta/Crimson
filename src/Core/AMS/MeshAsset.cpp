#include "Core/AMS/MeshAsset.h"

void Crimson::MeshAsset::AddSubMeshAsset(GeometryData subMeshAsset) {
    subMeshAssets.push_back(subMeshAsset);
}

Crimson::MeshAsset::MeshAsset(const std::string &guid, const std::string &name, const std::string &path) :
    Asset(AssetType::Mesh, guid, name, path){

    ReadAsset();
}

void Crimson::MeshAsset::ReadAsset() {

    //todo: Read asset here once it is implemented
}

Crimson::MeshAsset::MeshAsset() : Asset(AssetType::Mesh, "", "", "") {
    //Add at least a single submesh
    subMeshAssets.push_back(GeometryData());
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
