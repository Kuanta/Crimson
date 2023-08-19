//
// Created by erdem on 17.08.2023.
//

#ifndef CRIMSON_ENTITY_H
#define CRIMSON_ENTITY_H

#include "Utils/ElementList.h"

namespace Crimson
{
    class Scene;
    class Component;
    class Entity
    {
        //Methods
        public:
            Entity(){
                Name = "Default Entity";
                Initialize();
            }
            Entity(const std::string& name);
            ~Entity(){}

            //Children
            void Add(Entity* entity);
            void Remove(int sceneId);
            void Remove(Entity* entity);
            void Destroy();

            //Components
            virtual void AddComponent(Component* component);

            template<typename T>
            T* GetComponent();

            //Lifecycle
            virtual void Initialize();
            virtual void Update(float deltaTime);
            virtual void Render();
            virtual void LateUpdate(float deltaTime);

        //Properties
        public:
            int SceneId{};
            string Name;
            ElementsList<Entity*> Children;
            std::vector<Component*> Components;
            Entity* ParentEntity{};
            Scene* ParentScene;
    };
}
#endif //CRIMSON_ENTITY_H
