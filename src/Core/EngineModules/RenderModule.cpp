//
// Created by erdem on 17.08.2023.
//

#include "Core/Modules/RenderModule.h"
#include "Core/EngineManager.h"
#include "Rendering/RenderWindow.h"

namespace Crimson
{
    RenderModule::RenderModule() {}

    RenderModule::~RenderModule()
    {
        if (_currentWindow)
            _currentWindow->Cleanup();
        glfwTerminate();
    }

    bool RenderModule::Initialize()
    {
        //1. Initialize Glfw
        if(!glfwInit())
        {
            fprintf(stderr, "Failed to initialize glfw!\n");
            return false;
        }

        //2. Configure GLFW
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

        //3. Create context window
       _currentWindow = new Crimson::RenderWindow();
       if(!_currentWindow->Initialize()){
           return false;
       }
        _currentWindow->SetCurrentContext();

        if (!glfwGetCurrentContext()) {
            fprintf(stderr, "Failed to create valid GLFW context!\n");
            return false;
        }

        // 4. Initialize GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            fprintf(stderr, "Failed to initialize GLAD!\n");
            return false;
        }

        //5. Set default opengl settings
        glViewport(0, 0, 800, 600);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return true;
    }

    void RenderModule::Update(float deltaTime)
    {
        if (!_currentWindow)
        {
            ParentManager->StopEngine();
            return;
        }
        _currentWindow->Render();

        if (_currentWindow->ShouldClose())
        {
            _currentWindow->SetWindowShouldClose();
        }
    }

    void RenderModule::PreRender() {
        EngineModule::PreRender();
        glClearColor(0.0f,0.2f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void RenderModule::Render() {
        EngineModule::Render();
    }

    void RenderModule::PostRender() {
        EngineModule::PostRender();
        if(_currentWindow == nullptr) return;
        _currentWindow->Cleanup();
    }

}