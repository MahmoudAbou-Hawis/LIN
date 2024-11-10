#include "DispatchingAndHandling.hpp"
#include "interfaces/abstractNotifier.hpp"

void Handler(DispatchingAndHandling * arg)
{
    arg->mConnection->getNotifier()->notify(arg->mConnection);
}

void handleReceivingResponseWrapper(void *arg) {
    Handler(static_cast<DispatchingAndHandling*>(arg));
}


void DispatchingAndHandling::handle()
{
    mDispatcher->dispatch(fre);
    mTb->setRxHandler(handleReceivingResponseWrapper,static_cast<void*>(this));
}
void DispatchingAndHandling::set(AbstractedFramedDispatcher * disp,LinConnection * con ,AbstractTranspoertAdabter * Tb )
{
    mDispatcher = disp;
    mConnection = con;
    mTb = Tb;
}


