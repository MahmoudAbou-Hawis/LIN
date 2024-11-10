#ifndef ABSTRACTEDCONNECTIONHANDLER_H_
#define ABSTRACTEDCONNECTIONHANDLER_H_
#include "DataLink/frame/frame.hpp"
#include "DataLink/frame/response.hpp"


class AbstracterdConnectionHandler
{
    public:
        virtual void handle(frame & head) = 0;
        virtual bool CanYouHandle(header &head) = 0;
    public:
        virtual ~AbstracterdConnectionHandler() =default;
};

#endif
