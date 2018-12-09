//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/DomainRandomizer.h>
#include <Domain/Constants.h>
#include "Domain/Point.h"

TEST(Point_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Point point;

    EXPECT_EQ(point.x, 0);
    EXPECT_EQ(point.y, 0);
}

TEST(Point_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    float x = rand()%vss::MAX_COORDINATE_X;
    float y = rand()%vss::MAX_COORDINATE_Y;

    vss::Point point(x, y);

    EXPECT_EQ(point.x, x);
    EXPECT_EQ(point.y, y);
}

TEST(Point_cout, WhenCoutShouldPrintRight){
    auto point = vss::DomainRandomizer::createRandomPoint();

    testing::internal::CaptureStdout();
    std::cout << point;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;
    mock_output << "Point(" << point.x << ", " << point.y << ")";

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(Point_minus, ShouldSubtractCorrectly){
    auto first = vss::DomainRandomizer::createRandomPoint();
    auto second = vss::DomainRandomizer::createRandomPoint();

    auto result = first - second;

    EXPECT_EQ(result.x, first.x - second.x);
    EXPECT_EQ(result.y, first.y - second.y);
}

TEST(Point_plus, ShouldAddCorrectly){
    auto first = vss::DomainRandomizer::createRandomPoint();
    auto second = vss::DomainRandomizer::createRandomPoint();

    auto result = first + second;

    EXPECT_EQ(result.x, first.x + second.x);
    EXPECT_EQ(result.y, first.y + second.y);
}

TEST(Point_equals, ShouldCompareCorrectly){
    auto value = vss::DomainRandomizer::createRandomPoint();

    EXPECT_EQ(value, value);
    EXPECT_NE(value, vss::Point(value.x+1, value.y));
    EXPECT_NE(value, vss::Point(value.x, value.y+1));
    EXPECT_NE(value, vss::Point(value.x-1, value.y));
    EXPECT_NE(value, vss::Point(value.x, value.y-1));
}