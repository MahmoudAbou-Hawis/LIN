#include <stdint.h>

enum class LINDataBaseError;

class FrameInfo
{
public:
    virtual LINDataBaseError EditFrame(uint8_t ID, uint8_t* NewValue) = 0;
    virtual LINDataBaseError GetFrame(uint8_t ID, uint8_t * Frame) = 0;
    virtual uint8_t isValidFrame(uint8_t ID) const  = 0;
    virtual uint8_t len(uint8_t ID) const = 0;
};