#include "SendingHeader.hpp"


void SendingHeader::handle()
{
    mTb->send(fre.head);
    mConnection->getNotifier()->notify(mConnection);
}


void SendingHeader::set(LinConnection * connection, AbstractTranspoertAdabter * Tb)
{
     mConnection = connection;
     mTb = Tb;
}
