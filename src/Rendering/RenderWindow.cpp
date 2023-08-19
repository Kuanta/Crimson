//
// Created by erdem on 26.12.2022.
//

#include "Rendering/RenderWindow.h"

bool Crimson::RenderWindow::Initialize() {

    this->glfwWindow = glfwCreateWindow(800, 600, "Crimson", NULL, NULL);
    glfwSetFramebufferSizeCallback(this->glfwWindow, framebuffer_size_callback);
    if(glfwWindow == nullptr)
    {
        return false;
    }

    glfwSetFramebufferSizeCallback(glfwWindow, framebuffer_size_callback);
    glfwSetWindowUserPointer(glfwWindow, this);
    return true;
}

void Crimson::RenderWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Crimson::RenderWindow::Render() {
    glfwPollEvents();
    glfwSwapBuffers(glfwWindow);
}

bool Crimson::RenderWindow::ShouldClose() {

    return glfwWindowShouldClose(glfwWindow);
}

void Crimson::RenderWindow::Cleanup() {
    glfwDestroyWindow(glfwWindow);
}

void Crimson::RenderWindow::SetWindowShouldClose() {
    glfwSetWindowShouldClose(glfwWindow, true);
}

void Crimson::RenderWindow::SetCurrentContext() {
    glfwMakeContextCurrent(glfwWindow);
}
