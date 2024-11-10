#include "LinNotifier.hpp"
#include "States/LinStates/DispatchingAndHandling.hpp"
#include "States/LinStates/ReceivingBreak.hpp"
#include "States/LinStates/ReceivingHeader.hpp"
#include "States/LinStates/Validating.hpp"
#include "States/LinStates/Init.hpp"
#include "States/LinStates/SendingBreak.hpp"
#include "States/LinStates/SendingHeader.hpp"
#include "States/LinStates/Master.hpp"

#include "LinConf.h"

void RNotifier::notify(LinConnection *s)
{
    if(s->CurrentState == &ReceivingBreak::getInstance())
    {
        s->setState(ReceivingHeader::getInstance());
        s->request();
    }
    else if(s->CurrentState == &ReceivingHeader::getInstance())
    {
        s->setState(DispatchingAndHandling::getInstance());
        s->request();
    }
    else if(s->CurrentState == &DispatchingAndHandling::getInstance())
    {

        #if NODE_TYPE == SLAVE
            s->setState(Validating::getInstance());
            s->request();
        #endif
    }
    else if(s->CurrentState == &Validating::getInstance())
    {
        s->setState(ReceivingBreak::getInstance());
        s->request();
    }
    else if(s->CurrentState == &Init::getInstance())
    {
        #if NODE_TYPE == SLAVE
        s->setState(ReceivingBreak::getInstance());
        s->request();
        #endif
    }
    else if(s->CurrentState == &SendingBreak::getInstance())
    {
        s->setState(SendingHeader::getInstance());
        s->request();
    }
    else if(s->CurrentState == &SendingHeader::getInstance())
    {
          s->setState(DispatchingAndHandling::getInstance());
          s->request();
    }
    else if(s->CurrentState == &Master::getInstance())
    {
        s->setState(SendingBreak::getInstance());
        s->request();
    }
}
