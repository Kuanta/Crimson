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
        Scene* GetCurrentScene();
        void Update() override;
        void Render() override;
        void LateUpdate() override;

    private:
        Scene* CurrentScene;
    };

}

#endif //CRIMSON_SCENEMANAGER_H
