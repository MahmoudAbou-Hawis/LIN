#include "Validating.hpp"

void Validating::handle()
{
    if(mValidator->isValid(fre))
    {
        mdb->save(fre.head,fre.res);
    } 
    mConnection->getNotifier()->notify(mConnection);
}

void Validating::set(AbstractedValidator *validator, LinConnection *con,AbstractStorageAdabter *db)
{

    mValidator  = validator;
    mConnection = con;
    mdb = db;
}
