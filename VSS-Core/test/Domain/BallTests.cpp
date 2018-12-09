//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/DomainRandomizer.h>
#include <Domain/Constants.h>
#include "Domain/Ball.h"

TEST(Ball_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Ball ball;

    EXPECT_EQ(ball.x, 0);
    EXPECT_EQ(ball.y, 0);
    EXPECT_EQ(ball.speedX, 0);
    EXPECT_EQ(ball.speedY, 0);
}

TEST(Ball_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    float x = rand()%vss::MAX_COORDINATE_X;
    float y = rand()%vss::MAX_COORDINATE_Y;
    float speedX = rand();
    float speedY = rand();

    vss::Ball ball(x, y, speedX, speedY);

    EXPECT_EQ(ball.x, x);
    EXPECT_EQ(ball.y, y);
    EXPECT_EQ(ball.speedX, speedX);
    EXPECT_EQ(ball.speedY, speedY);
}

TEST(Ball_cout, WhenCoutShouldPrintRight){
    auto ball = vss::DomainRandomizer::createRandomBall();

    testing::internal::CaptureStdout();
    std::cout << ball;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;
    mock_output << "Ball(" << ball.x << ", " << ball.y << ", " << ball.speedX << ", " << ball.speedY  << ")";

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(Ball_minus, ShouldSubtractCorrectly){
    auto first = vss::DomainRandomizer::createRandomBall();
    auto second = vss::DomainRandomizer::createRandomBall();

    auto result = first - second;

    EXPECT_EQ(result.x, first.x - second.x);
    EXPECT_EQ(result.y, first.y - second.y);
    EXPECT_EQ(result.speedX, first.speedX - second.speedX);
    EXPECT_EQ(result.speedY, first.speedY - second.speedY);
}

TEST(Ball_plus, ShouldAddCorrectly){
    auto first = vss::DomainRandomizer::createRandomBall();
    auto second = vss::DomainRandomizer::createRandomBall();

    auto result = first + second;

    EXPECT_EQ(result.x, first.x + second.x);
    EXPECT_EQ(result.y, first.y + second.y);
    EXPECT_EQ(result.speedX, first.speedX + second.speedX);
    EXPECT_EQ(result.speedY, first.speedY + second.speedY);
}

TEST(Ball_equals, ShouldCompareCorrectly){
    auto value = vss::DomainRandomizer::createRandomBall();

    EXPECT_EQ(value, value);
    EXPECT_NE(value, vss::Ball(value.x+1, value.y, value.speedX, value.speedY));
    EXPECT_NE(value, vss::Ball(value.x, value.y+1, value.speedX, value.speedY));
    EXPECT_NE(value, vss::Ball(value.x, value.y, value.speedX+1, value.speedY));
    EXPECT_NE(value, vss::Ball(value.x, value.y, value.speedX, value.speedY+1));
    EXPECT_NE(value, vss::Ball(value.x-1, value.y, value.speedX, value.speedY));
    EXPECT_NE(value, vss::Ball(value.x, value.y-1, value.speedX, value.speedY));
    EXPECT_NE(value, vss::Ball(value.x, value.y, value.speedX-1, value.speedY));
    EXPECT_NE(value, vss::Ball(value.x, value.y, value.speedX, value.speedY-1));
}