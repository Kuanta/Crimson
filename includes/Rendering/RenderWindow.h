#ifndef RAYTRACER_RENDERWINDOW_H
#define RAYTRACER_RENDERWINDOW_H

#include <glad.h>
#include <GLFW/glfw3.h>

namespace Crimson
{
    class RenderWindow {

    public:
        GLFWwindow* glfwWindow;

        bool Initialize();
        void Render();
        bool ShouldClose();
        void SetWindowShouldClose();
        void Cleanup();

    private:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    };

}


#endif //RAYTRACER_RENDERWINDOW_H
