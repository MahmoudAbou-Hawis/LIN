#ifndef DBADABTER_H_
#define DBADABTER_H_

#include "DataLink/interfaces/abstractstorageAdabter.hpp"
#include "storage/db/Lindb.hpp"
class DbAdabter : public AbstractStorageAdabter 
{
    public:
        DbAdabter(LinDb * db);
        frameStatus isValid(header & hed) override;
        void save(header &hed,response & res) override;
        response restore(header &hed) override;
        uint8_t responseSize(header &head) override;
    private:
        LinDb * mDb{nullptr};
};

#endif