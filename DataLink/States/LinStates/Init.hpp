#ifndef LININIT_H_
#define LININIT_H_

#include "interfaces/abstractLinState.hpp"
#include "interfaces/abstracttransportadabter.hpp"
#include "interfaces/abstractNotifier.hpp"

class Init : public LinsStates
{
    private:
        Init(){};
    public:
        void handle() override;
        void  set(LinConnection * connection, AbstractTranspoertAdabter * Tb);
        static Init &getInstance()
        {
            static Init Instance;
            return Instance;
        }
    private:
        LinConnection * mConnection;
        AbstractTranspoertAdabter * mTb;
};

#endif
