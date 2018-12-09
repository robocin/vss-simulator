//
// Created by johnathan on 27/05/18.
//

#include <Helpers/StateMapper.h>
#include <Domain/Constants.h>
#include "Communications/StateSender.h"

namespace vss{

    StateSender::StateSender(){
        address = Address(DEFAULT_STATE_SEND_ADDR, DEFAULT_STATE_PORT);
    }

    void StateSender::createSocket(ExecutionConfig &exeConfig) {
        this->address = exeConfig.stateSendAddr;
        connect();
    }

    void StateSender::createSocket(Address address) {
        this->address = address;
        connect();
    }

    void StateSender::createSocket(){
        connect();
    }

    void StateSender::sendState(State state){
        std::string msg_str;
        vss_state::Global_State globalState;

        globalState = StateMapper::stateToGlobalState(state);
        globalState.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());

        socket->send( request );
    }

    void StateSender::connect() {
        try {
            context = new zmq::context_t( 1 );
            socket = new zmq::socket_t( *context, ZMQ_PUB );

            std::cout << "State Sender Connected: " << address << std::endl;
            socket->bind(address.getFullAddress().c_str());
        }
        catch(zmq::error_t& e) {
            std::cout << "Error: " << e.what() << " " << this->address.getFullAddress() << std::endl;
            throw e;
        }
    }

    void StateSender::closeSocket() {
        socket->close();
    }

}