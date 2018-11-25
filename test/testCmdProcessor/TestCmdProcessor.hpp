#ifndef TESTCMDPROCESSOR_HPP
#define TESTCMDPROCESSOR_HPP


#include "gtest/gtest.h"
#include "../../cmdProcessor/include/CmdProcessor.hpp"


class TestCmdProcessor : public ::testing::Test {

protected:
    TestCmdProcessor();
    virtual ~TestCmdProcessor();

    virtual void SetUp();
    virtual void TearDown();

    emulator::cmdProcessor::CmdProcessor cmdProcessor_;  
    std::shared_ptr<emulator::cmdProcessor::ActionReactionMap_t> actionReactionMapStub_;    
};

#endif /* TESTCMDPROCESSOR_HPP */
