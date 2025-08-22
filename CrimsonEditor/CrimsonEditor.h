#pragma once
#include <Crimson.h>
#include <iostream>

namespace Crimson
{
    class CRIMSON_API Editor : public Crimson::Application
    {
    public:
        Editor()
        {
            std::cout<<"Engine Started"<<std::endl;
        }
        ~Editor()
        {
            
        }
    };

}