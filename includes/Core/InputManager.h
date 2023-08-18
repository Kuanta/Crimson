//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_INPUTMANAGER_H
#define CRIMSON_INPUTMANAGER_H

#include <stdio.h>
#include <GLFW/glfw3.h>

class InputManager {
public:
    bool Initialize(GLFWwindow* window);

    //Input Methods
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};


#endif //CRIMSON_INPUTMANAGER_H
