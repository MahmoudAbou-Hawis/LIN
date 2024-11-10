#include "ReceivingHeader.hpp"

void Handler(ReceivingHeader * arg)
{
    arg->mConnection->getNotifier()->notify(arg->mConnection);
}

void handleReceivingHeaderWrapper(void *arg) {
    Handler(static_cast<ReceivingHeader*>(arg));
}


void ReceivingHeader::handle()
{
    mTp->setRxHandler(handleReceivingHeaderWrapper,static_cast<void*>(this));
    mTp->receive(fre.head);
}

void ReceivingHeader::set(AbstractTranspoertAdabter *adapter,LinConnection *con)
{
    mTp = adapter;
    mConnection = con;
}
