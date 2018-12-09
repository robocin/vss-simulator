//
// Created by johnathan on 31/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/State.h>
#include <Helpers/DomainRandomizer.h>

TEST(State_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::State state;

    EXPECT_EQ(state.ball.x, 0);
    EXPECT_EQ(state.ball.y, 0);
    EXPECT_EQ(state.ball.speedX, 0);
    EXPECT_EQ(state.ball.speedY, 0);
    EXPECT_EQ(state.teamYellow.size(), (unsigned int)0);
    EXPECT_EQ(state.teamBlue.size(), (unsigned int)0);
}

TEST(State_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    auto sizeTeamYellow = static_cast<unsigned int>(rand() % 10);
    auto sizeTeamBlue = static_cast<unsigned int>(rand() % 10);

    auto ball = vss::DomainRandomizer::createRandomBall();
    std::vector<vss::Robot> teamYellow;
    std::vector<vss::Robot> teamBlue;

    for(unsigned int i = 0 ; i < sizeTeamYellow ; i++){
        teamYellow.push_back(vss::DomainRandomizer::createRandomRobot());
    }

    for(unsigned int i = 0 ; i < sizeTeamBlue ; i++){
        teamBlue.push_back(vss::DomainRandomizer::createRandomRobot());
    }

    vss::State state(ball, teamYellow, teamBlue);

    EXPECT_EQ(state.ball.x, ball.x);
    EXPECT_EQ(state.ball.y, ball.y);
    EXPECT_EQ(state.ball.speedX, ball.speedX);
    EXPECT_EQ(state.ball.speedY, ball.speedY);
    EXPECT_EQ(state.teamYellow.size(), teamYellow.size());
    EXPECT_EQ(state.teamBlue.size(), teamBlue.size());

    for(unsigned int i = 0 ; i < state.teamYellow.size() ; i++){
        EXPECT_EQ(state.teamYellow[i].x, teamYellow[i].x);
        EXPECT_EQ(state.teamYellow[i].y, teamYellow[i].y);
        EXPECT_EQ(state.teamYellow[i].angle, teamYellow[i].angle);
        EXPECT_EQ(state.teamYellow[i].speedX, teamYellow[i].speedX);
        EXPECT_EQ(state.teamYellow[i].speedY, teamYellow[i].speedY);
        EXPECT_EQ(state.teamYellow[i].speedAngle, teamYellow[i].speedAngle);
    }

    for(unsigned int i = 0 ; i < state.teamBlue.size() ; i++){
        EXPECT_EQ(state.teamBlue[i].x, teamBlue[i].x);
        EXPECT_EQ(state.teamBlue[i].y, teamBlue[i].y);
        EXPECT_EQ(state.teamBlue[i].angle, teamBlue[i].angle);
        EXPECT_EQ(state.teamBlue[i].speedX, teamBlue[i].speedX);
        EXPECT_EQ(state.teamBlue[i].speedY, teamBlue[i].speedY);
        EXPECT_EQ(state.teamBlue[i].speedAngle, teamBlue[i].speedAngle);
    }
}

TEST(State_cout, WhenCoutShouldPrintRight){
    auto state = vss::DomainRandomizer::createRandomState();

    testing::internal::CaptureStdout();
    std::cout << state;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;

    mock_output << "State {" << std::endl;

    mock_output << "\t" << state.ball << std::endl;
    mock_output << "\tTeamYellow:" << std::endl;

    for (const auto &i : state.teamYellow) {
        mock_output << "\t\t" << i << std::endl;
    }

    mock_output << "\tTeamBlue:" << std::endl;

    for (const auto &i : state.teamBlue) {
        mock_output << "\t\t" << i << std::endl;
    }

    mock_output << "}";

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

