//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Interpreters/StdinInterpreter.h>
#include <Domain/Constants.h>

TEST(StdinInterpreter_Constructor, WhenDefaultBuilded_ShouldBeFalse){
    vss::StdinInterpreter stdinInterpreter;

    EXPECT_FALSE(stdinInterpreter.onStateRecvAddr);

    EXPECT_FALSE(stdinInterpreter.onYellowCmdSendAddr);
    EXPECT_FALSE(stdinInterpreter.onYellowDebugSendAddr);

    EXPECT_FALSE(stdinInterpreter.onBlueCmdSendAddr);
    EXPECT_FALSE(stdinInterpreter.onBlueDebugSendAddr);

    EXPECT_FALSE(stdinInterpreter.onCtrlRecvAddr);

    EXPECT_FALSE(stdinInterpreter.onStatePort);
    EXPECT_FALSE(stdinInterpreter.onYellowCmdPort);
    EXPECT_FALSE(stdinInterpreter.onYellowDebugPort);
    EXPECT_FALSE(stdinInterpreter.onBlueCmdPort);
    EXPECT_FALSE(stdinInterpreter.onBlueDebugPort);
    EXPECT_FALSE(stdinInterpreter.onCtrlPort);

    EXPECT_FALSE(stdinInterpreter.onTeamType);
    EXPECT_FALSE(stdinInterpreter.onSideAttackType);
    EXPECT_FALSE(stdinInterpreter.onTimeExecutionType);
    EXPECT_FALSE(stdinInterpreter.onEnvironmentType);
    EXPECT_FALSE(stdinInterpreter.onDurationType);
    EXPECT_FALSE(stdinInterpreter.onMatchFinishType);

    EXPECT_FALSE(stdinInterpreter.onTeamInitialPositionPath);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenAllConfigsAreFalseAnHelp_ShouldPrintOnlyHelp){
    vss::StdinInterpreter stdinInterpreter;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnStateRecvAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStateRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --state_recv_addr arg (=" << vss::DEFAULT_STATE_RECV_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowCmdSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_cmd_send_addr arg (=" << vss::DEFAULT_CMD_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowDebugSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_debug_send_addr arg (=" << vss::DEFAULT_CMD_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueCmdSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_cmd_send_addr arg (=" << vss::DEFAULT_CMD_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueDebugSendAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_debug_send_addr arg (=" << vss::DEFAULT_CMD_SEND_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnCtrlRecvAddrIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --ctrl_recv_addr arg (=" << vss::DEFAULT_CTRL_RECV_ADDR << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnStatePortIsTrueAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStatePort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --state_port arg (=" << vss::DEFAULT_STATE_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowCmdPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_cmd_port arg (=" << vss::DEFAULT_CMD_YELLOW_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnYellowDebugPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --yellow_debug_port arg (=" << vss::DEFAULT_DEBUG_YELLOW_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueCmdPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_cmd_port arg (=" << vss::DEFAULT_CMD_BLUE_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnBlueDebugPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --blue_debug_port arg (=" << vss::DEFAULT_DEBUG_BLUE_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnCtrlPortAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --ctrl_port arg (=" << vss::DEFAULT_CTRL_PORT << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnTeamTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTeamType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --team_type arg (=" << vss::toDescription(vss::DEFAULT_TEAM_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnSideAttackTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onSideAttackType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --side_attack_type arg (=" << vss::toDescription(vss::DEFAULT_SIDE_ATTACK_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnTimeExecutionTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTimeExecutionType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --time_execution_type arg (=" << vss::toDescription(vss::DEFAULT_TIME_EXECUTION_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnEnvironmentTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onEnvironmentType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --environment_type arg (=" << vss::toDescription(vss::DEFAULT_ENVIRONMENT_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnDurationTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onDurationType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --duration_type arg (=" << vss::toDescription(vss::DEFAULT_DURATION_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnMatchFinishTypeAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onMatchFinishType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --match_finish_type arg (=" << vss::toDescription(vss::DEFAULT_MATCH_FINISH_TYPE) << ")" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenOnTeamInitialPositionPathAnHelp_ShouldPrintOption){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTeamInitialPositionPath = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--help"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    testing::internal::CaptureStdout();
    stdinInterpreter.extractExecutionConfig(argc, argv);
    std::string output = testing::internal::GetCapturedStdout();

    std::stringstream mock_output;
    mock_output << "Options:" << std::endl;
    mock_output << "  -h [ --help ] " << std::endl;
    mock_output << "  --initial_position_path arg (=file.csv)" << std::endl << std::endl;

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnStateRecvAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStateRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--state_recv_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowCmdSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_cmd_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowDebugSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_debug_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueCmdSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_cmd_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueDebugSendAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_debug_send_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnCtrlRecvAddrAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--ctrl_recv_addr"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnStatePortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStatePort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--state_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowCmdPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_cmd_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueCmdPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_cmd_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowDebugPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_debug_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueDebugPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_debug_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnCtrlPortAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--ctrl_port"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnTeamTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTeamType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--team_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnSideAttackTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onSideAttackType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--side_attack_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnTimeExecutionTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTimeExecutionType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--time_execution_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnEnvironmentTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onEnvironmentType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--environment_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnDurationTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onDurationType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--duration_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnMatchFinishTypeAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onMatchFinishType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--match_finish_type"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnTeamInitialPositionPathAndNotSendValue_ShouldBreak){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTeamInitialPositionPath = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--initial_position_path"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_FALSE(executionConfig.isValidConfiguration);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnStateRecvAddrAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStateRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--state_recv_addr"), const_cast<char *>("tcp://192.168.0.100"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.stateRecvAddr.getIp(), "tcp://192.168.0.100");
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowCmdSendAddrAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_cmd_send_addr"), const_cast<char *>("tcp://192.168.0.100"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.cmdYellowSendAddr.getIp(), "tcp://192.168.0.100");
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowDebugSendAddrAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_debug_send_addr"), const_cast<char *>("tcp://192.168.0.100"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.debugYellowSendAddr.getIp(), "tcp://192.168.0.100");
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueCmdSendAddrAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_cmd_send_addr"), const_cast<char *>("tcp://192.168.0.100"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.cmdBlueSendAddr.getIp(), "tcp://192.168.0.100");
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueDebugSendAddrAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugSendAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_debug_send_addr"), const_cast<char *>("tcp://192.168.0.100"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.debugBlueSendAddr.getIp(), "tcp://192.168.0.100");
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnCtrlRecvAddrAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlRecvAddr = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--ctrl_recv_addr"), const_cast<char *>("tcp://192.168.0.100"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.ctrlRecvAddr.getIp(), "tcp://192.168.0.100");
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnStatePortAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onStatePort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--state_port"), const_cast<char *>("666"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.stateSendAddr.getPort(), 666);
    EXPECT_EQ(executionConfig.stateRecvAddr.getPort(), 666);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowCmdPortAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_cmd_port"), const_cast<char *>("666"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.cmdYellowSendAddr.getPort(), 666);
    EXPECT_EQ(executionConfig.cmdYellowRecvAddr.getPort(), 666);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueCmdPortAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueCmdPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_cmd_port"), const_cast<char *>("666"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.cmdBlueSendAddr.getPort(), 666);
    EXPECT_EQ(executionConfig.cmdBlueRecvAddr.getPort(), 666);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnYellowDebugPortAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onYellowDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--yellow_debug_port"), const_cast<char *>("666"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.debugYellowSendAddr.getPort(), 666);
    EXPECT_EQ(executionConfig.debugYellowRecvAddr.getPort(), 666);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnBlueDebugPortAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onBlueDebugPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--blue_debug_port"), const_cast<char *>("666"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.debugBlueSendAddr.getPort(), 666);
    EXPECT_EQ(executionConfig.debugBlueRecvAddr.getPort(), 666);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnCtrlPortAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onCtrlPort = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--ctrl_port"), const_cast<char *>("666"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.ctrlSendAddr.getPort(), 666);
    EXPECT_EQ(executionConfig.ctrlRecvAddr.getPort(), 666);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnTeamTypeAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTeamType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--team_type"), const_cast<char *>("Blue"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.teamType, vss::TeamType::Blue);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnSideAttackTypeAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onSideAttackType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--side_attack_type"), const_cast<char *>("Right"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.sideAttackType, vss::SideAttackType::Right);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnTimeExecutionTypeAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTimeExecutionType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--time_execution_type"), const_cast<char *>("Fast"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.timeExecutionType, vss::TimeExecutionType::Fast);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnEnvironmentTypeAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onEnvironmentType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--environment_type"), const_cast<char *>("Real"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.environmentType, vss::EnvironmentType::Real);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnDurationTypeAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onDurationType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--duration_type"), const_cast<char *>("UnlimitedMinutes"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.durationType, vss::DurationType::UnlimitedMinutes);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnMatchFinishTypeAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onMatchFinishType = true;

    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--match_finish_type"), const_cast<char *>("TimeUp"), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.matchFinishType, vss::MatchFinishType::TimeUp);
}

TEST(StdinInterpreter_extractExecutionConfig, WhenSendOnTeamInitialPositionPathAndSendValue_ShouldApply){
    vss::StdinInterpreter stdinInterpreter;
    stdinInterpreter.onTeamInitialPositionPath = true;

    std::string file = "new_file.csv";
    char *argv[] = {const_cast<char *>("vss"), const_cast<char *>("--initial_position_path"), const_cast<char *>(file.c_str()), NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    auto executionConfig = stdinInterpreter.extractExecutionConfig(argc, argv);

    EXPECT_TRUE(executionConfig.isValidConfiguration);
    EXPECT_EQ(executionConfig.teamInitialPositionPath, file);
}