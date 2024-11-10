#include "dbadabter.hpp"
#include "DataLink/serializtion/responsedeserializer.hpp"

DbAdabter::DbAdabter(LinDb * db)
{
    mDb = db;
}


DbAdabter::frameStatus DbAdabter::isValid(header & hed)
{
   switch(mDb->isValidFrame(hed.msgID))
   {
    case 0:
        return DbAdabter::frameStatus::NOTINTERSTED;
    case 1:
        return DbAdabter::frameStatus::SENDER;
    case 2:
        return DbAdabter::frameStatus::RECEIVER;
   }
}

void DbAdabter::save(header &hed,response & res)
{
    mDb->EditFrame(hed.msgID,res.data);
}


response DbAdabter::restore(header &hed)
{
    uint8_t arr[8];
    mDb->GetFrame(hed.msgID,arr);
    return ResponseDeserializer().deserialize(arr,mDb->len(hed.msgID));
}

uint8_t DbAdabter::responseSize(header &head)
{
    return mDb->len(head.msgID & 0X3F);
}
