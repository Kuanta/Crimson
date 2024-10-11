//
// Created by erdem on 26.12.2022.
//

#include "Rendering/SubMesh.h"
#include "Core/AMS/MeshAsset.h"

Crimson::SubMesh::SubMesh(Crimson::GeometryData* subMeshAsset) {
    SetGeometryData(subMeshAsset);
}

void Crimson::SubMesh::InitBuffers() {
// create buffers/arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    // load data into vertex buffers
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, _subMeshAsset->vertices.size() * sizeof(Vertex), &_subMeshAsset->vertices[0], GL_STATIC_DRAW);

    if (!_subMeshAsset->indices.empty())
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _subMeshAsset->indices.size() * sizeof(unsigned int), &_subMeshAsset->indices[0], GL_STATIC_DRAW);
    }

    // set the vertex attribute pointers
    // vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
//    // vertex texture coords
//    glEnableVertexAttribArray(2);
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UVs));
//
//    glEnableVertexAttribArray(3);
//    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UV2s));
//    //Bone IDs
//    glEnableVertexAttribArray(4);
//    glVertexAttribIPointer(4, SubMesh::NUM_BONES_PER_VERTEX, GL_INT, sizeof(Vertex), (void*)offsetof(Vertex, IDs));
//    //Weights
//    glEnableVertexAttribArray(5);
//    glVertexAttribPointer(5, SubMesh::NUM_BONES_PER_VERTEX, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Weights));
//    // vertex tangent
//    glEnableVertexAttribArray(6);
//    glVertexAttribPointer(6, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
//    // vertex bitangent
//    glEnableVertexAttribArray(7);
//    glVertexAttribPointer(7, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
//    // colors
//    glEnableVertexAttribArray(8);
//    glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));

    glBindVertexArray(0);
}

void Crimson::SubMesh::Render() {
//    if(this->hasBones)
//    {
//        shader->setInt("hasBones", 1);
//    }else{
//        shader->setInt("hasBones", 0);
//    }
    glBindVertexArray(this->VAO);
    if (_subMeshAsset->indexed)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
        glDrawElements(GL_TRIANGLES, _subMeshAsset->indices.size(), GL_UNSIGNED_INT, 0);
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0, _subMeshAsset->vertices.size());
    }
    glBindVertexArray(0);
}

void Crimson::SubMesh::SetGeometryData(Crimson::GeometryData* geometryData) {
    _subMeshAsset = geometryData;
    InitBuffers();
}

int Crimson::SubMesh::GetMaterialIndex() {
    return _subMeshAsset->materialIndex;
}

void Crimson::SubMesh::Release() {
    //todo: implement release here
}


