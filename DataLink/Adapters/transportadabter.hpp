#ifndef TRANSPORTADABTER_H_
#define TRANSPORTADABTER_H_

#include "DataLink/interfaces/abstracttransportadabter.hpp"
#include "Transport-api/Transport.hpp"
#include <stdint.h>
class TransportAdapter : public AbstractTranspoertAdabter
{
    public:
        TransportAdapter(AbstractedTransport * trans);
    public:
        void Init() override;
        void send(header & hed)override ;    
        void send(response & res) override;    
        void send() override;
        void send(uint8_t byte) override;
        void receive(response & res) override;
        void receive(header & hed)override ;    
        void setTxHandler(void (*callback)(void*) , void *)override ;
        void setRxHandler(void (*callback)(void*), void *)override ;   
        void setBreakingHandler(void (*callback)(void*), void *) override;   
        void DisableRx() override;
        void DisableTx() override;
        void receive(uint8_t * data) override;
    private:
        AbstractedTransport * mTrans {nullptr};
};

#endif
