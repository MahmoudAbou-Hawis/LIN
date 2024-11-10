#include "responsedeserializer.hpp"

response ResponseDeserializer::deserialize(uint8_t* data, uint8_t len)
{
    response res;
    for(uint8_t i = 0 ; i < len ; i++)
    {
        res.data[i] = data[i];
    }
    res.len = len;
    return res;
}