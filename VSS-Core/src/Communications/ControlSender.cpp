//
// Created by johnathan on 31/05/18.
//

#include <Communications/ControlSender.h>
#include <Helpers/ControlMapper.h>
#include <Domain/Constants.h>

namespace vss {

    ControlSender::ControlSender() {
        address = Address(DEFAULT_CTRL_SEND_ADDR, DEFAULT_CTRL_PORT);
    }

    void ControlSender::createSocket(ExecutionConfig &exeConfig) {
        this->address = exeConfig.ctrlSendAddr;
        connect();
    }

    void ControlSender::createSocket(Address address) {
        this->address = address;
        connect();
    }

    void ControlSender::createSocket() {
        connect();
    }

    void ControlSender::sendControl(Control control) {
        auto userControl = vss::ControlMapper::controlToUserControl(control);
        std::string msg_str;
        userControl.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());

        socket->send( request );
    }

    void ControlSender::connect() {
        try {
            context = new zmq::context_t( 1 );
            socket = new zmq::socket_t( *context, ZMQ_PUB );

            std::cout << "Control Sender Connected: " << address << std::endl;
            socket->bind(address.getFullAddress().c_str());
        }
        catch(zmq::error_t& e) {
            std::cout << "Error: " << e.what() << " " << this->address.getFullAddress() << std::endl;
            throw e;
        }
    }

    void ControlSender::closeSocket() {
        socket->close();
    }

}