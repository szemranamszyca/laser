#ifndef ICMDPROCESSORMOCK_HPP
#define ICMDPROCESSORMOCK_HPP

#include "gmock/gmock.h"
#include  "../../cmdProcessor/include/ICmdProcessor.hpp"

using namespace emulator::cmdProcessor;

class CmdProcessorMock : public ICmdProcessor {
 public:
  MOCK_METHOD1(process, std::string(const std::string&));
  MOCK_METHOD1(configure, void(std::shared_ptr<emulator::cmdProcessor::ActionReactionMap_t>));
};

#endif /* ICMDPROCESSORMOCK_HPP */