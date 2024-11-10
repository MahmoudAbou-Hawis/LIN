#ifndef DB_H_
#define DB_H_

#include "stdint.h"

struct signal
{
    uint8_t start;
    uint8_t len;
    char name[8];
};

struct FrameData
{
    uint8_t len;
    bool updated{0};
    char type[8];
    uint8_t ID;
    uint8_t data[8];
    uint8_t need;
    signal signals[64];
    uint8_t numberOfisgnals;
};
#endif