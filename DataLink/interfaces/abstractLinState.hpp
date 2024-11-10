#ifndef ABSTRACTSTATE_H_
#define ABSTRACTSTATE_H_

#include "DataLink/frame/frame.hpp"
class LinConnection;

class LinsStates 
{
    public:
        virtual ~LinsStates() = default;
    public:
        virtual void handle() = 0;
    protected:
        inline static frame fre;
};

#endif
