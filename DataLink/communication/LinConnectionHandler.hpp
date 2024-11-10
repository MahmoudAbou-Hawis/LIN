#ifndef LINCONNECTIONHANDLER_H_
#define LINCONNECTIONHANDLER_H_

#include "DataLink/interfaces/abstractedconnectionhandler.hpp"
#include "DataLink/interfaces/abstractedValidator.hpp"
#include "interfaces/abstractstorageAdabter.hpp"
#include "interfaces/abstracttransportadabter.hpp"
#include "interfaces/abstractedValidator.hpp"
#include "States/LinStates/LinConnection.hpp"

class LinConnectionHandler : public AbstracterdConnectionHandler
{
    public: 
        LinConnectionHandler(AbstractStorageAdabter *db,
                             AbstractTranspoertAdabter *ta,
                             AbstractedValidator * validator,
                             LinConnection * connection):
                             mDatabase(db),mTransport(ta), mValidator(validator), mConnection(connection) {};
    public:
        void handle(frame & fme) override;
        bool CanYouHandle(header &head) override;
    private:
        AbstractStorageAdabter * mDatabase;
        AbstractTranspoertAdabter * mTransport;
        AbstractedValidator * mValidator;
        LinConnection * mConnection;
        frame *mFrame;
};

#endif
