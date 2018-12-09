//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_CONTROLRECEIVER_H
#define VSS_CORE_CONTROLRECEIVER_H

#include <Interfaces/IControlReceiver.h>
#include <zmq.hpp>

namespace vss {

    class ControlReceiver : public IControlReceiver {
    public:
        ControlReceiver();

        void createSocket(ExecutionConfig&) override;
        void createSocket(Address) override;
        void createSocket() override;
        void closeSocket() override;
        Control receiveControl() override;

    protected:
        void connect();

        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

}

#endif //VSS_CORE_CONTROLRECEIVER_H
