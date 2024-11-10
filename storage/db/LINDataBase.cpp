#include "LINDataBase.hpp"
#include "dbErrors.hpp"
#include "LinConf.h"
#include "db.hpp"
#include <cstring>

LINDataBase::LINDataBase()
{
}

LINDataBaseError LINDataBase::EditFrame(uint8_t ID, uint8_t *NewValue)
{
    for(uint8_t it = 0 ; it < DATA_LEN ; it++)
    {
        if(pFramesData[it].ID == ID)
        {
            for(uint8_t i = 0 ; i < pFramesData[it].len ; i++)
            {
                pFramesData[it].data[i] = NewValue[i];
            }
            return LINDataBaseError::OK;
        }
    }
    return LINDataBaseError::NOTFOUND;
}

LINDataBaseError LINDataBase::GetFrame(uint8_t ID, uint8_t *Frame)
{
    for(uint8_t it = 0 ; it < DATA_LEN ; it++)
    {
        if(pFramesData[it].ID == ID)
        {
            for(uint8_t i = 0 ; i < pFramesData[it].len ; i++)
            {
                Frame[i] = pFramesData[it].data[i];
            }
            return LINDataBaseError::OK;
        }
    }
    return LINDataBaseError::NOTFOUND;
}

uint8_t LINDataBase::isValidFrame(uint8_t ID) const
{
    for(uint8_t it = 0 ; it < DATA_LEN ; it++)
    {
        if(pFramesData[it].ID == ID)
        {
            if(pFramesData[it].need == 1)
            {
                return 1;
            }
            return 2;
        }
    }
    return 0;
}

LINDataBaseError LINDataBase::EditSignal(uint8_t ID, char *SignalName, uint8_t NewValue)
{
    for(uint8_t it = 0 ; it < DATA_LEN ; it++)
    {
        if(pFramesData[it].ID == ID)
        {
            for(uint8_t i = 0 ; i <pFramesData[it].numberOfisgnals ;i++)
            {
                if(strcmp(SignalName, pFramesData[it].signals[i].name) == 0)
                {
                    uint8_t byte = pFramesData[it].data[pFramesData[it].signals[i].start/8];
                    uint8_t copy = byte;
                    copy >>= (pFramesData[it].signals[i].start%8);
                    copy <<= (8 - pFramesData[it].signals[i].len);
                    copy >>= (8 - pFramesData[it].signals[i].len);
                    copy <<= (pFramesData[it].signals[i].start%8);
                    byte &=~copy;
                    byte |= (NewValue << (pFramesData[it].signals[i].start%8));
                    pFramesData[it].data[pFramesData[it].signals[i].start/8] = byte;
                    return LINDataBaseError::OK;
                } 
            }
        }
    }
    return LINDataBaseError::NOTFOUND;
}

LINDataBaseError LINDataBase::GetSignal(uint8_t ID, char *SignalName, uint8_t *Signal) const
{
    for(uint8_t it = 0 ; it < DATA_LEN ; it++)
    {
        if(pFramesData[it].ID == ID)
        {
            for(uint8_t i = 0 ; i <pFramesData[it].numberOfisgnals ;i++)
            {
                if(strcmp(SignalName, pFramesData[it].signals[i].name) == 0)
                {
                    uint8_t byte = pFramesData[it].data[pFramesData[it].signals[i].start/8];
                    byte >>= pFramesData[it].signals[i].start;
                    byte <<= (8 - pFramesData[it].signals[i].len);
                    byte >>= (8 - pFramesData[it].signals[i].len);
                    *Signal = byte;
                    return LINDataBaseError::OK;
                } 
            }
        }
    }
    return LINDataBaseError::NOTFOUND;
}

uint8_t LINDataBase::len(uint8_t ID) const
{
    for(uint8_t it = 0 ; it < DATA_LEN ; it++)
    {
        if(pFramesData[it].ID == ID)
        {
            return pFramesData[it].len;
        }
    }
    return -1;
}
