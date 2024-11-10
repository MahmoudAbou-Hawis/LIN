#ifndef INHANCEDVALIDATOR_H_
#define INHANCEDVALIDATOR_H_

#include "DataLink/interfaces/abstractedValidator.hpp"
#include "DataLink/frame/frame.hpp"

class InhancedValidator : AbstractedValidator
{
    public:
        InhancedValidator(){};
        bool isValid( frame & Object) override;
        uint8_t getCheckSum(frame & Object) override;
};
#endif
