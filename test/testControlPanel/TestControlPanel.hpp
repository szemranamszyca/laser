#ifndef TESTCONTROLPANEL_HPP
#define TESTCONTROLPANEL_HPP


#include "gtest/gtest.h"
#include "../../controlPanel/include/ControlPanel.hpp"
#include "../mocks/CmdProcessorMock.hpp"
#include "../mocks/HMIMock.hpp"

class TestControlPanel : public ::testing::Test {

protected:
    TestControlPanel();
    virtual ~TestControlPanel();

    virtual void SetUp();
    virtual void TearDown();

    std::unique_ptr<::testing::StrictMock<HMIMock>> hmiMock_ 
        = std::make_unique<::testing::StrictMock<HMIMock>>();

    std::unique_ptr<::testing::StrictMock<CmdProcessorMock>> cmdProcessorMock_ 
        = std::make_unique<::testing::StrictMock<CmdProcessorMock>>();

    HMIMock* hmiMockPtr_ = hmiMock_.get();
    CmdProcessorMock* cmdProcessorPtr_ = cmdProcessorMock_.get();

    laser::controlPanel::ControlPanel controlPanel_;
        
        
};

#endif /* TESTCONTROLPANEL_HPP */