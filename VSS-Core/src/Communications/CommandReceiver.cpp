//
// Created by johnathan on 28/05/18.
//

#include <Communications/CommandReceiver.h>
#include <Helpers/CommandMapper.h>
#include <Domain/Constants.h>

namespace vss{

    CommandReceiver::CommandReceiver() {
        address = Address();
    }

    void CommandReceiver::createSocket(ExecutionConfig &exeConfig) {
        setupAddress(exeConfig);
        connect();
    }

    void CommandReceiver::createSocket(Address address) {
        this->address = address;
        std::cout << "Team Receiver Connected: " << address.getFullAddress() << std::endl;
        connect();
    }

    void CommandReceiver::createSocket(TeamType teamType) {
        setupAddress(teamType);
        connect();
    }

    Command CommandReceiver::receiveCommand() {
        vss_command::Global_Commands globalCommands;
        zmq::message_t request;
        socket->recv( &request );

        std::string msg_str( static_cast<char*>(request.data()), request.size());
        globalCommands.ParseFromString( msg_str );

        return CommandMapper::globalCommandsToCommand(globalCommands);
    }

    void CommandReceiver::setupAddress(TeamType teamType) {
        if(teamType == TeamType::Yellow){
            address = Address(DEFAULT_CMD_RECV_ADDR, DEFAULT_CMD_YELLOW_PORT);
            std::cout << "Yellow Team Receiver Connected: " << address.getFullAddress() << std::endl;
        }else{
            address = Address(DEFAULT_CMD_RECV_ADDR, DEFAULT_CMD_BLUE_PORT);
            std::cout << "Blue Team Receiver Connected: " << address.getFullAddress() << std::endl;
        }
    }

    void CommandReceiver::setupAddress(ExecutionConfig &exeConfig) {
        if(exeConfig.teamType == TeamType::Yellow){
            address = exeConfig.cmdYellowRecvAddr;
            std::cout << "Yellow Team Receiver Connected: " << address.getFullAddress() << std::endl;
        }else{
            address = exeConfig.cmdBlueRecvAddr;
            std::cout << "Blue Team Receiver Connected: " << address.getFullAddress() << std::endl;
        }
    }

    void CommandReceiver::connect() {
        try {
            context = new zmq::context_t( 1 );
            socket = new zmq::socket_t( *context, ZMQ_PAIR );
            socket->bind(address.getFullAddress().c_str());
        }
        catch(zmq::error_t& e) {
            std::cout << "Error: " << e.what() << " " << this->address.getFullAddress() << std::endl;
            throw e;
        }
    }

    void CommandReceiver::closeSocket() {
        socket->close();
    }

}