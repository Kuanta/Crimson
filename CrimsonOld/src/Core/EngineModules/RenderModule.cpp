#include "Core/Modules/RenderModule.h"
#include "Core/EngineManager.h"
#include "Rendering/RenderWindow.h"
#include "Rendering/Shader.h"
#include "Rendering/UniformBuffer.h"
#include "Core/Camera.h"
#include "Core/ECS/SceneManager.h"
#include "Core/ECS/Scene.h"

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
       if(!_currentWindow->Initialize(1920, 1080)){
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
        glViewport(0, 0, 1920, 1080);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        //Initialize buffers
        this->matricesBuffer = new UniformBuffer(16*9, "Matrices", 0);
        this->lightsBuffer = new UniformBuffer(100*160 + 4, "Lights", 1);

        return true;
    }

    void RenderModule::Update()
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

        //Bind matrices buffer
        Camera* camera = EngineManager::GetInstance()->GetEngineModule<SceneManager>()->GetCurrentScene()->GetMainCamera();

        if (this->matricesBuffer != nullptr && camera != nullptr)
        {
            this->matricesBuffer->bindBuffer(); //Set the active buffer
            this->matricesBuffer->updateMat4(camera->getViewMatrix(), 0);
            this->matricesBuffer->updateMat4(camera->getProjectionMatrix(), sizeof(glm::mat4));
            this->matricesBuffer->updateVec3(camera->transform->position, sizeof(glm::mat4) * 2);
        }
    }

    void RenderModule::Render() {
        EngineModule::Render();
    }

    void RenderModule::PostRender() {
        EngineModule::PostRender();

    }

    void RenderModule::BindUniformBuffersToShader(Shader *shader) {
        if(shader == nullptr) return;
        matricesBuffer->setBindingPoint(shader);
        lightsBuffer->setBindingPoint(shader);
    }

}