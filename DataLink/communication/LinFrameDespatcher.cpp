#include "LinFrameDespatcher.hpp"
#include "interfaces/abstracttransportadabter.hpp"
#include "interfaces/abstractNotifier.hpp"
#include "States/LinStates/ReceivingBreak.hpp"
#include "LinConf.h"
void FrameDespatcher::set(std::array<AbstracterdConnectionHandler*, NUMBER_LIN_HANDLERS> &handlers ,
                          AbstractTranspoertAdabter *ta ,LinConnection * connection)

{
    for(uint8_t cnt = 0 ; cnt < NUMBER_LIN_HANDLERS ; cnt++)
    {
        mHandlers[cnt] = handlers[cnt];
    }
    mTa = ta;
}


void FrameDespatcher::dispatch(frame &_frame)
{
    for(auto &handler : mHandlers)
    {
        if(handler->CanYouHandle(_frame.head))
        {
            handler->handle(_frame);
            return;
        }
    }
#if NODE_TYPE == SLAVE
    mConnection->setState(ReceivingBreak::getInstance());
    mConnection->request();
#endif
}
