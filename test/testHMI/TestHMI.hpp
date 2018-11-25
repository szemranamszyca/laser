#include "gtest/gtest.h"
#include "../../HMI/include/HMI.hpp"

// The fixture for testing class Foo.
class TestHMI : public ::testing::Test {

protected:
    // You can do set-up work for each test here.
    TestHMI();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~TestHMI();

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor (right
    // before each test).
    virtual void SetUp();

    // Code here will be called immediately after each test (right
    // before the destructor).
    virtual void TearDown();

    emulator::HMI::HMI hmi_;
};
