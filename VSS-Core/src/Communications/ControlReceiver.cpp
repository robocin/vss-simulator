//
// Created by johnathan on 31/05/18.
//

#include <Communications/ControlReceiver.h>
#include <Helpers/ControlMapper.h>
#include <Domain/Constants.h>

namespace vss {

    ControlReceiver::ControlReceiver() {
        address = Address(DEFAULT_CTRL_RECV_ADDR, DEFAULT_CTRL_PORT);
    }

    void ControlReceiver::createSocket(ExecutionConfig &exeConfig) {
        this->address = exeConfig.ctrlRecvAddr;
        connect();
    }

    void ControlReceiver::createSocket(Address address) {
        this->address = address;
        connect();
    }

    void ControlReceiver::createSocket() {
        connect();
    }

    Control ControlReceiver::receiveControl() {
        vss_control::User_Control userControl;

        zmq::message_t request;
        socket->recv( &request, 0 );

        std::string msg_str( static_cast<char*>(request.data()), request.size());
        userControl.ParseFromString( msg_str );

        return vss::ControlMapper::userControlToControl(userControl);
    }

    void ControlReceiver::connect() {
        try {
            context = new zmq::context_t( 1 );
            socket = new zmq::socket_t( *context, ZMQ_SUB );

            std::cout << "Control Receiver Connected: " << address << std::endl;
            socket->connect(address.getFullAddress().c_str());
            socket->setsockopt( ZMQ_SUBSCRIBE, "", 0 );
        }
        catch(zmq::error_t& e) {
            std::cout << "Error: " << e.what() << " " << this->address.getFullAddress() << std::endl;
            throw e;
        }
    }

    void ControlReceiver::closeSocket() {
        socket->close();
    }

}