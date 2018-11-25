#include <string>
#include "TestCmdProcessor.hpp"

TestCmdProcessor::TestCmdProcessor() {}
TestCmdProcessor::~TestCmdProcessor() {}

using namespace emulator::cmdProcessor;

void TestCmdProcessor::SetUp() {
    actionReactionMapStub_ = std::make_shared<ActionReactionMap_t>();
    auto reactionStub = [](Params& param){
        if (param.size() == 0)
            return true;
        else
            return false;
    };
    actionReactionMapStub_->insert(std::make_pair("StartEmission", reactionStub));
    actionReactionMapStub_->insert(std::make_pair("SetPower", reactionStub));
}

void TestCmdProcessor::TearDown() {}

TEST_F(TestCmdProcessor, ShouldReturnUKIfWasNotConfigured) 
{
    std::string result = cmdProcessor_.process("STR");
    ASSERT_EQ("UK!", result);
}

TEST_F(TestCmdProcessor, ShouldReturnUKIfCmdIsUnknown) 
{
    std::string result = cmdProcessor_.process("AAA");
    ASSERT_EQ("UK!", result);
}

TEST_F(TestCmdProcessor, ShouldEnterAndExitSillyMode) 
{
    cmdProcessor_.configure(actionReactionMapStub_);
    std::string result = cmdProcessor_.process("ESM");
    ASSERT_EQ("ESM#", result);

    result = cmdProcessor_.process("ST?");
    ASSERT_EQ("UK!", result);

    result = cmdProcessor_.process("MSD");
    ASSERT_EQ("DSM#", result);
}

TEST_F(TestCmdProcessor, ShouldReturnUKIfValidationNotPassed) 
{
    cmdProcessor_.configure(actionReactionMapStub_);
    std::string result = cmdProcessor_.process("PW=|34|65");
    ASSERT_EQ("UK!", result);
}

TEST_F(TestCmdProcessor, ShouldReturnPWWithParameterNotEmissing) 
{
    cmdProcessor_.configure(actionReactionMapStub_);
    std::string result = cmdProcessor_.process("PW=|34");
    ASSERT_EQ("PW=|34!", result);
}





