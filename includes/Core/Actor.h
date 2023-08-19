//
// Created by erdem on 19.08.2023.
//

#ifndef CRIMSON_ACTOR_H
#define CRIMSON_ACTOR_H

#include <memory>
#include "Core/ECS/Entity.h"

namespace Crimson
{
    class Transform;
    class Component;
    class Actor: public Entity
    {
    public:
        Actor();
        Actor(const std::string& name);
        void Initialize() override;
        void LateUpdate(float deltaTime) override;
        void AddComponent(Component* component) override;
    public:
        Transform* transform;
    };
}
#endif //CRIMSON_ACTOR_H
