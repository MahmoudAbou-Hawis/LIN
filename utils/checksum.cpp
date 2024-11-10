#include "checksum.h"


uint8_t checkSum(uint8_t * ptr, uint8_t len)
{
    uint16_t result = 0;
    for(uint8_t i = 0 ; i < len ;i++)
    {
        result += ptr[i];
        result = (result >> 8) +  (result & static_cast<uint8_t>(255));
    }
    return ~((uint8_t)(result));
}