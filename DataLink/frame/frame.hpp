#ifndef FRAME_H_
#define FRAME_H_
#include "header.hpp"
#include "response.hpp"
struct frame
{
    header head;
    response res;
    uint8_t checksum;
};


#endif