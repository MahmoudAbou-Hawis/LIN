#include "headerdeserializer.hpp"

header HeaderDeserializer::deserialize(uint8_t* data,uint8_t len)
{
    header a;
    a.msgID = data[1];
    a.sync = data[0];
    return a;
}