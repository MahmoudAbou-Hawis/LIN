#include "LinConnectionHandler.hpp"
#include "States/LinStates/ReceivingBreak.hpp"
void LinConnectionHandler::handle(frame &fme)
{
    fme.res.len =  mDatabase->responseSize(fme.head);
    if(mDatabase->isValid(fme.head) == AbstractStorageAdabter::frameStatus::RECEIVER)
    {
        mTransport->receive(fme.res);
        mTransport->receive(&fme.checksum);
    }
    else
    {
     //   for(uint8_t i = 0 ; i < 3000;i++);
        fme.res = mDatabase->restore(fme.head);
        mTransport->send(fme.res);
        mTransport->send(mValidator->getCheckSum(fme));
        mConnection->setState(ReceivingBreak::getInstance());
        mConnection->request();

    }
}
bool LinConnectionHandler::CanYouHandle(header &head)
{
    return (mDatabase->isValid(head) != AbstractStorageAdabter::frameStatus::NOTINTERSTED);
}


