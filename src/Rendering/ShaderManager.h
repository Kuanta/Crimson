//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_SHADERMANAGER_H
#define CRIMSON_SHADERMANAGER_H

#include <map>
#include <string>
#include "Shader.h"
#include "Utils/Events.hpp"

namespace Crimson
{
    class ShaderManager {
    public:
        std::map<std::string, Shader*> shaders;

        ShaderManager();
        Shader* GetShader(std::string name);
        void InitShader(std::string shaderName);
        void DeleteShader(std::string shaderName);

        //Events
        Crimson::Event<Shader*> shaderCreatedEvent;

    private:
        Shader* CreateShader(std::string shaderName);
    };
}



#endif //CRIMSON_SHADERMANAGER_H
