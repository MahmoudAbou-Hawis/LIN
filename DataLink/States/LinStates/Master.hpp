#ifndef MASRER_H_
#define MASTER_H_

#include "interfaces/abstractNotifier.hpp"
#include <utility>
#include <stdint.h>
#include "LinConf.h"

class Master : public LinsStates
{
    private:
        Master(){};
    public:
        void handle() override;
        void  set(uint32_t currentTime);
        void  set(LinConnection * Connection);
        static Master &getInstance()
        {
            static Master Instance;
            return Instance;
        }
    private:
        uint32_t  time;
        LinConnection * mConnection;
};


#endif
