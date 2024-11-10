#ifndef OBJECTDESERIALIZER_H
#define OBJECTDESERIALIZER_H
#include <stdint.h>
#include <utility>
template <typename T>
class ObjectDeserializer {
 public:
  virtual ~ObjectDeserializer()= default ;
  virtual T deserialize(uint8_t * data, uint8_t len)= 0;
};
#endif  
