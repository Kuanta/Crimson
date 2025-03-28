#ifndef ELEMENT_LIST_H
#define ELEMENT_LIST_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
This class is a container based on std::vector
With it elements from middle can be removed and next elements can take empty spaces
*/
namespace Crimson
{
#pragma once

    template <typename T>
    class ElementsList
    {

    public:
        int AddElement(T element);
        void RemoveElement(int index);
        T GetElement(int index) const;

        vector<T> Elements;
    protected:

        std::queue<int> AvailableIndices;

    private:
        int GetAvailableIndex();

    };

    template <typename T>
    int ElementsList<T>::AddElement(T element)
    {
        int newIndex = GetAvailableIndex();
        if(newIndex >= Elements.size())
        {
            Elements.push_back(element);
        }else
        {
            Elements[newIndex] = element;
        }
        return newIndex;
    }

    template <typename T>
    void ElementsList<T>::RemoveElement(int index)
    {
        if(!Elements.size() <= index) return;
        Elements[index] = nullptr;
        AvailableIndices.push(index);
    }

    template <typename T>
    T ElementsList<T>::GetElement(int index) const
    {
        return Elements[index];
    }

    template <typename T>
    int ElementsList<T>::GetAvailableIndex()
    {
        if(AvailableIndices.empty())
        {
            return Elements.size();
        }

        int NextAvailableIndex = AvailableIndices.front();
        AvailableIndices.pop();
        return NextAvailableIndex;
    }

}


#endif
