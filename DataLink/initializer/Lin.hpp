#ifndef LIN_H_
#define LIN_H_

#include "communication/LinConnectionHandler.hpp"
#include "communication/LinFrameDespatcher.hpp"
#include "States/LinStates/LinConnection.hpp"
#include "validators/ClassicalValidator.hpp"
#include "validators/InhancedValidator.hpp"

class Lin
{
    public:
        Lin(AbstractStorageAdabter *db,AbstractTranspoertAdabter *ta) ;
        void start();
        void run(uint32_t time);
    private:
        LinConnectionHandler handler;
        FrameDespatcher dispatcher;
        LinConnection connection;
#if CHECKSUM == CLASSICAL
        ClassicalValidator valid;
#elif CHECKSUM == INHANCED
        InhancedValidator valid;
#endif


};

#endif
