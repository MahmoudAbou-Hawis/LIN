#include "SendingBreak.hpp"


void SendingBreak::set(LinConnection * connection , AbstractTranspoertAdabter *Tb)
{
    mTb = Tb;
    mConnection = connection;
}

void SendingBreak::handle()
{
    mTb->send();
    mConnection->getNotifier()->notify(mConnection);
}
