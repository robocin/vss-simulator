//
// Created by johnathan on 29/05/18.
//

#ifndef VSS_CORE_DEBUGSENDER_H
#define VSS_CORE_DEBUGSENDER_H

#include <Interfaces/IDebugSender.h>
#include <zmq.hpp>

namespace vss {

    class DebugSender : public IDebugSender {
    public:
        DebugSender();

        void createSocket(ExecutionConfig&) override;
        void createSocket(Address) override;
        void createSocket(TeamType) override;
        void closeSocket() override;
        void sendDebug(Debug) override;

    protected:
        void setupAddress(TeamType);
        void setupAddress(ExecutionConfig&);
        void connect();

        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

}

#endif //VSS_CORE_DEBUGSENDER_H
