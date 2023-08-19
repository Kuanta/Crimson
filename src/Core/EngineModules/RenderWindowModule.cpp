//
// Created by erdem on 17.08.2023.
//

#include "Core/Modules/RenderWindowModule.h"
#include "Core/EngineManager.h"
#include "Rendering/RenderWindow.h"

namespace Crimson
{
    RenderWindowModule::RenderWindowModule() {}

    RenderWindowModule::~RenderWindowModule()
    {
        if (_currentWindow)
            _currentWindow->Cleanup();
        glfwTerminate();
    }

    bool RenderWindowModule::Initialize()
    {
        //Initialize Glfw
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_SAMPLES, 0);
        glfwWindowHint(GLFW_RED_BITS, 16);
        glfwWindowHint(GLFW_GREEN_BITS, 16);
        glfwWindowHint(GLFW_BLUE_BITS, 16);
        glfwWindowHint(GLFW_ALPHA_BITS, 16);
        glfwWindowHint(GLFW_STENCIL_BITS, 16);
        glfwWindowHint(GLFW_DEPTH_BITS, 24);

       _currentWindow = new Crimson::RenderWindow();
       return _currentWindow->Initialize();
    }

    void RenderWindowModule::Update(float deltaTime)
    {
        if (!_currentWindow)
        {
            ParentManager->StopEngine();
            return;
        }
        glfwPollEvents();

        if (_currentWindow->ShouldClose())
        {
            _currentWindow->SetWindowShouldClose();
        }
    }

    void RenderWindowModule::PreRender() {
        EngineModule::PreRender();
        if(_currentWindow == nullptr) return;
        _currentWindow->Render();
    }

    void RenderWindowModule::Render() {
        EngineModule::Render();
        _currentWindow->Render();
    }

    void RenderWindowModule::PostRender() {
        EngineModule::PostRender();
        if(_currentWindow == nullptr) return;
        _currentWindow->Cleanup();
    }

}