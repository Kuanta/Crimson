//
// Created by erdem on 18.08.2023.
//

#include <iostream>
#include "NotifierComponent.h"
#include "Core/ECS/Entity.h"
#include "Core/TimeManager.h"

void Crimson::NotifierComponent::Update() {
    Component::Update();

    float timeSince = TimeManager::GetElapsedTime() - _lastTime;
    if(timeSince > 2.0f)
    {
        std::cout<<"Updating "<<ParentEntity->Name<<std::endl;
        _lastTime = TimeManager::GetElapsedTime();
    }
}
