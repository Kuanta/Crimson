//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_RENDERER_H
#define CRIMSON_RENDERER_H

#include "Rendering/RenderWindow.h"
#include "Rendering/UniformBuffer.h"
#include "Core/Camera.h"
#include "ShaderManager.h"

namespace Crimson
{
    class Renderer;

    class ShaderCreatedHandler: public Delegate<Shader*>
    {
    public:
        Renderer* renderer;
        void Invoke(Shader* param) override;
    };

    class Renderer {
    public:
        const int MAX_NUMBER_LIGHTS = 10;
        RenderWindow* window;
        ShaderManager* shaderManager;
        ShaderCreatedHandler* shaderCreateHandler;

        //Methods
        Renderer();
        bool Initialize();
        void OpenWindow();
        void BindUniformBuffersToShader(Shader* shader);

        //Clears the current window and binds global buffers
        void PreRender();
        void PostRender();
        void SetMainCamera(Camera* camera);

    private:
        Camera* camera;
        unsigned int fbo;
        unsigned int fboTexture;
        unsigned int rbo;

        UniformBuffer* matricesBuffer = nullptr;
        UniformBuffer* lightsBuffer = nullptr;

        void InitializeFrameBuffer();
        void DrawFrameBuffer();
        void RenderFrameBufferQuad();
    };
}


#endif //CRIMSON_RENDERER_H
