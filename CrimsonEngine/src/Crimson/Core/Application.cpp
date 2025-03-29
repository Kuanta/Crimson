#include "Crimson/Core/Application.h"
#include <iostream>

namespace Crimson
{
    Crimson::Application::Application(){}
    Application::~Application(){}
    void Application::Test()
    {
        std::cout<<"Testing!"<<std::endl;
    }

    void Application::Run()
    {
        std::cout<<"Ran!"<<std::endl;
    }

}