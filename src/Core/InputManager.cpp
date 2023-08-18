//
// Created by erdem on 26.12.2022.
//

#include "../../includes/Core/InputManager.h"

bool InputManager::Initialize(GLFWwindow* window) {
    glfwSetKeyCallback(window, keyCallback);


    return true;
}

void InputManager::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
        printf("CLose\n");
    }
}
