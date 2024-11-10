#include "ReceivingBreak.hpp"

void Handler(ReceivingBreak * arg)
{
    arg->mConnection->setState(arg->getInstance());
    arg->mConnection->getNotifier()->notify(arg->mConnection);
}

void handleReceivingBreakWrapper(void *arg) {
    Handler(static_cast<ReceivingBreak*>(arg));
}

void ReceivingBreak::handle()
{
    mTp->DisableRx();
    mTp->DisableTx();
    mTp->setBreakingHandler(handleReceivingBreakWrapper,static_cast<void*>(this));
}

void ReceivingBreak::set(AbstractTranspoertAdabter *adapter,LinConnection * con)
{
    mConnection = con;
    mTp = adapter;
}

