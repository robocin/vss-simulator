//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/DomainRandomizer.h>
#include <Domain/Constants.h>
#include "Domain/Pose.h"

TEST(Pose_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Pose pose;

    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 0);
    EXPECT_EQ(pose.angle, 0);
}

TEST(Pose_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    float x = rand()%vss::MAX_COORDINATE_X;
    float y = rand()%vss::MAX_COORDINATE_Y;
    float angle = rand()%vss::MAX_ANGLE_VALUE;

    vss::Pose pose(x, y, angle);

    EXPECT_EQ(pose.x, x);
    EXPECT_EQ(pose.y, y);
    EXPECT_EQ(pose.angle, angle);
}

TEST(Pose_cout, WhenCoutShouldPrintRight){
    auto pose = vss::DomainRandomizer::createRandomPose();

    testing::internal::CaptureStdout();
    std::cout << pose;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;
    mock_output << "Pose(" << pose.x << ", " << pose.y << ", " << pose.angle << ")";

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(Pose_minus, ShouldSubtractCorrectly){
    auto first = vss::DomainRandomizer::createRandomPose();
    auto second = vss::DomainRandomizer::createRandomPose();

    auto result = first - second;

    EXPECT_EQ(result.x, first.x - second.x);
    EXPECT_EQ(result.y, first.y - second.y);
    EXPECT_EQ(result.angle, first.angle - second.angle);
}

TEST(Pose_plus, ShouldAddCorrectly){
    auto first = vss::DomainRandomizer::createRandomPose();
    auto second = vss::DomainRandomizer::createRandomPose();

    auto result = first + second;

    EXPECT_EQ(result.x, first.x + second.x);
    EXPECT_EQ(result.y, first.y + second.y);
    EXPECT_EQ(result.angle, first.angle + second.angle);
}

TEST(Pose_equals, ShouldCompareCorrectly){
    auto value = vss::DomainRandomizer::createRandomPose();

    EXPECT_EQ(value, value);
    EXPECT_NE(value, vss::Pose(value.x+1, value.y, value.angle));
    EXPECT_NE(value, vss::Pose(value.x, value.y+1, value.angle));
    EXPECT_NE(value, vss::Pose(value.x, value.y, value.angle+1));
    EXPECT_NE(value, vss::Pose(value.x-1, value.y, value.angle));
    EXPECT_NE(value, vss::Pose(value.x, value.y-1, value.angle));
    EXPECT_NE(value, vss::Pose(value.x, value.y, value.angle-1));
}