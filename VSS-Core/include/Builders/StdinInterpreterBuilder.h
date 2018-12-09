//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_FLUENTSTDININTERPRETERBUILDER_H
#define VSS_CORE_FLUENTSTDININTERPRETERBUILDER_H

#include <Interfaces/IStdinInterpreterBuilder.h>

namespace vss {

    class StdinInterpreterBuilder : public IStdinInterpreterBuilder {
    public:
        StdinInterpreterBuilder();

        IStdinInterpreter* buildInterpreter() override;

        IStdinInterpreterBuilder* onStateRecvAddr() override;

        IStdinInterpreterBuilder* onYellowCmdSendAddr() override;
        IStdinInterpreterBuilder* onYellowDebugSendAddr() override;

        IStdinInterpreterBuilder* onBlueCmdSendAddr() override;
        IStdinInterpreterBuilder* onBlueDebugSendAddr() override;

        IStdinInterpreterBuilder* onCtrlRecvAddr() override;

        IStdinInterpreterBuilder* onStatePort() override;
        IStdinInterpreterBuilder* onYellowCmdPort() override;
        IStdinInterpreterBuilder* onYellowDebugPort() override;
        IStdinInterpreterBuilder* onBlueCmdPort() override;
        IStdinInterpreterBuilder* onBlueDebugPort() override;
        IStdinInterpreterBuilder* onCtrlPort() override;

        IStdinInterpreterBuilder* onTeamType() override;
        IStdinInterpreterBuilder* onSideAttackType() override;
        IStdinInterpreterBuilder* onTimeExecutionType() override;
        IStdinInterpreterBuilder* onEnvironmentType() override;
        IStdinInterpreterBuilder* onDurationType() override;
        IStdinInterpreterBuilder* onMatchFinishType() override;

        IStdinInterpreterBuilder* onTeamInitialPositionPath() override;

    protected:
        IStdinInterpreter *stdinInterpreter;
    };

};

#endif //VSS_CORE_FLUENTSTDININTERPRETERBUILDER_H
