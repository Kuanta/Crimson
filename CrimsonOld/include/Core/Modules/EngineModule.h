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
        virtual void Update() {}
        virtual void LateUpdate(){}
        virtual void PreRender(){}
        virtual void Render(){}
        virtual void PostRender(){}

    public:
        EngineManager* ParentManager;
    };

}


#endif //CRIMSON_ENGINEMODULE_H
