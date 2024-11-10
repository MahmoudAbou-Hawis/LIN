#ifndef OBJECTSERIALIZER_H
#define OBJECTSERIALIZER_H

#include <utility>
#include <stdint.h>
template <typename T>
class ObjectSerializer {
 public:
  virtual ~ObjectSerializer() = default;
  virtual std::pair<uint8_t *, uint8_t> serialize(const T& object)  = 0;
};

#endif  
