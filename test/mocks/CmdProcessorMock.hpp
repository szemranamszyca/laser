#ifndef ICMDPROCESSORMOCK_HPP
#define ICMDPROCESSORMOCK_HPP

#include "gmock/gmock.h"
#include  "../../cmdProcessor/include/ICmdProcessor.hpp"

using namespace laser::cmdProcessor;

class CmdProcessorMock : public ICmdProcessor {
 public:
  MOCK_METHOD1(process, std::string(const std::string&));
  MOCK_METHOD1(configure, void(std::shared_ptr<laser::cmdProcessor::ActionReactionMap_t>));
};

#endif /* ICMDPROCESSORMOCK_HPP */