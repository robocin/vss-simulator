//
// Created by johnathan on 16/06/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/Constants.h>
#include "Helpers/DomainRandomizer.h"
#include "math.h"

TEST(createRandomPoint, ShouldCreateValidObject){
    auto point = vss::DomainRandomizer::createRandomPoint();

    EXPECT_GE(point.x, 0);
    EXPECT_GE(point.y, 0);
    EXPECT_LE(point.x, vss::MAX_COORDINATE_X);
    EXPECT_LE(point.y, vss::MAX_COORDINATE_Y);
}

TEST(createRandomPose, ShouldCreateValidObject){
    auto pose = vss::DomainRandomizer::createRandomPose();

    EXPECT_GE(pose.x, 0);
    EXPECT_GE(pose.y, 0);
    EXPECT_GE(pose.angle, 0);
    EXPECT_LE(pose.x, vss::MAX_COORDINATE_X);
    EXPECT_LE(pose.y, vss::MAX_COORDINATE_Y);
    EXPECT_LE(pose.angle, vss::MAX_ANGLE_VALUE);
}

TEST(createRandomBall, ShouldCreateValidObject){
    auto ball = vss::DomainRandomizer::createRandomBall();

    EXPECT_GE(ball.x, 0);
    EXPECT_GE(ball.y, 0);
    EXPECT_LE(ball.x, vss::MAX_COORDINATE_X);
    EXPECT_LE(ball.y, vss::MAX_COORDINATE_Y);
    EXPECT_LE(std::fabs(ball.speedX), vss::MAX_RANDOM_VELOCITY);
    EXPECT_LE(std::fabs(ball.speedY), vss::MAX_RANDOM_VELOCITY);
}

TEST(createRandomRobot, ShouldCreateValidObject){
    auto robot = vss::DomainRandomizer::createRandomRobot();

    EXPECT_GE(robot.x, 0);
    EXPECT_GE(robot.y, 0);
    EXPECT_GE(robot.angle, 0);
    EXPECT_LE(robot.x, vss::MAX_COORDINATE_X);
    EXPECT_LE(robot.y, vss::MAX_COORDINATE_Y);
    EXPECT_LE(robot.angle, vss::MAX_ANGLE_VALUE);
    EXPECT_LE(std::fabs(robot.speedX), vss::MAX_RANDOM_VELOCITY);
    EXPECT_LE(std::fabs(robot.speedY), vss::MAX_RANDOM_VELOCITY);
    EXPECT_LE(std::fabs(robot.speedAngle), vss::MAX_RANDOM_VELOCITY);
}

TEST(createRandomPath, ShouldCreateValidObject){
    auto path = vss::DomainRandomizer::createRandomPath();

    EXPECT_GE(path.points.size(), (unsigned int)0);
    EXPECT_LE(path.points.size(), (unsigned int)vss::MAX_RANDOM_PATH_SIZE);
}

TEST(createRandomState, ShouldCreateValidObject){
    auto state = vss::DomainRandomizer::createRandomState();

    EXPECT_GE(state.teamBlue.size(), (unsigned int)0);
    EXPECT_GE(state.teamYellow.size(), (unsigned int)0);
    EXPECT_LE(state.teamBlue.size(), (unsigned int)vss::MAX_RANDOM_TEAM_SIZE);
    EXPECT_LE(state.teamYellow.size(), (unsigned int)vss::MAX_RANDOM_TEAM_SIZE);
}

TEST(createRandomWheelsCommand, ShouldCreateValidObject){
    auto wheelsCommand = vss::DomainRandomizer::createRandomWheelsCommand();

    EXPECT_LE(std::fabs(wheelsCommand.rightVel), vss::MAX_RANDOM_WHEEL_COMMAND);
    EXPECT_LE(std::fabs(wheelsCommand.leftVel), vss::MAX_RANDOM_WHEEL_COMMAND);
}

TEST(createRandomCommand, ShouldCreateValidObject){
    auto command = vss::DomainRandomizer::createRandomCommand();

    EXPECT_GE(command.commands.size(), (unsigned int)0);
    EXPECT_LE(command.commands.size(), (unsigned int)vss::MAX_RANDOM_TEAM_SIZE);
}

TEST(createRandomDebug, ShouldCreateValidObject){
    auto debug = vss::DomainRandomizer::createRandomDebug();

    EXPECT_GE(debug.paths.size(), (unsigned int)0);
    EXPECT_GE(debug.finalPoses.size(), (unsigned int)0);
    EXPECT_GE(debug.stepPoints.size(), (unsigned int)0);
    EXPECT_LE(debug.paths.size(), (unsigned int)vss::MAX_RANDOM_TEAM_SIZE);
    EXPECT_LE(debug.finalPoses.size(), (unsigned int)vss::MAX_RANDOM_TEAM_SIZE);
    EXPECT_LE(debug.stepPoints.size(), (unsigned int)vss::MAX_RANDOM_TEAM_SIZE);
}

TEST(createRandomControl, ShouldCreateValidObject){
    auto control = vss::DomainRandomizer::createRandomControl();

    EXPECT_GE(control.teamYellow.size(), (unsigned int)0);
    EXPECT_GE(control.teamBlue.size(), (unsigned int)0);
    EXPECT_LE(control.teamYellow.size(), (unsigned int)vss::MAX_RANDOM_TEAM_SIZE);
    EXPECT_LE(control.teamBlue.size(), (unsigned int)vss::MAX_RANDOM_TEAM_SIZE);
}

TEST(createRandomRobotCommand, ShouldCreateValidObject){
    auto robotCommand = vss::DomainRandomizer::createRandomRobotCommand();

    EXPECT_LE(std::fabs(robotCommand.left_vel()), vss::MAX_RANDOM_WHEEL_COMMAND);
    EXPECT_LE(std::fabs(robotCommand.right_vel()), vss::MAX_RANDOM_WHEEL_COMMAND);
}

TEST(createRandomGlobalCommands, ShouldCreateValidObject){
    auto robotCommand = vss::DomainRandomizer::createRandomGlobalCommands();

    EXPECT_GE(robotCommand.robot_commands_size(), 0);
    EXPECT_LE(robotCommand.robot_commands_size(), vss::MAX_RANDOM_TEAM_SIZE);

    for(int i = 0 ; i < robotCommand.robot_commands_size() ; i++){
        EXPECT_LE(std::fabs(robotCommand.robot_commands(i).left_vel()), vss::MAX_RANDOM_WHEEL_COMMAND);
        EXPECT_LE(std::fabs(robotCommand.robot_commands(i).right_vel()), vss::MAX_RANDOM_WHEEL_COMMAND);
    }
}