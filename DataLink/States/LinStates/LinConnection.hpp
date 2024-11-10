#ifndef LINCONNECTION_H_
#define LINCONNECTION_H_
#include "interfaces/abstractLinState.hpp"


class Notifier;

class LinConnection {
    public:  
        LinConnection(LinsStates * state ,Notifier * notifier) : CurrentState(state) , mNotifier(notifier){}
        void setState(LinsStates& newState);
        void request();
        Notifier * getNotifier();
        friend class RNotifier;
    private:
        LinsStates * CurrentState{nullptr};
        Notifier  * mNotifier{nullptr};
};

#endif
