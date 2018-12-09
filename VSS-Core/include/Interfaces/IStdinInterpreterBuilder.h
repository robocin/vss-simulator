//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_ISTDININTERPRETERBUILDER_H
#define VSS_CORE_ISTDININTERPRETERBUILDER_H

#include "Interfaces/IStdinInterpreter.h"

namespace vss {

    class IStdinInterpreterBuilder {
    public:
        virtual IStdinInterpreter* buildInterpreter() = 0;

        virtual IStdinInterpreterBuilder* onStateRecvAddr() = 0;
        virtual IStdinInterpreterBuilder* onYellowCmdSendAddr() = 0;
        virtual IStdinInterpreterBuilder* onYellowDebugSendAddr() = 0;
        virtual IStdinInterpreterBuilder* onBlueCmdSendAddr() = 0;
        virtual IStdinInterpreterBuilder* onBlueDebugSendAddr() = 0;
        virtual IStdinInterpreterBuilder* onCtrlRecvAddr() = 0;

        virtual IStdinInterpreterBuilder* onStatePort() = 0;
        virtual IStdinInterpreterBuilder* onYellowCmdPort() = 0;
        virtual IStdinInterpreterBuilder* onYellowDebugPort() = 0;
        virtual IStdinInterpreterBuilder* onBlueCmdPort() = 0;
        virtual IStdinInterpreterBuilder* onBlueDebugPort() = 0;
        virtual IStdinInterpreterBuilder* onCtrlPort() = 0;

        virtual IStdinInterpreterBuilder* onTeamType() = 0;
        virtual IStdinInterpreterBuilder* onSideAttackType() = 0;
        virtual IStdinInterpreterBuilder* onTimeExecutionType() = 0;
        virtual IStdinInterpreterBuilder* onEnvironmentType() = 0;
        virtual IStdinInterpreterBuilder* onDurationType() = 0;
        virtual IStdinInterpreterBuilder* onMatchFinishType() = 0;

        virtual IStdinInterpreterBuilder* onTeamInitialPositionPath() = 0;
    };

};

#endif //VSS_CORE_ISTDININTERPRETERBUILDER_H
