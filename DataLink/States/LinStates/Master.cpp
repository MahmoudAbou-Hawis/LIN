#include "Master.hpp"

extern std::pair<uint32_t , uint8_t> IDs[NUMBER_OF_IDS];

void Master::handle()
{
    for(uint8_t cnt = 0 ; cnt < NUMBER_OF_IDS ; cnt++)
    {
        if(time % IDs[cnt].first == 0)
        {
            fre.head.sync = 0x55;
            fre.head.msgID = IDs[cnt].second;
            mConnection->getNotifier()->notify(mConnection);
        }
    }
}
void  Master::set( uint32_t currentTime)
{

    time = currentTime;
}
void  Master::set(LinConnection * Connection)
{
    mConnection = Connection;
}
