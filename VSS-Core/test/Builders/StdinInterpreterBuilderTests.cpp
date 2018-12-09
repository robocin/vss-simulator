//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Builders/StdinInterpreterBuilder.h>

TEST(StdinInterpreterBuilder_buildInterpreter, ShouldReturnAllFalse){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto stdinInterpreter = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_FALSE(stdinInterpreter->onStateRecvAddr);

    EXPECT_FALSE(stdinInterpreter->onYellowCmdSendAddr);
    EXPECT_FALSE(stdinInterpreter->onYellowDebugSendAddr);

    EXPECT_FALSE(stdinInterpreter->onBlueCmdSendAddr);
    EXPECT_FALSE(stdinInterpreter->onBlueDebugSendAddr);

    EXPECT_FALSE(stdinInterpreter->onCtrlRecvAddr);

    EXPECT_FALSE(stdinInterpreter->onStatePort);
    EXPECT_FALSE(stdinInterpreter->onYellowCmdPort);
    EXPECT_FALSE(stdinInterpreter->onYellowDebugPort);
    EXPECT_FALSE(stdinInterpreter->onBlueCmdPort);
    EXPECT_FALSE(stdinInterpreter->onBlueDebugPort);
    EXPECT_FALSE(stdinInterpreter->onCtrlPort);

    EXPECT_FALSE(stdinInterpreter->onTeamType);
    EXPECT_FALSE(stdinInterpreter->onSideAttackType);
    EXPECT_FALSE(stdinInterpreter->onTimeExecutionType);
    EXPECT_FALSE(stdinInterpreter->onEnvironmentType);
    EXPECT_FALSE(stdinInterpreter->onDurationType);
    EXPECT_FALSE(stdinInterpreter->onMatchFinishType);

    EXPECT_FALSE(stdinInterpreter->onTeamInitialPositionPath);
}

TEST(StdinInterpreterBuilder_onStateRecvAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onStateRecvAddr, false);

    auto configured = stdinInterpreterBuilder.onStateRecvAddr()->buildInterpreter();
    EXPECT_EQ(configured->onStateRecvAddr, true);
}

TEST(StdinInterpreterBuilder_onYellowCmdSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowCmdSendAddr, false);

    auto configured = stdinInterpreterBuilder.onYellowCmdSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onYellowCmdSendAddr, true);
}

TEST(StdinInterpreterBuilder_onYellowDebugSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowDebugSendAddr, false);

    auto configured = stdinInterpreterBuilder.onYellowDebugSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onYellowDebugSendAddr, true);
}

TEST(StdinInterpreterBuilder_onBlueCmdSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueCmdSendAddr, false);

    auto configured = stdinInterpreterBuilder.onBlueCmdSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onBlueCmdSendAddr, true);
}

TEST(StdinInterpreterBuilder_onBlueDebugSendAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueDebugSendAddr, false);

    auto configured = stdinInterpreterBuilder.onBlueDebugSendAddr()->buildInterpreter();
    EXPECT_EQ(configured->onBlueDebugSendAddr, true);
}

TEST(StdinInterpreterBuilder_onCtrlRecvAddr, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onCtrlRecvAddr, false);

    auto configured = stdinInterpreterBuilder.onCtrlRecvAddr()->buildInterpreter();
    EXPECT_EQ(configured->onCtrlRecvAddr, true);
}

TEST(StdinInterpreterBuilder_onYellowCmdPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowCmdPort, false);

    auto configured = stdinInterpreterBuilder.onYellowCmdPort()->buildInterpreter();
    EXPECT_EQ(configured->onYellowCmdPort, true);
}

TEST(StdinInterpreterBuilder_onYellowDebugPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onYellowDebugPort, false);

    auto configured = stdinInterpreterBuilder.onYellowDebugPort()->buildInterpreter();
    EXPECT_EQ(configured->onYellowDebugPort, true);
}

TEST(StdinInterpreterBuilder_onBlueCmdPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueCmdPort, false);

    auto configured = stdinInterpreterBuilder.onBlueCmdPort()->buildInterpreter();
    EXPECT_EQ(configured->onBlueCmdPort, true);
}

TEST(StdinInterpreterBuilder_onBlueDebugPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onBlueDebugPort, false);

    auto configured = stdinInterpreterBuilder.onBlueDebugPort()->buildInterpreter();
    EXPECT_EQ(configured->onBlueDebugPort, true);
}

TEST(StdinInterpreterBuilder_onCtrlPort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onCtrlPort, false);

    auto configured = stdinInterpreterBuilder.onCtrlPort()->buildInterpreter();
    EXPECT_EQ(configured->onCtrlPort, true);
}

TEST(StdinInterpreterBuilder_onTeamType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onTeamType, false);

    auto configured = stdinInterpreterBuilder.onTeamType()->buildInterpreter();
    EXPECT_EQ(configured->onTeamType, true);
}

TEST(StdinInterpreterBuilder_onSideAttackType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onSideAttackType, false);

    auto configured = stdinInterpreterBuilder.onSideAttackType()->buildInterpreter();
    EXPECT_EQ(configured->onSideAttackType, true);
}

TEST(StdinInterpreterBuilder_onTimeExecutionType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onTimeExecutionType, false);

    auto configured = stdinInterpreterBuilder.onTimeExecutionType()->buildInterpreter();
    EXPECT_EQ(configured->onTimeExecutionType, true);
}

TEST(StdinInterpreterBuilder_onDurationType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onDurationType, false);

    auto configured = stdinInterpreterBuilder.onDurationType()->buildInterpreter();
    EXPECT_EQ(configured->onDurationType, true);
}

TEST(StdinInterpreterBuilder_onMatchFinishType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onMatchFinishType, false);

    auto configured = stdinInterpreterBuilder.onMatchFinishType()->buildInterpreter();
    EXPECT_EQ(configured->onMatchFinishType, true);
}

TEST(StdinInterpreterBuilder_onTeamInitialPositionPath, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onTeamInitialPositionPath, false);

    auto configured = stdinInterpreterBuilder.onTeamInitialPositionPath()->buildInterpreter();
    EXPECT_EQ(configured->onTeamInitialPositionPath, true);
}

TEST(StdinInterpreterBuilder_onStatePort, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onStatePort, false);

    auto configured = stdinInterpreterBuilder.onStatePort()->buildInterpreter();
    EXPECT_EQ(configured->onStatePort, true);
}

TEST(StdinInterpreterBuilder_onEnvironmentType, ShouldReturnThisAndSetValue){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onEnvironmentType, false);

    auto configured = stdinInterpreterBuilder.onEnvironmentType()->buildInterpreter();
    EXPECT_EQ(configured->onEnvironmentType, true);
}

TEST(StdinInterpreterBuilder_TwoFluents, ShouldReturnThisAndSetValues){
    vss::StdinInterpreterBuilder stdinInterpreterBuilder;

    auto raw = stdinInterpreterBuilder.buildInterpreter();
    EXPECT_EQ(raw->onEnvironmentType, false);
    EXPECT_EQ(raw->onStatePort, false);

    auto configured = stdinInterpreterBuilder.onStatePort()->onEnvironmentType()->buildInterpreter();
    EXPECT_EQ(configured->onEnvironmentType, true);
    EXPECT_EQ(configured->onStatePort, true);
}