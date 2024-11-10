#ifndef CLASSICALVALIDATOR_H_
#define CLASSICALVALIDATOR_H_

#include "DataLink/interfaces/abstractedValidator.hpp"
#include "DataLink/frame/frame.hpp"

class ClassicalValidator : public AbstractedValidator
{
    public:
        ClassicalValidator(){};
        bool isValid(frame & Object) override;
        uint8_t getCheckSum(frame & Object) override;

};
#endif
