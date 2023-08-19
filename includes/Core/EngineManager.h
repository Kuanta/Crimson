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
#include "Rendering/MaterialLibrary.h"

namespace Crimson
{
    class EngineModule;

    class EngineManager {
//Fields
    public:
        static EngineManager* GetInstance() {
            if (!instance)
                instance = new EngineManager;
            return instance;
        }

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

    protected:

    private:
        EngineManager() {}
        EngineManager(EngineManager const&) = delete;
        void operator=(EngineManager const&) = delete;

        std::unordered_map<std::type_index, EngineModule*> modulesMap;

//Methods



    public:
        TimeManager TimeManager;
        AssetManager AssetManager;
        MaterialLibrary MaterialLibrary;

    protected:

    private:
        static EngineManager* instance;
        bool _engineShouldStop = false;

    };

}

#endif //CRIMSON_ENGINEMANAGER_H
