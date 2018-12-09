//
// Created by john on 01/09/18.
//

#include <Communications/CommandReceiverAdapter.h>
#include <Communications/CommandReceiver.h>
#include <Domain/Constants.h>
#include <Sir.h>

CommandReceiverAdapter::CommandReceiverAdapter(vss::ExecutionConfig *executionConfig, vector<Command>* commands, bool *paused) {
    this->executionConfig = executionConfig;
    this->commands = commands;
    this->paused = paused;
}

void CommandReceiverAdapter::loop(vss::TeamType teamType) {
    commandReceiver = new vss::CommandReceiver();

    if(hasACustomAddress())
        if(teamType == vss::TeamType::Yellow)
            commandReceiver->createSocket(executionConfig->cmdYellowRecvAddr);
        else
            commandReceiver->createSocket(executionConfig->cmdBlueRecvAddr);
    else
        commandReceiver->createSocket(teamType);

    if(teamType == vss::TeamType::Yellow){
        while(true) {
            if(*paused){
                usleep(500000);
                continue;
            }

            auto command = commandReceiver->receiveCommand();

            for(unsigned int i = 0; i < command.commands.size() && i < 3; i++) {
                commands->at( i ) = Command(static_cast<float>(command.commands[i].leftVel + 0.001),
                                           static_cast<float>(command.commands[i].rightVel + 0.001));
            }
        }
    }else{
        while(true) {
            if(*paused){
                usleep(500000);
                continue;
            }

            auto command = commandReceiver->receiveCommand();

            for(unsigned int i = 0; i < command.commands.size() && i < 3; i++) {
                commands->at( i + 3 ) = Command(static_cast<float>(command.commands[i].leftVel + 0.001),
                                            static_cast<float>(command.commands[i].rightVel + 0.001));
            }
        }
    }
}

bool CommandReceiverAdapter::hasACustomAddress() {
    if(executionConfig->ctrlRecvAddr.getIp() != vss::DEFAULT_CMD_RECV_ADDR)
        return true;

    if(executionConfig->ctrlRecvAddr.getPort() != vss::DEFAULT_CMD_BLUE_PORT && executionConfig->ctrlRecvAddr.getPort() != vss::DEFAULT_CMD_YELLOW_PORT)
        return true;

    return false;
}

