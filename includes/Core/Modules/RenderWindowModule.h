//
// Created by erdem on 17.08.2023.
//

#ifndef CRIMSON_RENDERWINDOWMODULE_H
#define CRIMSON_RENDERWINDOWMODULE_H


#include <GLFW/glfw3.h>
#include "EngineModule.h"

namespace Crimson
{
    class RenderWindow;
    class RenderWindowModule : public EngineModule
    {
    public:
        RenderWindowModule();
        ~RenderWindowModule();

        bool Initialize() override;
        void PreRender() override;
        void Update(float deltaTime) override;
        void Render() override;
        void PostRender() override;


    private:
        RenderWindow* _currentWindow = nullptr;
    };
}
#endif //CRIMSON_RENDERWINDOWMODULE_H
