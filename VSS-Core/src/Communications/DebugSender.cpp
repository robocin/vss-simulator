//
// Created by johnathan on 29/05/18.
//

#include <iostream>
#include <Helpers/DebugMapper.h>
#include <Domain/Constants.h>
#include <Communications/DebugSender.h>

#include "Communications/DebugSender.h"

namespace vss {

    DebugSender::DebugSender() {
        address = Address();
    }

    void DebugSender::createSocket(ExecutionConfig &exeConfig) {
        setupAddress(exeConfig);
        connect();
    }

    void DebugSender::createSocket(Address address) {
        this->address = address;
        std::cout << "Debug Sender Connected: " << address.getFullAddress() << std::endl;
        connect();
    }

    void DebugSender::createSocket(TeamType teamType) {
        setupAddress(teamType);
        connect();
    }

    void DebugSender::sendDebug(Debug debug) {
        std::string msg_str;
        auto globalDebug = DebugMapper::debugToGlobalDebug(debug);

        globalDebug.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
        socket->send( request );
    }

    void DebugSender::setupAddress(TeamType teamType) {
        if(teamType == TeamType::Yellow){
            address = Address(DEFAULT_DEBUG_SEND_ADDR, DEFAULT_DEBUG_YELLOW_PORT);
            std::cout << "Yellow Debug Sender Connected: " << address.getFullAddress() << std::endl;
        }else{
            address = Address(DEFAULT_DEBUG_SEND_ADDR, DEFAULT_DEBUG_BLUE_PORT);
            std::cout << "Blue Debug Sender Connected: " << address.getFullAddress() << std::endl;
        }
    }

    void DebugSender::setupAddress(ExecutionConfig &exeConfig) {
        if(exeConfig.teamType == TeamType::Yellow){
            address = exeConfig.debugYellowSendAddr;
            std::cout << "Yellow Debug Sender Connected: " << address.getFullAddress() << std::endl;
        }else{
            address = exeConfig.debugBlueSendAddr;
            std::cout << "Blue Debug Sender Connected: " << address.getFullAddress() << std::endl;
        }
    }

    void DebugSender::connect() {
        try {
            context = new zmq::context_t( 1 );
            socket = new zmq::socket_t( *context, ZMQ_PAIR );

            socket->connect(address.getFullAddress().c_str());
        }
        catch(zmq::error_t& e) {
            std::cout << "Error: " << e.what() << " " << this->address.getFullAddress() << std::endl;
            throw e;
        }
    }

    void DebugSender::closeSocket() {
        socket->close();
    }

}