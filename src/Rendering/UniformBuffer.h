//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_UNIFORMBUFFER_H
#define CRIMSON_UNIFORMBUFFER_H

#include <glm/glm.hpp>
#include "Shader.h"

namespace Crimson
{
    class UniformBuffer {
    public:
        UniformBuffer(unsigned int byteSize, const char* blockName, int bindingPoint);
        void setBindingPoint(Shader* shader);
        void bindBuffer();

        //Data update methods
        void updateInt(int data, unsigned int offset);
        void updateFloat(float data, unsigned int offset);
        void updateVec2(glm::vec2 data, unsigned int offset);
        void updateVec3(glm::vec3 data, unsigned int offset);
        void updateVec4(glm::vec4 data, unsigned int offset);
        void updateMat2(glm::mat2 data, unsigned int offset);
        void updateMat3(glm::mat3 data, unsigned int offset);
        void updateMat4(glm::mat4 data, unsigned int offset);

    private:
        unsigned int bufferID;
        const char* blockName;
        unsigned int byteSize;
        int bindingPoint;
    };
};


#endif //CRIMSON_UNIFORMBUFFER_H
