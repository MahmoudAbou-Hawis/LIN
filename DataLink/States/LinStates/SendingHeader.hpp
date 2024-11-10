#ifndef SENDINGHEADER_H
#define SENDINGHEADER_H

#include "interfaces/abstractLinState.hpp"
#include "interfaces/abstracttransportadabter.hpp"
#include "interfaces/abstractNotifier.hpp"


class SendingHeader : public LinsStates
{
    private:
    SendingHeader(){};
    public:
        void handle() override;
        void  set(LinConnection * connection, AbstractTranspoertAdabter * Tb);
        static SendingHeader &getInstance()
        {
            static SendingHeader Instance;
            return Instance;
        }
    private:
        LinConnection * mConnection;
        AbstractTranspoertAdabter * mTb;
};

#endif
