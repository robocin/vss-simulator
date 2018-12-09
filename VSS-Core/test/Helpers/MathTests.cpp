//
// Created by johnathan on 31/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/DomainRandomizer.h>
#include <Helpers/Math.h>
#include <cmath>

TEST(Math_distance, ShouldCalcDistanceBetweenPoints){
    srand(static_cast<unsigned int>(time(NULL)));

    int r = rand();
    auto point_1 = vss::Point(r, 0);
    auto point_2 = vss::Point(0, 0);

    auto distance = vss::Math::distance(point_1, point_2);

    EXPECT_EQ(distance, r);
}

TEST(Math_distance, ShouldCalcDistanceBetweenPointAndPose){
    srand(static_cast<unsigned int>(time(NULL)));

    int r = rand();
    auto point_1 = vss::Point(r, 0);
    auto pose_1 = vss::Pose(0, 0, 0);

    auto distance = vss::Math::distance(point_1, pose_1);

    EXPECT_EQ(distance, r);
}

TEST(Math_distance, ShouldCalcDistanceBetweenPointAndBall){
    srand(static_cast<unsigned int>(time(NULL)));

    int r = rand();
    auto point_1 = vss::Point(r, 0);
    auto ball_1 = vss::Ball(0, 0, 0, 0);

    auto distance = vss::Math::distance(point_1, ball_1);

    EXPECT_EQ(distance, r);
}

TEST(Math_distance, ShouldCalcDistanceBetweenPointAndRobot){
    srand(static_cast<unsigned int>(time(NULL)));

    int r = rand();
    auto point_1 = vss::Point(r, 0);
    auto robot_1 = vss::Robot(0, 0, 0, 0, 0, 0);

    auto distance = vss::Math::distance(point_1, robot_1);

    EXPECT_EQ(distance, r);
}

TEST(Math_angleBetween, ShouldCalcPositive45DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(r, r);

    auto angle = vss::Math::angleBetween(point_1, point_2);

    EXPECT_EQ(angle, 45.0);
}

TEST(Math_angleBetween, ShouldCalcNegative45DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(-r, r);

    auto angle = vss::Math::angleBetween(point_1, point_2);

    EXPECT_EQ(angle, -45.0);
}

TEST(Math_angleBetween, ShouldCalcPositive90DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(r, 0);

    auto angle = vss::Math::angleBetween(point_1, point_2);

    EXPECT_EQ(angle, 90.0);
}

TEST(Math_angleBetween, ShouldCalcNegative90DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(-r, 0);

    auto angle = vss::Math::angleBetween(point_1, point_2);

    EXPECT_EQ(angle, -90.0);
}

TEST(Math_angleBetween, ShouldCalc0DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(0, r);

    auto angle = vss::Math::angleBetween(point_1, point_2);

    EXPECT_EQ(angle, 0.0);
}

TEST(Math_angleBetween, ShouldCalc180DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(0, -r);

    auto angle = vss::Math::angleBetween(point_1, point_2);

    EXPECT_EQ(angle, 180.0);
}

TEST(Math_radianBetween, ShouldCalcPositive45DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(r, r);

    auto radian = vss::Math::radianBetween(point_1, point_2);

    EXPECT_FLOAT_EQ(radian, M_PI/4.0);
}

TEST(Math_radianBetween, ShouldCalcNegative45DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(-r, r);

    auto radian = vss::Math::radianBetween(point_1, point_2);

    EXPECT_FLOAT_EQ(radian, -M_PI/4.0);
}

TEST(Math_radianBetween, ShouldCalcPositive90DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(r, 0);

    auto radian = vss::Math::radianBetween(point_1, point_2);

    EXPECT_FLOAT_EQ(radian, M_PI/2.0);
}

TEST(Math_radianBetween, ShouldCalcNegative90DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(-r, 0);

    auto radian = vss::Math::radianBetween(point_1, point_2);

    EXPECT_FLOAT_EQ(radian, -M_PI/2.0);
}

TEST(Math_radianBetween, ShouldCalc0DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(0, r);

    auto radian = vss::Math::radianBetween(point_1, point_2);

    EXPECT_FLOAT_EQ(radian, 0.0);
}

TEST(Math_radianBetween, ShouldCalc180DegreesCorrectly){
    float r = 1.0;
    auto point_1 = vss::Point(0, 0);
    auto point_2 = vss::Point(0, -r);

    auto radian = vss::Math::radianBetween(point_1, point_2);

    EXPECT_FLOAT_EQ(radian, M_PI);
}