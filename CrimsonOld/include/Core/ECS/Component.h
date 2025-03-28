//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_COMPONENT_H
#define CRIMSON_COMPONENT_H

namespace Crimson
{
    class Entity;
    class Transform;
    class Component {
    public:
        Component() {
            Initialize();
        };
        ~Component()= default;
        virtual void OnAttach(){};
        virtual void OnRemove(){};
        virtual void Initialize(){};
        virtual void Update(){};
        virtual void LateUpdate(){};
        virtual void FixedUpdate(){};
        virtual void Render(){};
        virtual void Cleanup(){};

        Entity* ParentEntity = nullptr;
        bool enabled = true;
        Transform* transform; //Since this is used too much, add it as ref
    };
}



#endif //CRIMSON_COMPONENT_H
