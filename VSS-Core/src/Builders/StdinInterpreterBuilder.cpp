//
// Created by johnathan on 01/07/18.
//

#include <Builders/StdinInterpreterBuilder.h>
#include <Interpreters/StdinInterpreter.h>

namespace vss {

    StdinInterpreterBuilder::StdinInterpreterBuilder() {
        stdinInterpreter = new StdinInterpreter();
    }

    IStdinInterpreter* StdinInterpreterBuilder::buildInterpreter() {
        return stdinInterpreter;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onStateRecvAddr() {
        stdinInterpreter->onStateRecvAddr = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowCmdSendAddr() {
        stdinInterpreter->onYellowCmdSendAddr = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowDebugSendAddr() {
        stdinInterpreter->onYellowDebugSendAddr = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueCmdSendAddr() {
        stdinInterpreter->onBlueCmdSendAddr = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueDebugSendAddr() {
        stdinInterpreter->onBlueDebugSendAddr = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onCtrlRecvAddr() {
        stdinInterpreter->onCtrlRecvAddr = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onTeamType() {
        stdinInterpreter->onTeamType = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowCmdPort() {
        stdinInterpreter->onYellowCmdPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onYellowDebugPort() {
        stdinInterpreter->onYellowDebugPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueCmdPort() {
        stdinInterpreter->onBlueCmdPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onBlueDebugPort() {
        stdinInterpreter->onBlueDebugPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onCtrlPort() {
        stdinInterpreter->onCtrlPort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onSideAttackType() {
        stdinInterpreter->onSideAttackType = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onTimeExecutionType() {
        stdinInterpreter->onTimeExecutionType = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onStatePort() {
        stdinInterpreter->onStatePort = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onEnvironmentType() {
        stdinInterpreter->onEnvironmentType = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onDurationType() {
        stdinInterpreter->onDurationType = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onMatchFinishType() {
        stdinInterpreter->onMatchFinishType = true;
        return this;
    }

    IStdinInterpreterBuilder *StdinInterpreterBuilder::onTeamInitialPositionPath() {
        stdinInterpreter->onTeamInitialPositionPath = true;
        return this;
    }

};