#ifndef SENDINGBREAK_H_
#define SENDINGBREAK_H_

#include "interfaces/abstractLinState.hpp"
#include "interfaces/abstracttransportadabter.hpp"
#include "interfaces/abstractNotifier.hpp"


class SendingBreak : public LinsStates
{
    private:
    SendingBreak(){};
    public:
        void handle() override;
        void  set(LinConnection * connection, AbstractTranspoertAdabter * Tb);
        static SendingBreak &getInstance()
        {
            static SendingBreak Instance;
            return Instance;
        }
    private:
        LinConnection * mConnection;
        AbstractTranspoertAdabter * mTb;
};

#endif
