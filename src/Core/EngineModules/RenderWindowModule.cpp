//
// Created by erdem on 17.08.2023.
//

#include "Core/Modules/RenderWindowModule.h"
#include "Core/EngineManager.h"

namespace Crimson
{
    RenderWindowModule::RenderWindowModule() {}

    RenderWindowModule::~RenderWindowModule()
    {
        if (window)
            glfwDestroyWindow(window);
        glfwTerminate();
    }

    bool RenderWindowModule::Initialize()
    {
        if (!glfwInit())
            return false;

        window = glfwCreateWindow(800, 600, "Crimson Engine", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            ParentManager->StopEngine();
            return false;
        }

        glfwMakeContextCurrent(window);

        return true;
    }

    void RenderWindowModule::Update(float deltaTime)
    {
        if (!window)
        {
            ParentManager->StopEngine();
            return;
        }
        glfwPollEvents();

        if (glfwWindowShouldClose(window))
            glfwSetWindowShouldClose(window, true);
    }
}