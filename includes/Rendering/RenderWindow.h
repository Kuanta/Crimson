#ifndef RAYTRACER_RENDERWINDOW_H
#define RAYTRACER_RENDERWINDOW_H

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE 
#include <GLFW/glfw3.h>

namespace Crimson
{
    class RenderWindow {

    public:
        GLFWwindow* glfwWindow;

        //Lifecycle
        bool Initialize(int width, int height);
        void Render();
        void Cleanup();

        void SetCurrentContext();
        bool ShouldClose();
        void SetWindowShouldClose();

    private:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    };

}


#endif //RAYTRACER_RENDERWINDOW_H
