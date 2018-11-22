#include <string>
#include "TestHMI.hpp"

using namespace std;

TestHMI::TestHMI() {}

TestHMI::~TestHMI() {}

void TestHMI::SetUp() {}

void TestHMI::TearDown() {}

TEST_F(TestHMI, ShouldDoNothingIfProcessorIsNotPlugged) 
{
    hmi_.interact();
}
