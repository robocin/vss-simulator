//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_ISTDININTERPRETER_H
#define VSS_CORE_ISTDININTERPRETER_H

#include <Domain/ExecutionConfig.h>

namespace vss {

    class IStdinInterpreter {
    public:
        virtual ExecutionConfig extractExecutionConfig(int argc, char **argv) = 0;

        bool onStateRecvAddr;

        bool onYellowCmdSendAddr;
        bool onYellowDebugSendAddr;

        bool onBlueCmdSendAddr;
        bool onBlueDebugSendAddr;

        bool onCtrlRecvAddr;

        bool onStatePort;
        bool onYellowCmdPort;
        bool onYellowDebugPort;
        bool onBlueCmdPort;
        bool onBlueDebugPort;
        bool onCtrlPort;

        bool onTeamType;
        bool onSideAttackType;
        bool onTimeExecutionType;
        bool onEnvironmentType;
        bool onDurationType;
        bool onMatchFinishType;

        bool onTeamInitialPositionPath;
    };

};

#endif //VSS_CORE_ISTDININTERPRETER_H
