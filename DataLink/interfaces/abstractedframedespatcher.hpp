#ifndef ABSTRACTEDFRAMEDDISPATCHER_H_
#define ABSTRACTEDFRAMEDDISPATCHER_H_

#include "DataLink/frame/frame.hpp"

class AbstractedFramedDispatcher
{
    public:
        virtual void dispatch(frame &head) = 0;
    public:
        virtual ~AbstractedFramedDispatcher() = default;
};

#endif
