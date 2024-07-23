//
// Created by erdem on 20.08.2023.
//

#include "Utils/AssimpParser.h"
#include "Core/AMS/ModelAsset.h"
#include "Core/AMS/MeshAsset.h"

void Crimson::AssimpParser::LoadModel(ModelAsset* modelAsset, const std::string &filename) {

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(filename, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace | aiProcess_GenSmoothNormals);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
    {
        fprintf(stderr, "Error loading model: %s\n", importer.GetErrorString());
        return;
    }

    Crimson::ModelNode* rootNode = LoadNode(scene->mRootNode, scene);

    //Root transform
    glm::vec3 position;
    glm::quat orientation;
    glm::vec3 scale;
    aiMatrix4x4 rootTransform = scene->mRootNode->mTransformation;
    glm::mat4 globalInverseTransform = AiToGLMMat4(rootTransform);

    glm::vec3 unitVec3;
    glm::vec4 unitVec4;
    glm::decompose(AiToGLMMat4(rootTransform), scale, orientation, position, unitVec3, unitVec4);
    rootNode->transform.SetPosition(position);
    rootNode->transform.SetRotation(glm::eulerAngles(orientation));
    rootNode->transform.SetScale(scale);

}

Crimson::ModelNode *Crimson::AssimpParser::LoadNode(aiNode *node, const aiScene* scene) {
    ModelNode* modelNode = new ModelNode();
    modelNode->MeshAsset = new MeshAsset;
    modelNode->name = node->mName.data;

    //Decompose transformation of the mesh
    glm::vec3 position;
    glm::quat orientation;
    glm::vec3 scale;
    aiMatrix4x4 nodeTransform = node->mTransformation;

    glm::vec3 unitVec3;
    glm::vec4 unitVec4;
    glm::decompose(glm::transpose(AiToGLMMat4(nodeTransform)), scale, orientation, position, unitVec3, unitVec4);
    modelNode->transform.SetPosition(position);
    modelNode->transform.SetRotation(glm::eulerAngles(orientation));
    modelNode->transform.SetScale(scale);

    for (size_t i = 0; i < node->mNumChildren; i++)
    {
        ModelNode* child = LoadNode(node->mChildren[i], scene);
        modelNode->children.push_back(child);
    }

    if (node->mNumMeshes > 0)
    {
        for (size_t i = 0; i < node->mNumMeshes; i++)
        {
            GeometryData data = LoadMesh(node, scene->mMeshes[node->mMeshes[i]], scene);
            modelNode->MeshAsset->AddSubMeshAsset(data);
        }
    }

    return modelNode;
}

Crimson::GeometryData Crimson::AssimpParser::LoadMesh(aiNode* node, aiMesh* mesh, const aiScene* scene) {
    GeometryData data;


    for (int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        vertex.Position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
        //Normals
        vertex.Normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
        vertex.Tangent = glm::vec3(mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z);

        //UVs
        if (mesh->mTextureCoords[0])
        {
            vertex.UVs = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
        }
        //Initialize boneIDs (Will set correct values while loading bones)
        for (int j = 0; j < MeshAsset::NUM_BONES_PER_VERTEX; j++)
        {
            vertex.IDs[j] = -1;
            vertex.Weights[j] = 0;
        }
        data.vertices.push_back(vertex);
    }

    for (int i = 0; i <mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (int j = 0; j < face.mNumIndices; j++)
        {
            data.indices.push_back(face.mIndices[j]);
        }
    }

    //todo: Load material

    return data;
}
