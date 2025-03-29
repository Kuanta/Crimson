#pragma once
#include "Crimson/Core/Application.h"

extern Crimson::Application* Crimson::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Crimson::CreateApplication();
    app->Run();
    delete app;
}