//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/DomainRandomizer.h>
#include "Domain/WheelsCommand.h"

TEST(WheelsCommand_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::WheelsCommand wheelsCommand;

    EXPECT_EQ(wheelsCommand.leftVel, 0);
    EXPECT_EQ(wheelsCommand.rightVel, 0);
}

TEST(WheelsCommand_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    float leftVel = rand();
    float rightVel = rand();

    vss::WheelsCommand wheelsCommand(leftVel, rightVel);

    EXPECT_EQ(wheelsCommand.leftVel, leftVel);
    EXPECT_EQ(wheelsCommand.rightVel, rightVel);
}

TEST(WheelsCommand_cout, WhenCoutShouldPrintRight){
    auto wheelsCommand = vss::DomainRandomizer::createRandomWheelsCommand();

    testing::internal::CaptureStdout();
    std::cout << wheelsCommand;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;
    mock_output << "WheelsCommand(" << wheelsCommand.leftVel << ", " << wheelsCommand.rightVel << ")";

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}