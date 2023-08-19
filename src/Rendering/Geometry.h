//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_GEOMETRY_H
#define CRIMSON_GEOMETRY_H


#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Rendering/Shader.h"

namespace Crimson
{

    struct Vertex;

    class Geometry {
    public:
        //Attributes
        static const int NUM_BONES_PER_VERTEX = 4;
        const static int MAX_BONE = 100;
        bool hasBones = false;
        std::vector<Vertex> vertices;
        unsigned int VAO, VBO, EBO;
    private:
        bool indexed;
        std::vector<unsigned int> indices;

    public:
        //Methods
        Geometry(){}
        Geometry(std::vector<Vertex> vertices, std::vector<unsigned int> indices, bool initBuffers = true); // For indexed geometries
        Geometry(std::vector<Vertex> vertices, unsigned int indices[], bool initBuffers = true);
        Geometry(std::vector<Vertex> vertices, bool initBuffers = true);

        void SetIndices(unsigned int indices[], int indicesSize);
        void InitBuffers();
        void Draw(Shader* shader);

    private:
        void InitGeometry(std::vector<Vertex> verticesa, bool initBuffers);

    };

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
        int IDs[Geometry::NUM_BONES_PER_VERTEX];
        //Bone Weights
        float Weights[Geometry::NUM_BONES_PER_VERTEX];
        // tangent
        glm::vec3 Tangent;
        // bitangent
        glm::vec3 Bitangent;
    };
}



#endif //CRIMSON_GEOMETRY_H
