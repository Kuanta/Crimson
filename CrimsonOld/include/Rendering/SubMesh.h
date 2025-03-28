//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_SUBMESH_H
#define CRIMSON_SUBMESH_H


#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Rendering/Shader.h"
#include "Core/AMS/MeshAsset.h"

namespace Crimson
{
    struct GeometryData;

    class SubMesh {

        public:
            //Methods
            SubMesh() = default;
            explicit SubMesh(GeometryData* geometryData);
            void SetGeometryData(GeometryData* geometryData);
            void InitBuffers();
            void Render();
            int GetMaterialIndex();
            void Release();

        public:
            unsigned int VAO{}, VBO{}, EBO{};

            //Constants
            const static int NUM_BONES_PER_VERTEX = 4;
            const static int MAX_BONE = 100;

    private:
        GeometryData* _subMeshAsset{};
    };
}


#endif //CRIMSON_SUBMESH_H
