//
// Created by johnathan on 01/07/18.
//

#include <Domain/ExecutionConfig.h>
#include <Domain/Constants.h>

namespace vss {

    ExecutionConfig::ExecutionConfig() {
        stateSendAddr = Address(DEFAULT_STATE_SEND_ADDR, DEFAULT_STATE_PORT);
        stateRecvAddr = Address(DEFAULT_STATE_RECV_ADDR, DEFAULT_STATE_PORT);

        cmdYellowSendAddr = Address(DEFAULT_CMD_SEND_ADDR, DEFAULT_CMD_YELLOW_PORT);
        cmdYellowRecvAddr = Address(DEFAULT_CMD_RECV_ADDR, DEFAULT_CMD_YELLOW_PORT);
        debugYellowSendAddr = Address(DEFAULT_DEBUG_SEND_ADDR, DEFAULT_DEBUG_YELLOW_PORT);
        debugYellowRecvAddr = Address(DEFAULT_DEBUG_RECV_ADDR, DEFAULT_DEBUG_YELLOW_PORT);

        cmdBlueSendAddr = Address(DEFAULT_CMD_SEND_ADDR, DEFAULT_CMD_BLUE_PORT);
        cmdBlueRecvAddr = Address(DEFAULT_CMD_RECV_ADDR, DEFAULT_CMD_BLUE_PORT);
        debugBlueSendAddr = Address(DEFAULT_DEBUG_SEND_ADDR, DEFAULT_DEBUG_BLUE_PORT);
        debugBlueRecvAddr = Address(DEFAULT_DEBUG_RECV_ADDR, DEFAULT_DEBUG_BLUE_PORT);

        ctrlSendAddr = Address(DEFAULT_CTRL_SEND_ADDR, DEFAULT_CTRL_PORT);
        ctrlRecvAddr = Address(DEFAULT_CTRL_RECV_ADDR, DEFAULT_CTRL_PORT);

        teamType = DEFAULT_TEAM_TYPE;
        sideAttackType = DEFAULT_SIDE_ATTACK_TYPE;
        timeExecutionType = DEFAULT_TIME_EXECUTION_TYPE;
        environmentType = DEFAULT_ENVIRONMENT_TYPE;
        durationType = DEFAULT_DURATION_TYPE;
        matchFinishType = DEFAULT_MATCH_FINISH_TYPE;
        teamInitialPositionPath = "";

        isValidConfiguration = false;
    }

    std::ostream &operator<<(std::ostream &os, const ExecutionConfig &executionConfig) {
        os << "stateSendAddr: " << executionConfig.stateSendAddr.ip << ":" << executionConfig.stateSendAddr.port << std::endl;
        os << "stateRecvAddr: " << executionConfig.stateRecvAddr.ip << ":" << executionConfig.stateRecvAddr.port << std::endl;

        os << "cmdYellowSendAddr: " << executionConfig.cmdYellowSendAddr.ip << ":" << executionConfig.cmdYellowSendAddr.port << std::endl;
        os << "cmdYellowRecvAddr: " << executionConfig.cmdYellowRecvAddr.ip << ":" << executionConfig.cmdYellowRecvAddr.port << std::endl;
        os << "debugYellowSendAddr: " << executionConfig.debugYellowSendAddr.ip << ":" << executionConfig.debugYellowSendAddr.port << std::endl;
        os << "debugYellowRecvAddr: " << executionConfig.debugYellowRecvAddr.ip << ":" << executionConfig.debugYellowRecvAddr.port << std::endl;

        os << "cmdBlueSendAddr: " << executionConfig.cmdBlueSendAddr.ip << ":" << executionConfig.cmdBlueSendAddr.port << std::endl;
        os << "cmdBlueRecvAddr: " << executionConfig.cmdBlueRecvAddr.ip << ":" << executionConfig.cmdBlueRecvAddr.port << std::endl;
        os << "debugBlueSendAddr: " << executionConfig.debugBlueSendAddr.ip << ":" << executionConfig.debugBlueSendAddr.port << std::endl;
        os << "debugBlueRecvAddr: " << executionConfig.debugBlueRecvAddr.ip << ":" << executionConfig.debugBlueRecvAddr.port << std::endl;

        os << "ctrlSendAddr: " << executionConfig.ctrlSendAddr.ip << ":" << executionConfig.ctrlSendAddr.port << std::endl;
        os << "ctrlRecvAddr: " << executionConfig.ctrlRecvAddr.ip << ":" << executionConfig.ctrlRecvAddr.port << std::endl;

        os << "teamType: " << toDescription(executionConfig.teamType) << std::endl;
        os << "sideAttackType: " << toDescription(executionConfig.sideAttackType) << std::endl;
        os << "timeExecutionType: " << toDescription(executionConfig.timeExecutionType) << std::endl;
        os << "environmentType: " << toDescription(executionConfig.environmentType) << std::endl;
        os << "durationType: " << toDescription(executionConfig.durationType) << std::endl;
        os << "matchFinishType: " << toDescription(executionConfig.matchFinishType) << std::endl;

        os << "teamInitialPositionPath: " << executionConfig.teamInitialPositionPath << std::endl;

        return os;
    }

};