#include "headerserializer.hpp"
#include <cstring>
std::pair<uint8_t *, uint8_t> HeaderSerializer::serialize(const header &head)
{
    memcpy(mOut,&head,sizeof(mOut));
    return {mOut,2};
}