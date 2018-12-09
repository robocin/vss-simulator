//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_CONTROLSENDER_H
#define VSS_CORE_CONTROLSENDER_H

#include <Interfaces/IControlSender.h>
#include <zmq.hpp>

namespace vss {

    class ControlSender : public IControlSender {
    public:
        ControlSender();

        void createSocket(ExecutionConfig&) override;
        void createSocket(Address) override;
        void createSocket() override;
        void closeSocket() override;
        void sendControl(Control) override;

    protected:
        void connect();

        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

}

#endif //VSS_CORE_CONTROLSENDER_H
