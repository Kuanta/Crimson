//
// Created by erdem on 18.08.2023.
//

#ifndef CRIMSON_NOTIFIERCOMPONENT_H
#define CRIMSON_NOTIFIERCOMPONENT_H

#include "Core/ECS/Component.h"
namespace Crimson
{
    class NotifierComponent : public Component{
    public:
        void Update(float deltaTime) override;

    private:
        float _lastTime;
    };

}


#endif //CRIMSON_NOTIFIERCOMPONENT_H
