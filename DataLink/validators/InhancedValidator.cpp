#include "InhancedValidator.hpp"
#include "utils/checksum.h"

bool InhancedValidator::isValid(frame &Object)
{
    uint8_t arr[9] = {Object.head.msgID};
    for(uint8_t i = 1 ; i < Object.res.len ; i++)
    {
        arr[i] = Object.res.data[i];
    }
    uint8_t result = checkSum(arr,1+Object.res.len);
    return (result == Object.checksum);
}

uint8_t InhancedValidator::getCheckSum(frame & Object)
{
    uint8_t arr[9] = {Object.head.msgID};
    for(uint8_t i = 1 ; i < Object.res.len ; i++)
    {
        arr[i] = Object.res.data[i];
    }
    uint8_t result = checkSum(arr,1+Object.res.len);
    return (result);
}
