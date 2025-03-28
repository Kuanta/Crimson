//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_EVENTS_HPP
#define CRIMSON_EVENTS_HPP

#include <vector>

namespace Crimson
{
    template <typename T>
    class Delegate
    {
    public:
        virtual void Invoke(T param) = 0;
    };

    template <typename T>
    class Event
    {
    public:
        void operator += (Delegate<T>* delegate)
        {
            _delegates.push_back(delegate);
        }
        void operator -=(Delegate<T>* delegate)
        {
            RemoveElement(_delegates, delegate);
        }
        void operator()(T param)
        {
            for(auto subscriber:this->_delegates)
            {
                subscriber->Invoke(param);
            }
        }

    private:
        std::vector<Delegate<T>*> _delegates;
    };
}

#endif //CRIMSON_EVENTS_HPP
