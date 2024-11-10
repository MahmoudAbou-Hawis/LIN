#ifndef ABSTRACTEDTRANSPORTADABTER_H_
#define ABSTRACTEDTRANSPORTADABTER_H_

#include "DataLink/frame/header.hpp"
#include "DataLink/frame/response.hpp"

class AbstractTranspoertAdabter 
{
    public:
        virtual void Init() = 0;
        virtual void send(header & hed) = 0;    
        virtual void send(response & res) = 0;    
        virtual void send(uint8_t byte) = 0;
        virtual void send() = 0;
        virtual void receive(response & res) = 0;
        virtual void receive(header & hed) = 0;    
        virtual void DisableRx() = 0;
        virtual void DisableTx() = 0;
        virtual void receive(uint8_t *  data) = 0;
        virtual void setTxHandler(void (*callback)(void*), void *) = 0;
        virtual void setRxHandler(void (*callback)(void*), void *) = 0;
        virtual void setBreakingHandler(void (*callback)(void*), void *) = 0;   
        virtual ~AbstractTranspoertAdabter() = default;

};

#endif
