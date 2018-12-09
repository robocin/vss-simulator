//
// Created by john on 01/09/18.
//

#ifndef VSS_SIMULATOR_COMMANDRECEIVERADAPTER_H
#define VSS_SIMULATOR_COMMANDRECEIVERADAPTER_H

#include <Interfaces/ICommandReceiverAdapter.h>
#include <Domain/ExecutionConfig.h>
#include <Interfaces/ICommandReceiver.h>
#include <Sir.h>

class CommandReceiverAdapter : public ICommandReceiverAdapter {
public:
    CommandReceiverAdapter(vss::ExecutionConfig*, std::vector<Command>*, bool*);

    void loop(vss::TeamType) override;

    vss::ICommandReceiver *commandReceiver;
    vss::ExecutionConfig *executionConfig;
    std::vector<Command> *commands;
    bool *paused;

protected:
    bool hasACustomAddress();
};

#endif //VSS_SIMULATOR_COMMANDRECEIVERADAPTER_H
