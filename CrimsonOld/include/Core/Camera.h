//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_CAMERA_H
#define CRIMSON_CAMERA_H

#include "Object.h"

namespace Crimson
{
    class Camera : public Component{
    public:
        Camera();
        Camera(float fov, float aspectRatio, float near, float far);

        void OnAttach() override;
        glm::mat4 getProjectionMatrix();
        glm::mat4 getViewMatrix();
    private:
        glm::mat4 projection;

    };
}



#endif //CRIMSON_CAMERA_H
