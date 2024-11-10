#ifndef RESPONSEDESERIALIZER_H_
#define RESPONSEDESERIALIZER_H_

#include "utils/interfaces/ObjectDeserlizer.hpp"
#include "frame/response.hpp"

class ResponseDeserializer : public ObjectDeserializer<response>
{
    public:
        response deserialize(uint8_t * data,uint8_t len) override;
};

#endif