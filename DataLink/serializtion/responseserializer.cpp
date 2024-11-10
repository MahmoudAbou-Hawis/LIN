#include "responseserializer.hpp"
#include <cstring>

std::pair<uint8_t *, uint8_t> ResponseSerializer::serialize(const response& object)  
{
    memcpy(mOut,&object,object.len);
    return {mOut,object.len};
}
