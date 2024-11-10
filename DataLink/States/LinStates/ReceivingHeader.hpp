#ifndef RECEVINGHEADER_H_
#define RECEVINGHEADER_H_

#include "interfaces/abstractLinState.hpp"
#include "interfaces/abstracttransportadabter.hpp"
#include "interfaces/abstractNotifier.hpp"

class ReceivingHeader : public LinsStates
{
    private:
        ReceivingHeader(){};
    public:
        void handle() override;
        void set(AbstractTranspoertAdabter *adapter,LinConnection *con );
        static ReceivingHeader &getInstance()
        {
            static ReceivingHeader Instance;
            return Instance;
        }
        friend void Handler(ReceivingHeader * arg);
    private:
        AbstractTranspoertAdabter * mTp{nullptr};
        LinConnection *mConnection;
};

#endif
