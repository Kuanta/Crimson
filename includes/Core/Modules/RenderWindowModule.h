//
// Created by erdem on 17.08.2023.
//

#ifndef CRIMSON_RENDERWINDOWMODULE_H
#define CRIMSON_RENDERWINDOWMODULE_H


#include <GLFW/glfw3.h>
#include "EngineModule.h"

namespace Crimson
{
    class RenderWindowModule : public EngineModule
    {
    public:
        RenderWindowModule();
        ~RenderWindowModule();

        virtual bool Initialize() override;
        virtual void Update(float deltaTime) override;

        GLFWwindow* GetWindow() const { return window; }

    private:
        GLFWwindow* window = nullptr;
    };
}
#endif //CRIMSON_RENDERWINDOWMODULE_H
