//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_SCENE_H
#define CRIMSON_SCENE_H

#include <string>
#include "Rendering/Camera.h"

namespace Crimson
{
    class Entity;
    class Scene{
    public:
        Scene();
        Scene(const std::string& name);
        void SetMainCamera(Camera* camera);
        Camera* GetMainCamera();
        void AddEntity(Entity* entity);

        //Lifecycle
        void OnSetup();
        void Update(float deltaTime);
        void Render();
        void LateUpdate(float deltaTime);
        void OnRemove();

    public:
        std::string Name;

    private:
        Camera* mainCamera;
        Entity* _root;
    };
}


#endif //CRIMSON_SCENE_H
