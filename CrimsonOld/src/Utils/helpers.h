//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_HELPERS_H
#define CRIMSON_HELPERS_H

#include <vector>

template <typename T>
void RemoveElement(std::vector<T> vector, T element)
{
    auto iter = vector.begin();
    bool remove = false;
    for(iter = vector.begin(); iter != vector.end(); iter++)
    {
        if(iter == element)
        {
            remove = true;
            break;
        }
    }
    if(remove)
    {
        vector.erase(element);
    }
}
#endif //CRIMSON_HELPERS_H
