#include "Renderer.h"

Crimson::Renderer::Renderer() {

}

bool Crimson::Renderer::Initialize() {
    window = new RenderWindow();
    shaderManager = new ShaderManager();
    shaderCreateHandler = new ShaderCreatedHandler();
    shaderCreateHandler->renderer = this;

    shaderManager->shaderCreatedEvent += shaderCreateHandler;

    if(!window->Initialize())
    {
        return false;
    }
    //Initialize buffers
    this->matricesBuffer = new UniformBuffer(16*9, "Matrices", 0);
    this->lightsBuffer = new UniformBuffer(MAX_NUMBER_LIGHTS*160 + 4, "Lights", 1);

    glEnable(GL_DEPTH_TEST);

    return true;
}

void Crimson::Renderer::OpenWindow() {

}

void Crimson::Renderer::PreRender() {

    if(window == nullptr) return;

    //... do rendering
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(camera == nullptr)
    {
        printf("Camera is null for current renderer\n");
        return;
    }

    //Bind matrices buffer
    if (this->matricesBuffer != nullptr)
    {
        this->matricesBuffer->bindBuffer(); //Set the active buffer
        this->matricesBuffer->updateMat4(this->camera->getViewMatrix(), 0);
        this->matricesBuffer->updateMat4(this->camera->getProjectionMatrix(), sizeof(glm::mat4));
        this->matricesBuffer->updateVec3(this->camera->transform->position, sizeof(glm::mat4) * 2);
    }
}

void Crimson::Renderer::InitializeFrameBuffer() {

}

void Crimson::Renderer::PostRender() {
    window->Render();
}

void Crimson::Renderer::SetMainCamera(Crimson::Camera *camera) {
    this->camera = camera;
}

void Crimson::Renderer::BindUniformBuffersToShader(Crimson::Shader *shader) {
    matricesBuffer->setBindingPoint(shader);
    lightsBuffer->setBindingPoint(shader);
}

void Crimson::ShaderCreatedHandler::Invoke(Crimson::Shader *param) {
    if(this->renderer == nullptr) return;
    this->renderer->BindUniformBuffersToShader(param);
}