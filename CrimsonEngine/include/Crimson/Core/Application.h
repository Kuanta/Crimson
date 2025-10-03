#pragma once
#include "Crimson/Core/Core.h"
#include "Crimson/Core/Log/CrimsonLog.h"

namespace Crimson
{
    class CRIMSON_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };
    
    //To be defined in application
    Application* CreateApplication();

} // namespace Crimson
