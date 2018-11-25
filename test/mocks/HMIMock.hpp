#ifndef IHMIMOCK_HPP
#define IHMIMOCK_HPP

#include "gmock/gmock.h"
#include  "../../HMI/include/IHMI.hpp"

using namespace emulator::HMI;

class HMIMock : public IHMI {
 public:
  MOCK_CONST_METHOD0(interact, void());
  MOCK_METHOD1(plugProcessor, void(const processorFunction&));
};

#endif /* IHMIMOCK_HPP */