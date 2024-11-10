#include  "ClassicalValidator.hpp"
#include "utils/checksum.h"

bool ClassicalValidator::isValid(frame& Object)
{
    return (checkSum(Object.res.data,Object.res.len) == Object.checksum);
}

uint8_t ClassicalValidator::getCheckSum(frame &Object)
{
    return checkSum(Object.res.data,Object.res.len);
}
