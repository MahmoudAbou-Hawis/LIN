#ifndef HEADER_H_
#define HEADER_H_

#include <stdint.h>

struct header
{
    uint8_t sync ;
    uint8_t msgID;
};

#endif
