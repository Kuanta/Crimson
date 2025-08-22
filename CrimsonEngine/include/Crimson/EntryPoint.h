#pragma once
#include "Crimson/Core/Application.h"

extern Crimson::Application* Crimson::CreateApplication();

int main(int argc, char** argv)
{
    Crimson::CrimsonLog::Init();
    CR_CORE_INFO("My logging work!");

    const char* name = "Kuanta";
    CR_INFO("Crimson Engine is developped by {0}", name);
    auto app = Crimson::CreateApplication();
    app->Run();
    delete app;
}