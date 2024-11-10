
struct FrameData;
enum class LINDataBaseError;
#include "LinConf.h"

#include "Lindb.hpp"

extern  FrameData data[DATA_LEN];

class LINDataBase : public LinDb
{
    private:
        FrameData * pFramesData = data;
    public:    
        LINDataBase();
        LINDataBaseError EditFrame(uint8_t ID, uint8_t* NewValue) override;
        LINDataBaseError GetFrame(uint8_t ID, uint8_t * Frame) override;
        uint8_t isValidFrame(uint8_t ID) const override;
        LINDataBaseError EditSignal(uint8_t ID, char * SignalName  ,uint8_t NewValue) override;
        LINDataBaseError GetSignal(uint8_t ID, char * SignalName , uint8_t * Signal) const override;
        uint8_t len(uint8_t ID) const override;
};
