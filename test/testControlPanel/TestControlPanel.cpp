#include <string>
#include "TestControlPanel.hpp"

using namespace std;
using ::testing::StrictMock;

TestControlPanel::TestControlPanel() : 
    controlPanel_(std::make_unique<StrictMock<HMIMock>>(),
        std::make_unique<StrictMock<CmdProcessorMock>>())
{
}

TestControlPanel::~TestControlPanel() {}

void TestControlPanel::SetUp() {}

void TestControlPanel::TearDown() {}

TEST_F(TestControlPanel, ShouldCallHMIandCmdProcessorWhenConfigureInvoked) {

    controlPanel_.configure();
    ASSERT_TRUE(true);
}
