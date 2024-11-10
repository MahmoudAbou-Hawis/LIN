#ifndef HEADERSERIALIZAER_H_
#define HEADERSERIALIZAER_H_

#include "utils/interfaces/ObjectSerializer.hpp"
#include "DataLink/frame/header.hpp"
#include <stdint.h>
#include <utility>

class HeaderSerializer : public ObjectSerializer<header>
{
    public:
        std::pair<uint8_t *, uint8_t> serialize(const header& object)  override;
    private:
        uint8_t mOut[2];
};

#endif