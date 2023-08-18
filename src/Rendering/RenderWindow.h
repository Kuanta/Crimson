#ifndef RAYTRACER_RENDERWINDOW_H
#define RAYTRACER_RENDERWINDOW_H

#include <glad.h>
#include <GLFW/glfw3.h>


class RenderWindow {

public:
    GLFWwindow* glfwWindow;

    bool Initialize();
    void Render();
    bool ShouldClose();


private:
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};


#endif //RAYTRACER_RENDERWINDOW_H
