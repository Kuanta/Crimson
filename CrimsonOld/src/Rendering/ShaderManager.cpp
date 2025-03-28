//
// Created by erdem on 26.12.2022.
//

#include "Rendering/ShaderManager.h"

Crimson::ShaderManager::ShaderManager() {

}

Crimson::Shader *Crimson::ShaderManager::GetShader(std::string name) {
    Shader* shader = nullptr;
    if (this->shaders.find(name) == this->shaders.end())
    {
        shader = this->CreateShader(name);
        this->shaders.insert(std::pair<std::string, Shader*>(name, shader));
    }
    else {
        shader = this->shaders.at(name);
        if (shader == nullptr)
        {
            shader = this->CreateShader(name);
        }
    }
    return shader;
}

void Crimson::ShaderManager::InitShader(std::string shaderName) {
    if (this->shaders.find(shaderName) == this->shaders.end())
    {
        //No such key
        Shader* shader = this->CreateShader(shaderName);
        this->shaders.insert(std::pair<std::string, Shader*>(shaderName, shader));
    }
}

void Crimson::ShaderManager::DeleteShader(std::string shaderName) {
    Shader* shader = nullptr;
    if (this->shaders.find(shaderName) != this->shaders.end())
    {
        //No such key
        shader = this->shaders.at(shaderName);
        if (shader != nullptr)
        {
            shader->clean();
            this->shaders.at(shaderName) = nullptr;
        }
    }
}

Crimson::Shader *Crimson::ShaderManager::CreateShader(std::string shaderName) {
    Shader* shader = nullptr;
    shader = new Shader("../shaders/simple_vertex.txt", "../shaders/simple_fragment.txt");
//    switch (shaderName)
//    {
//        case "simple":
//            shader = new Shader("Shaders/simple_vertex.txt", "Shaders/simple_fragment.txt");
//            break;
////        case SHADER_TYPE::PBR_SHADER:
////            shader = new Shader("Shaders/simple_vertex.txt", "Shaders/pbr_fragment.txt");
////            break;
////        case SHADER_TYPE::OUTLINE_FRAGMENT:
////            shader = new Shader("Shaders/simple_vertex.txt", "Shaders/outline_fragment.txt");
////            break;
////        case SHADER_TYPE::FBO_SHADER:
////            shader = new Shader("Shaders/fbo_vertex.glsl", "Shaders/fbo_fragment.txt");
////            break;
////        case SHADER_TYPE::SKYBOX_SHADER:
////            shader = new Shader("Shaders/skybox_vertex.txt", "Shaders/skybox_fragment.txt");
////            break;
////        case SHADER_TYPE::DEPTH_SHADER:
////            shader = new Shader("Shaders/depth/depth_vertex.txt","Shaders/depth/depth_fragment.txt");
////            break;
////        case SHADER_TYPE::DEPTH_POINT_SHADER:
////            shader = new Shader("Shaders/depth/depth_point_vertex.txt", "Shaders/depth/depth_point_geometry.txt",
////                                "Shaders/depth/depth_point_fragment.txt");
////            break;
////        case SHADER_TYPE::GBUFFER_SHADER:
////            shader = new Shader("Shaders/gbuffer/gbuffer_vertex.txt", "Shaders/gbuffer/gbuffer_fragment.txt");
////            break;
////        case SHADER_TYPE::GBUFFER_SKY_SHADER:
////            shader = new Shader("Shaders/gbuffer/gbuffer_skybox_vertex.txt", "Shaders/gbuffer/gbuffer_skybox_fragment.txt");
////            break;
////        case SHADER_TYPE::DEFERRED_SHADER:
////            shader = new Shader("Shaders/fbo_vertex.glsl", "Shaders/deferred_fragment.glsl");
////            break;
//        default:
//            break;
//    }

    this->shaderCreatedEvent(shader); //Fire event
    return shader;
}
