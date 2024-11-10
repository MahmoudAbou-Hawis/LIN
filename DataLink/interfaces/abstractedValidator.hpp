#ifndef ABSTRACTEDVALIDATOR_H_
#define ABSTRACTEDVALIDATOR_H_

#include "DataLink/frame/frame.hpp"
class AbstractedValidator
{
    public:
        AbstractedValidator() = default;
        virtual bool isValid(frame & Object) = 0;
        virtual uint8_t getCheckSum(frame & Object) = 0;
        virtual ~AbstractedValidator() = default;
};

#endif 
