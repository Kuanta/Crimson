//
// Created by erdem on 18.08.2023.
//

#ifndef CRIMSON_SCENEMANAGER_H
#define CRIMSON_SCENEMANAGER_H

#include "Core/Modules/EngineModule.h"

namespace Crimson
{
    class Scene;
    class SceneManager : public EngineModule{
    public:
        bool Initialize() override;
        void ChangeScene(Scene* newScene);
        void Update(float deltaTime) override;
        void Render() override;
        void LateUpdate(float deltaTime) override;

    private:
        Scene* CurrentScene;
    };

}

#endif //CRIMSON_SCENEMANAGER_H
