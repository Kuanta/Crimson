//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_OBJECT_H
#define CRIMSON_OBJECT_H

#include "Transform.h"
#include "Core/ECS/Component.h"

namespace Crimson
{
    class Object {
    public:
        //Parameters
        string name;
        int id;

        Transform* transform;
        vector<Component*> components;

        //Lifecycle
        void Update(float deltaTime);
        void Render();
        void FixedUpdate(float fixedDeltaTime);
        void LateUpdate(float deltaTime);
        void Cleanup();

        //Methods
        Object();
        ~Object();


        void AddComponent(Component* component);
        void RemoveComponent(Component* component);
    };
}



#endif //CRIMSON_OBJECT_H
