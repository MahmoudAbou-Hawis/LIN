#ifndef ABSTRACTEDNOTIFIER_H_
#define ABSTRACTEDNOTIFIER_H_
#include "States/LinStates/LinConnection.hpp"

class Notifier
{
    public:
        virtual ~Notifier() = default;
    public:
        virtual void notify(LinConnection * device) = 0;
};

#endif
