//
// Created by erdem on 26.12.2022.
//

#include "RenderWindow.h"

bool RenderWindow::Initialize() {

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

    this->glfwWindow = glfwCreateWindow(800, 600, "Crimson", NULL, NULL);
    glfwSetFramebufferSizeCallback(this->glfwWindow, framebuffer_size_callback);
    if(glfwWindow == nullptr)
    {
        return false;
    }

    glfwMakeContextCurrent(glfwWindow);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return false;
    }

    glfwSetWindowUserPointer(glfwWindow, this);
    glViewport(0, 0, 800, 600);
    glEnable(GL_DEPTH_TEST);
    return true;
}

void RenderWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void RenderWindow::Render() {
    glfwPollEvents();
    glfwSwapBuffers(glfwWindow);
}

bool RenderWindow::ShouldClose() {

    return glfwWindowShouldClose(glfwWindow);
}
