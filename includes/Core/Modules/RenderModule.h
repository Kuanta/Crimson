//
// Created by erdem on 17.08.2023.
//

#ifndef CRIMSON_RENDERMODULE_H
#define CRIMSON_RENDERMODULE_H


#include <GLFW/glfw3.h>
#include "EngineModule.h"

namespace Crimson
{
    class UniformBuffer;
    class RenderWindow;
    class Shader;
    class RenderModule : public EngineModule
    {
    public:
        RenderModule();
        ~RenderModule();

        bool Initialize() override;
        void PreRender() override;
        void Update(float deltaTime) override;
        void Render() override;
        void PostRender() override;

        void BindUniformBuffersToShader(Shader* shader);

    private:
        RenderWindow* _currentWindow = nullptr;

        //Buffers
        UniformBuffer* matricesBuffer = nullptr;
        UniformBuffer* lightsBuffer = nullptr;
    };
}
#endif //CRIMSON_RENDERMODULE_H
