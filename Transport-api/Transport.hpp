#ifndef ABSTRACTEDTRANSPORT_H_
#define ABSTRACTEDTRANSPORT_H_


#include <stdint.h>


enum class TransportErrorCode;

class AbstractedTransport
{
    public:
        virtual TransportErrorCode Init() = 0;
        virtual TransportErrorCode send(uint8_t * data, uint8_t len) = 0;
        virtual TransportErrorCode receive(uint8_t * data , uint8_t len) = 0;
        virtual TransportErrorCode SendBreak () = 0;
        virtual TransportErrorCode sleep() = 0;
        virtual TransportErrorCode RegisterRxCallBack(void (*CB)(void *),void *arg)    = 0;
        virtual TransportErrorCode RegisterTxCallBack(void (*CB)(void *),void *arg)    = 0;
        virtual TransportErrorCode RegisterBreakCallBack(void (*CB)(void *),void *arg) = 0;
        virtual TransportErrorCode UnRegisterRxCallBack()    = 0;
        virtual TransportErrorCode UnRegisterTxCallBack()    = 0;
        virtual TransportErrorCode UnRegisterBreakCallBack() = 0;
        virtual void receiveByte(uint8_t * byte) = 0;
        virtual void disableTx() = 0;
        virtual void disableRx() = 0;
        virtual void sendByte(uint8_t  data) = 0;
        virtual ~AbstractedTransport() = default;
};

#endif
