#ifndef RECEVINGBREAK_H_
#define RECEVINGBREAK_H_

#include "interfaces/abstractLinState.hpp"
#include "interfaces/abstracttransportadabter.hpp"
#include "interfaces/abstractNotifier.hpp"

class ReceivingBreak : public LinsStates
{
    private:
        ReceivingBreak(){};
    public:
        void handle() override;
        void set(AbstractTranspoertAdabter *adapter, LinConnection * con);
        static ReceivingBreak &getInstance()
        {
            static ReceivingBreak Instance;
            return Instance;
        }
        friend void Handler(ReceivingBreak * arg);
    private:
        AbstractTranspoertAdabter * mTp{nullptr};
        LinConnection *mConnection;
};


#endif
