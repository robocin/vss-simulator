//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_COMMANDSENDER_H
#define VSS_CORE_COMMANDSENDER_H

#include <Interfaces/ICommandSender.h>
#include <zmq.hpp>
#include "Domain/TeamType.h"
#include "Domain/Command.h"

namespace vss {

    class CommandSender : public ICommandSender {
    public:
        CommandSender();

        void createSocket(ExecutionConfig&) override;
        void createSocket(Address) override;
        void createSocket(TeamType) override;
        void closeSocket() override;
        void sendCommand(Command) override;

    protected:
        void setupAddress(TeamType);
        void setupAddress(ExecutionConfig&);
        void connect();

        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

}

#endif //VSS_CORE_COMMANDSENDER_H
