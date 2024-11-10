#include "LinConnection.hpp"
#include "interfaces/abstractNotifier.hpp"


void LinConnection::setState(LinsStates &newState)
{
    CurrentState = &newState;
}

void LinConnection::request()
{
    CurrentState->handle();
}

Notifier *LinConnection::getNotifier()
{
    return mNotifier;
}
