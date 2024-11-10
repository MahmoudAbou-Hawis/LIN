#ifndef RESPONSESERIALIZAER_H_
#define RESPONSESERIALIZAER_H_

#include "utils/interfaces/ObjectSerializer.hpp"
#include "frame/response.hpp"
#include <stdint.h>
#include <utility>

class ResponseSerializer : public ObjectSerializer<response>
{
    public:
        std::pair<uint8_t *, uint8_t> serialize(const response& object)  override;
    private:
        uint8_t mOut[8];
};

#endif