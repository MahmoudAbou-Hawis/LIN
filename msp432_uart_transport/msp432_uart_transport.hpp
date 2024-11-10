#ifndef UARTSTM32_H_
#define UARTSTM32_H_

#include "Transport-api/Transport.hpp"


struct CallBacks
{
    void (*CB)(void *);
    void * args;
};

#define TX_IDX          0
#define RX_IDX          1
#define BREAK_IDX       2

class UartTransport : public AbstractedTransport
{
    public:
        UartTransport(){};
        TransportErrorCode Init() override;
        TransportErrorCode send(uint8_t * data, uint8_t len) override;
        TransportErrorCode receive(uint8_t * data , uint8_t len) override;
        TransportErrorCode SendBreak () override;
        TransportErrorCode sleep() override;
        TransportErrorCode RegisterRxCallBack(void (*CB)(void *),void *arg)    override;
        TransportErrorCode RegisterTxCallBack(void (*CB)(void *),void *arg)    override;
        TransportErrorCode RegisterBreakCallBack(void (*CB)(void *),void *arg) override;
        TransportErrorCode UnRegisterRxCallBack()    override;
        TransportErrorCode UnRegisterTxCallBack()    override;
        TransportErrorCode UnRegisterBreakCallBack() override;
        void disableRx()override;
        void disableTx()override;
        void receiveByte(uint8_t * byte)  override;
        void sendByte(uint8_t  data) override;
        ~UartTransport(){};



};


#endif
