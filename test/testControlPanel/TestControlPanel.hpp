#ifndef TESTCONTROLPANEL_HPP
#define TESTCONTROLPANEL_HPP


#include "gtest/gtest.h"
#include "../../controlPanel/include/ControlPanel.hpp"
#include "../mocks/CmdProcessorMock.hpp"
#include "../mocks/HMIMock.hpp"

// The fixture for testing class Foo.
class TestControlPanel : public ::testing::Test {

protected:

    // You can do set-up work for each test here.
    TestControlPanel();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~TestControlPanel();

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor (right
    // before each test).
    virtual void SetUp();

    // Code here will be called immediately after each test (right
    // before the destructor).
    virtual void TearDown();

    // auto hmiMock_ = std::make_unique<StrictMock<HMIMock>>();
    // auto cmdProcessorMock_ = std::make_unique<StrictMock<CmdProcessorMock>>()

    laser::controlPanel::ControlPanel controlPanel_;
        
        
};

#endif /* TESTCONTROLPANEL_HPP */