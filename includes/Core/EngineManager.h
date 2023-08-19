//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_ENGINEMANAGER_H
#define CRIMSON_ENGINEMANAGER_H

#include <list>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include "Core/TimeManager.h"
#include "Core/AMS/AssetManager.h"

namespace Crimson
{
    class EngineModule;

    class EngineManager {
//Fields
    public:

    protected:

    private:
        std::unordered_map<std::type_index, EngineModule*> modulesMap;

//Methods
    public:
        bool InitializeEngine();
        void StartEngine();
        void StopEngine();
        void RegisterModule(EngineModule* module);
        void Update();
        void Render();
        void LateUpdate();

    template<typename T>
    T* GetEngineModule()
    {
        std::type_index typeIndex(typeid(T));
        if (modulesMap.find(typeIndex) != modulesMap.end())
        {
            return dynamic_cast<T*>(modulesMap[typeIndex]);
        }
        return nullptr;
    }

    public:
        TimeManager TimeManager;
        AssetManager AssetManager;

    protected:

    private:
        bool _engineShouldStop = false;

    };

}


#endif //CRIMSON_ENGINEMANAGER_H
