#include "transportadabter.hpp"
#include "DataLink/serializtion/headerserializer.hpp"
#include "DataLink/serializtion/responseserializer.hpp"
#include "LinConf.h"

TransportAdapter::TransportAdapter(AbstractedTransport * trans)
{
    mTrans = trans;
}


void TransportAdapter::Init()
{
    mTrans->Init();
}


void TransportAdapter::send(header &hed)
{
    auto data = HeaderSerializer().serialize(hed);
    mTrans->send(data.first,data.second);
}

void TransportAdapter::send(response &res)
{
    auto data = ResponseSerializer().serialize(res);
    mTrans->send(data.first,data.second);
}

void TransportAdapter::send()
{
    mTrans->SendBreak();
}


void TransportAdapter::receive(response &res)
{
    mTrans->receive(res.data,res.len);
}

void TransportAdapter::receive(header &hed)
{
    mTrans->receive(reinterpret_cast<uint8_t*>(&hed),2);
}

void TransportAdapter::setTxHandler(void (*callback)(void *), void* arg) 
{
    mTrans->RegisterTxCallBack(callback,arg);
}
void TransportAdapter::setRxHandler(void (*callback)(void *), void* arg) 
{
    mTrans->RegisterRxCallBack(callback,arg);
}
void TransportAdapter::setBreakingHandler(void (*callback)(void*) , void* arg) 
{
    mTrans->RegisterBreakCallBack(callback,arg);
}

void TransportAdapter::DisableRx()
{
    mTrans->disableRx();
}
void TransportAdapter::DisableTx()
{
    mTrans->disableTx();
}

void TransportAdapter::send(uint8_t byte)
{
    mTrans->sendByte(byte);
}

void TransportAdapter::receive(uint8_t * data)
{
     mTrans->receiveByte(data);
}
