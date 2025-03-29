#pragma once
#include "Crimson/Core/Core.h"

namespace Crimson
{
    class CRIMSON_API Application
    {
    public:
        Application();
        virtual ~Application();


        void Run();

        void Test();    
    };
    
    //To be defined in application
    Application* CreateApplication();

} // namespace Crimson
