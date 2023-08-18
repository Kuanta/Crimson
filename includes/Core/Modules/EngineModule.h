//
// Created by erdem on 6.08.2023.
//

#ifndef CRIMSON_ENGINEMODULE_H
#define CRIMSON_ENGINEMODULE_H

namespace Crimson
{
    class EngineManager;

    class EngineModule {
    public:
        virtual ~EngineModule(){}
        virtual bool Initialize() = 0;
        virtual void Update(float deltaTime) {}
        virtual void LateUpdate(float deltaTime){}
        virtual void Render(){}

    public:
        EngineManager* ParentManager;
    };

}


#endif //CRIMSON_ENGINEMODULE_H
