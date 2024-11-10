#ifndef ABSTRACTSTORAGEADABTER_H_
#define ABSTRACTSTORAGEADABTER_H_


#include "DataLink/frame/header.hpp"
#include "DataLink/frame/response.hpp"



class AbstractStorageAdabter 
{
    public:
    enum class frameStatus {NOTINTERSTED,SENDER,RECEIVER};
    public:
        virtual frameStatus isValid(header & hed) = 0;
        virtual void save(header &hed, response & res) = 0;
        virtual response restore(header& ID) = 0;
        virtual uint8_t responseSize(header &head) = 0;
};


#endif