//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/DomainRandomizer.h>
#include <Domain/Constants.h>
#include "Domain/Robot.h"

TEST(Robot_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Robot robot;

    EXPECT_EQ(robot.x, 0);
    EXPECT_EQ(robot.y, 0);
    EXPECT_EQ(robot.angle, 0);
    EXPECT_EQ(robot.speedX, 0);
    EXPECT_EQ(robot.speedY, 0);
    EXPECT_EQ(robot.speedAngle, 0);
}

TEST(Robot_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    float x = rand()%vss::MAX_COORDINATE_X;
    float y = rand()%vss::MAX_COORDINATE_Y;
    float angle = rand()%vss::MAX_ANGLE_VALUE;
    float speedX = rand();
    float speedY = rand();
    float speedAngle = rand();


    vss::Robot robot(x, y, angle, speedX, speedY, speedAngle);

    EXPECT_EQ(robot.x, x);
    EXPECT_EQ(robot.y, y);
    EXPECT_EQ(robot.angle, angle);
    EXPECT_EQ(robot.speedX, speedX);
    EXPECT_EQ(robot.speedY, speedY);
    EXPECT_EQ(robot.speedAngle, speedAngle);
}

TEST(Robot_cout, WhenCoutShouldPrintRight){
    auto robot = vss::DomainRandomizer::createRandomRobot();

    testing::internal::CaptureStdout();
    std::cout << robot;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;
    mock_output << "Robot(" << robot.x << ", " << robot.y << ", " << robot.angle << ", " << robot.speedX << ", " << robot.speedY << ", " << robot.speedAngle << ")";

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(Robot_minus, ShouldSubtractCorrectly){
    auto first = vss::DomainRandomizer::createRandomRobot();
    auto second = vss::DomainRandomizer::createRandomRobot();

    auto result = first - second;

    EXPECT_EQ(result.x, first.x - second.x);
    EXPECT_EQ(result.y, first.y - second.y);
    EXPECT_EQ(result.angle, first.angle - second.angle);
    EXPECT_EQ(result.speedX, first.speedX - second.speedX);
    EXPECT_EQ(result.speedY, first.speedY - second.speedY);
    EXPECT_EQ(result.speedAngle, first.speedAngle - second.speedAngle);
}

TEST(Robot_plus, ShouldAddCorrectly){
    auto first = vss::DomainRandomizer::createRandomRobot();
    auto second = vss::DomainRandomizer::createRandomRobot();

    auto result = first + second;

    EXPECT_EQ(result.x, first.x + second.x);
    EXPECT_EQ(result.y, first.y + second.y);
    EXPECT_EQ(result.angle, first.angle + second.angle);
    EXPECT_EQ(result.speedX, first.speedX + second.speedX);
    EXPECT_EQ(result.speedY, first.speedY + second.speedY);
    EXPECT_EQ(result.speedAngle, first.speedAngle + second.speedAngle);
}

TEST(Robot_equals, ShouldCompareCorrectly){
    auto value = vss::DomainRandomizer::createRandomRobot();

    EXPECT_EQ(value, value);
    EXPECT_NE(value, vss::Robot(value.x+1, value.y, value.angle, value.speedX, value.speedY, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y+1, value.angle, value.speedX, value.speedY, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y, value.angle+1, value.speedX, value.speedY, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y, value.angle, value.speedX+1, value.speedY, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y, value.angle, value.speedX, value.speedY+1, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y, value.angle, value.speedX, value.speedY, value.speedAngle+1));
    EXPECT_NE(value, vss::Robot(value.x-1, value.y, value.angle, value.speedX, value.speedY, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y-1, value.angle, value.speedX, value.speedY, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y, value.angle-1, value.speedX, value.speedY, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y, value.angle, value.speedX-1, value.speedY, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y, value.angle, value.speedX, value.speedY-1, value.speedAngle));
    EXPECT_NE(value, vss::Robot(value.x, value.y, value.angle, value.speedX, value.speedY, value.speedAngle-1));
}