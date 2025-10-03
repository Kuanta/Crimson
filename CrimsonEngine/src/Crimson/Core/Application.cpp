#include "Crimson/Core/Application.h"
#include <iostream>

namespace Crimson
{
    Crimson::Application::Application(){}
    Application::~Application(){}

    void Application::Run()
    {
        CR_INFO("Application Ran!");
    }

}