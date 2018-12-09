//
// Created by johnathan on 27/05/18.
//

#include <Helpers/CommandMapper.h>
#include <Domain/Constants.h>
#include <Communications/CommandSender.h>

#include "Communications/CommandSender.h"

namespace vss{

    CommandSender::CommandSender(){
        address = Address();
    }

    void CommandSender::createSocket(ExecutionConfig &exeConfig) {
        setupAddress(exeConfig);
        connect();
    }

    void CommandSender::createSocket(Address address) {
        this->address = address;
        std::cout << "Team Sender Connected: " << address.getFullAddress() << std::endl;
        connect();
    }

    void CommandSender::createSocket(TeamType teamType) {
        setupAddress(teamType);
        connect();
    }

    void CommandSender::sendCommand(Command command) {
        auto globalCommands = CommandMapper::commandToGlobalCommands(command);

        std::string msg_str;
        globalCommands.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
        socket->send( request );
    }

    void CommandSender::setupAddress(TeamType teamType) {
        if(teamType == TeamType::Yellow){
            address = Address(DEFAULT_CMD_SEND_ADDR, DEFAULT_CMD_YELLOW_PORT);
            std::cout << "Yellow Team Sender Connected: " << address.getFullAddress() << std::endl;
        }else{
            address = Address(DEFAULT_CMD_SEND_ADDR, DEFAULT_CMD_BLUE_PORT);
            std::cout << "Blue Team Sender Connected: " << address.getFullAddress() << std::endl;
        }
    }

    void CommandSender::setupAddress(ExecutionConfig &exeConfig) {
        if(exeConfig.teamType == TeamType::Yellow){
            address = exeConfig.cmdYellowSendAddr;
            std::cout << "Yellow Team Sender Connected: " << address.getFullAddress() << std::endl;
        }else{
            address = exeConfig.cmdBlueRecvAddr;
            std::cout << "Blue Team Sender Connected: " << address.getFullAddress() << std::endl;
        }
    }

    void CommandSender::connect() {
        try {
            context = new zmq::context_t(1);
            socket = new zmq::socket_t(*context, ZMQ_PAIR);
            socket->connect(address.getFullAddress().c_str());
        }
        catch(zmq::error_t& e) {
            std::cout << "Error: " << e.what() << " " << this->address.getFullAddress() << std::endl;
            throw e;
        }
    }

    void CommandSender::closeSocket() {
        socket->close();
    }

}
