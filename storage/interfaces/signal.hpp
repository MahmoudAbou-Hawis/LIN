#include <stdint.h>

enum class LINDataBaseError;

class Signal
{
    virtual LINDataBaseError EditSignal(uint8_t ID, char * SignalName  ,uint8_t NewValue) = 0;
    virtual LINDataBaseError GetSignal(uint8_t ID, char * SignalName , uint8_t * Signal) const = 0;
};