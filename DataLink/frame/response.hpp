#ifndef RESPONSE_H_
#define RESPONSE_H_

#include <stdint.h>
#include <array>

struct response
{
    uint8_t data[8];
    uint8_t len;
};

#endif
