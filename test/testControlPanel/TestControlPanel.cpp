#include <string>
#include "TestControlPanel.hpp"


using ::testing::_;

TestControlPanel::TestControlPanel() : 
    controlPanel_(move(hmiMock_), std::move(cmdProcessorMock_))
{
}

TestControlPanel::~TestControlPanel() {}

void TestControlPanel::SetUp() {}

void TestControlPanel::TearDown() {}

TEST_F(TestControlPanel, ShouldCallHMIandCmdProcessorWhenConfigureInvoked) 
{
    EXPECT_CALL(*hmiMockPtr_, plugProcessor(_));
    EXPECT_CALL(*cmdProcessorPtr_, configure(_));

    controlPanel_.configure();
}

TEST_F(TestControlPanel, ShouldStartHMIInteractWhenStartInvoked) 
{
    EXPECT_CALL(*hmiMockPtr_, interact());

    controlPanel_.start();
}
