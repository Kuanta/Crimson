//
// Created by erdem on 26.12.2022.
//

#include "Shader.h"

Crimson::Shader::Shader() {

}

Crimson::Shader::Shader(const char *vertexPath, const char *fragmentPath) {
    unsigned int vertex = this->loadShader(vertexPath, GL_VERTEX_SHADER);
    unsigned int fragment = this->loadShader(fragmentPath, GL_FRAGMENT_SHADER);
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Crimson::Shader::Shader(const char *vertexPath, const char *geometryPath, const char *fragmentPath) {
    unsigned int vertex = this->loadShader(vertexPath, GL_VERTEX_SHADER);
    unsigned int geometry = this->loadShader(geometryPath, GL_GEOMETRY_SHADER);
    unsigned int fragment = this->loadShader(fragmentPath, GL_FRAGMENT_SHADER);
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, geometry);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");
    glDeleteShader(vertex);
    glDeleteShader(geometry);
    glDeleteShader(fragment);
}

unsigned int Crimson::Shader::loadShader(const char *shaderPath, unsigned int type) {
    std::string shaderCode;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        shaderFile.open(shaderPath);
        std::stringstream shaderStream;
        // read file's buffer contents into streams
        shaderStream << shaderFile.rdbuf();
        // close file handlers
        shaderFile.close();
        // convert stream into string
        shaderCode = shaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        std::cout<<shaderPath<<std::endl;
        return -1; //Failed to create shader
    }
    const char* _shaderCode = shaderCode.c_str();
    // 2. compile shaders
    unsigned int shader;
    int success;
    char infoLog[512];
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &_shaderCode, NULL);
    glCompileShader(shader);
    this->checkCompileErrors(shader, "SHADER");
    return shader;
}
