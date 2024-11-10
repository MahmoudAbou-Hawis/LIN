#ifndef HEADERDESERIALIZER_H_
#define HEADERDESERIALIZER_H_

#include "utils/interfaces/ObjectDeserlizer.hpp"
#include "DataLink/frame/header.hpp"

class HeaderDeserializer : public ObjectDeserializer<header>
{
    public:
        header deserialize(uint8_t * data, uint8_t len) override;
};

#endif