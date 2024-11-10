#ifndef LINFRAMEDESPATCHER_H_
#define LINFRAMEDESPATCHER_H_

#include "interfaces/abstractedframedespatcher.hpp"
#include "interfaces/abstractedconnectionhandler.hpp"
#include "LinConf.h"
#include "interfaces/abstracttransportadabter.hpp"
#include "States/LinStates/LinConnection.hpp"

class FrameDespatcher : public AbstractedFramedDispatcher
{
    public:
        FrameDespatcher(){};
    public:
        void dispatch(frame &_frame) override;
        void set(std::array<AbstracterdConnectionHandler*, NUMBER_LIN_HANDLERS> &handlers,
                            AbstractTranspoertAdabter *ta,LinConnection * connection);
    private:
        std::array<AbstracterdConnectionHandler*, NUMBER_LIN_HANDLERS> mHandlers; 
        AbstractTranspoertAdabter *mTa;
        LinConnection * mConnection;
};


#endif
