//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_TRANSFORM_H
#define CRIMSON_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "Utils/ElementList.h"

namespace Crimson
{
    class Actor;

    class Transform{
    public:
        Actor* owner;

        //Attributes
        glm::vec3 position;
        glm::quat rotation;
        glm::vec3 scale;


        Transform();

        void Update(float deltaTime);
        void Cleanup();

        //Transform Calculations
        void SetPosition(glm::vec3 position);
        void SetPosition(float x, float y, float z);
        void SetRotation(glm::vec3 eulerAngles);
        void SetRotation(glm::quat rotation);
        void SetScale(glm::vec3 scale);
        void SetForwardDirection(glm::vec3 forward);
        glm::vec3 GetForwardDirection();
        glm::vec3 GetRightDirection(glm::vec3 upVector = glm::vec3(0,1,0));

        glm::mat4 GetLocalMatrix();
        glm::mat4 GetModelMatrix();
        void SetModelMatrix(glm::mat4 modelMatrix);
        void UpdateLocalMatrix(); //Updates local matrix
        void UpdateModel(); //Updates final model matrix by checking its parents

    private:
        bool requireModelUpdate = false;
        glm::mat4 modelMatrix = glm::mat4(1.0);
        glm::mat4 localMatrix = glm::mat4(1.0);
    };

}

#endif //CRIMSON_TRANSFORM_H
