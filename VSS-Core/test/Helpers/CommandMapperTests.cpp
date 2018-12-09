//
// Created by johnathan on 17/06/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/CommandMapper.h>
#include <Helpers/DomainRandomizer.h>

TEST(setupWheelCommand, ShouldSetRightValues){
    auto robotCommand = vss_command::Robot_Command();
    auto wheelsCommand = vss::DomainRandomizer::createRandomWheelsCommand();

    vss::CommandMapper::setupWheelCommand(&robotCommand, wheelsCommand);

    EXPECT_EQ(wheelsCommand.leftVel, robotCommand.left_vel());
    EXPECT_EQ(wheelsCommand.rightVel, robotCommand.right_vel());
}

TEST(commandToGlobalCommands, ShouldSetRightValues){
    auto command = vss::DomainRandomizer::createRandomCommand();

    auto globalCommands = vss::CommandMapper::commandToGlobalCommands(command);

    EXPECT_EQ(command.commands.size(), (unsigned)globalCommands.robot_commands_size());

    for(unsigned int i = 0 ; i < command.commands.size() ; i++) {
        EXPECT_EQ(command.commands[i].leftVel, globalCommands.robot_commands(i).left_vel());
        EXPECT_EQ(command.commands[i].rightVel, globalCommands.robot_commands(i).right_vel());
    }
}

TEST(robotCommandToWheelsCommand, ShouldReturnRightValues){
    auto robotCommand = vss::DomainRandomizer::createRandomRobotCommand();
    auto wheelsCommand = vss::CommandMapper::robotCommandToWheelsCommand(robotCommand);

    EXPECT_EQ(wheelsCommand.leftVel, robotCommand.left_vel());
    EXPECT_EQ(wheelsCommand.rightVel, robotCommand.right_vel());
}

TEST(globalCommandsToCommand, ShouldReturnRightValues){
    auto globalCommands = vss::DomainRandomizer::createRandomGlobalCommands();
    auto command = vss::CommandMapper::globalCommandsToCommand(globalCommands);

    EXPECT_EQ(command.commands.size(), (unsigned)globalCommands.robot_commands_size());

    for(unsigned int i = 0 ; i < command.commands.size() ; i++){
        EXPECT_EQ(globalCommands.robot_commands(i).left_vel(), command.commands[i].leftVel);
        EXPECT_EQ(globalCommands.robot_commands(i).right_vel(), command.commands[i].rightVel);
    }
}