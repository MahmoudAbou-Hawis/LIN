#include "Init.hpp"
                                       
void Init::handle()
{
    mTb->Init();
    mConnection->getNotifier()->notify(mConnection);
}

void Init::set(LinConnection * connection, AbstractTranspoertAdabter * Tb)
{
    mConnection = connection;
    mTb = Tb;
}
