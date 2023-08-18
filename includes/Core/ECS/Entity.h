//
// Created by erdem on 17.08.2023.
//

#ifndef CRIMSON_ENTITY_H
#define CRIMSON_ENTITY_H

#include "Utils/ElementList.h"

namespace Crimson
{
    class Component;
    class Entity
    {
        //Methods
        public:
            Entity(){}
            Entity(const std::string& name);
            ~Entity(){}

            //Children
            void Add(Entity* entity);
            void Remove(int sceneId);
            void Remove(Entity* entity);
            void Destroy();

            //Components
            void AddComponent(Component* component);

            //Lifecycle
            void Update(float deltaTime);
            void Render();
            void LateUpdate(float deltaTime);

        //Properties
        public:
            int SceneId;
            string Name;
            ElementsList<Entity*> Children;
            std::vector<Component*> Components;
            Entity* ParentEntity;

    };
}
#endif //CRIMSON_ENTITY_H
