#include "Lin.hpp"
#include <array>
#include "States/LinStates/Init.hpp"
#include "Notifiers/LinNotifier.hpp"
#include "States/LinStates/ReceivingBreak.hpp"
#include "States/LinStates/Validating.hpp"
#include "States/LinStates/DispatchingAndHandling.hpp"
#include "States/LinStates/ReceivingHeader.hpp"
#include "interfaces/abstractedValidator.hpp"
#include "States/LinStates/SendingBreak.hpp"
#include "States/LinStates/SendingHeader.hpp"
#include "States/LinStates/Master.hpp"
Lin::Lin(AbstractStorageAdabter *db,AbstractTranspoertAdabter *ta) :handler(db,ta,&valid,&connection) , connection(&Init::getInstance(),&RNotifier::getInstance())
{
    std::array<AbstracterdConnectionHandler *, NUMBER_LIN_HANDLERS> handlers= {&handler};
    dispatcher.set(handlers,ta,&connection);
    Init::getInstance().set(&connection,ta);
#if NODE_TYPE == SLAVE
    ReceivingBreak::getInstance().set(ta,&connection);
    ReceivingHeader::getInstance().set(ta,&connection);
#elif NODE_TYPE == MASTER
    Master::getInstance().set(&connection);
    SendingHeader::getInstance().set(&connection, ta);
    SendingBreak::getInstance().set(&connection, ta);
#endif
    DispatchingAndHandling::getInstance().set(&dispatcher,&connection,ta);
    Validating::getInstance().set(&valid,&connection,db);
}

void Lin::start() {
    connection.request();
}

#if NODE_TYPE == MASTER
void Lin::run(uint32_t time) {
    Master::getInstance().set(time);
    connection.setState(Master::getInstance());
    connection.request();
}

#endif
