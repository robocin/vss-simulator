//
// Created by johnathan on 31/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/Control.h>
#include <Helpers/DomainRandomizer.h>

TEST(Control_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Control control;

    EXPECT_EQ(control.paused, false);
    EXPECT_EQ(control.ball.x, 0);
    EXPECT_EQ(control.ball.y, 0);
    EXPECT_EQ(control.ball.speedX, 0);
    EXPECT_EQ(control.ball.speedY, 0);
    EXPECT_EQ(control.teamYellow.size(), (unsigned int)0);
    EXPECT_EQ(control.teamBlue.size(), (unsigned int)0);
}

TEST(Control_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
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

    vss::Control control(true, ball, teamYellow, teamBlue);

    EXPECT_EQ(control.ball.x, ball.x);
    EXPECT_EQ(control.ball.y, ball.y);
    EXPECT_EQ(control.ball.speedX, ball.speedX);
    EXPECT_EQ(control.ball.speedY, ball.speedY);
    EXPECT_EQ(control.teamYellow.size(), teamYellow.size());
    EXPECT_EQ(control.teamBlue.size(), teamBlue.size());

    for(unsigned int i = 0 ; i < control.teamYellow.size() ; i++){
        EXPECT_EQ(control.teamYellow[i].x, teamYellow[i].x);
        EXPECT_EQ(control.teamYellow[i].y, teamYellow[i].y);
        EXPECT_EQ(control.teamYellow[i].angle, teamYellow[i].angle);
        EXPECT_EQ(control.teamYellow[i].speedX, teamYellow[i].speedX);
        EXPECT_EQ(control.teamYellow[i].speedY, teamYellow[i].speedY);
        EXPECT_EQ(control.teamYellow[i].speedAngle, teamYellow[i].speedAngle);
    }

    for(unsigned int i = 0 ; i < control.teamBlue.size() ; i++){
        EXPECT_EQ(control.teamBlue[i].x, teamBlue[i].x);
        EXPECT_EQ(control.teamBlue[i].y, teamBlue[i].y);
        EXPECT_EQ(control.teamBlue[i].angle, teamBlue[i].angle);
        EXPECT_EQ(control.teamBlue[i].speedX, teamBlue[i].speedX);
        EXPECT_EQ(control.teamBlue[i].speedY, teamBlue[i].speedY);
        EXPECT_EQ(control.teamBlue[i].speedAngle, teamBlue[i].speedAngle);
    }
}

TEST(Control_cout, WhenCoutShouldPrintRight){
    auto control = vss::DomainRandomizer::createRandomControl();

    testing::internal::CaptureStdout();
    std::cout << control;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;

    mock_output << "Control {" << std::endl;

    mock_output << "\tPaused: " << control.paused << std::endl;
    mock_output << "\tBall: " << control.ball << std::endl;
    mock_output << "\tTeamYellow:" << std::endl;

    for (const auto &i : control.teamYellow) {
        mock_output << "\t\t" << i << std::endl;
    }

    mock_output << "\tTeamBlue:" << std::endl;

    for (const auto &i : control.teamBlue) {
        mock_output << "\t\t" << i << std::endl;
    }

    mock_output << "}";

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}