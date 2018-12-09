//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_CONSTANTS_H
#define VSS_CORE_CONSTANTS_H

#include "string"
#include "Domain/TeamType.h"
#include "Domain/SideAttackType.h"
#include "Domain/TimeExecutionType.h"
#include "Domain/EnvironmentType.h"
#include "Domain/DurationType.h"
#include "Domain/MatchFinishType.h"

namespace vss {

    // Space Constraints
    const int MIN_COORDINATE_X = 0;
    const int MAX_COORDINATE_X = 170;
    const int MIN_COORDINATE_Y = 0;
    const int MAX_COORDINATE_Y = 130;
    const int MIN_ANGLE_VALUE = 0;
    const int MAX_ANGLE_VALUE = 360;

    // Randomization
    const int MAX_RANDOM_VELOCITY = 5;
    const int MAX_RANDOM_PATH_SIZE = 10;
    const int MAX_RANDOM_TEAM_SIZE = 11;
    const int MAX_RANDOM_WHEEL_COMMAND = 10;
    const int MAX_RANDOM_IP_VALUE = 255;
    const int MAX_RANDOM_PORT_VALUE = 20000;

    // Communication
    const int DEFAULT_STATE_PORT = 5555;
    const int DEFAULT_CMD_YELLOW_PORT = 5556;
    const int DEFAULT_CMD_BLUE_PORT = 5557;
    const int DEFAULT_DEBUG_YELLOW_PORT = 5558;
    const int DEFAULT_DEBUG_BLUE_PORT = 5559;
    const int DEFAULT_CTRL_PORT = 5560;
    const std::string DEFAULT_STATE_SEND_ADDR = "tcp://*";
    const std::string DEFAULT_STATE_RECV_ADDR = "tcp://localhost";
    const std::string DEFAULT_CMD_SEND_ADDR = "tcp://localhost";
    const std::string DEFAULT_CMD_RECV_ADDR = "tcp://*";
    const std::string DEFAULT_DEBUG_SEND_ADDR = "tcp://localhost";
    const std::string DEFAULT_DEBUG_RECV_ADDR = "tcp://*";
    const std::string DEFAULT_CTRL_SEND_ADDR = "tcp://*";
    const std::string DEFAULT_CTRL_RECV_ADDR = "tcp://localhost";

    // Enums
    const TeamType DEFAULT_TEAM_TYPE = TeamType::Yellow;
    const SideAttackType DEFAULT_SIDE_ATTACK_TYPE = SideAttackType::Left;
    const TimeExecutionType DEFAULT_TIME_EXECUTION_TYPE = TimeExecutionType::Normal;
    const EnvironmentType DEFAULT_ENVIRONMENT_TYPE = EnvironmentType::Simulation;
    const DurationType  DEFAULT_DURATION_TYPE = DurationType::TenMinutes;
    const MatchFinishType DEFAULT_MATCH_FINISH_TYPE = MatchFinishType::TenGoalsDifference;

}

#endif //VSS_CORE_CONSTANTS_H
