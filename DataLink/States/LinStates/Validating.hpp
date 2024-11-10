#ifndef VALIDATING_H_
#define VALIDATING_H_

#include "interfaces/abstractLinState.hpp"
#include "interfaces/abstractedValidator.hpp"
#include "interfaces/abstractNotifier.hpp"
#include "interfaces/abstractstorageAdabter.hpp"

class Validating : public LinsStates
{
    private:
        Validating(){};
    public:
        void handle() override;
        void set(AbstractedValidator *validator,LinConnection *con ,AbstractStorageAdabter *db);
        static Validating &getInstance()
        {
            static Validating Instance;
            return Instance;
        }
    private:
        LinConnection * mConnection;
        AbstractedValidator * mValidator;
        AbstractStorageAdabter * mdb;
};



#endif
