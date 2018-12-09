//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_STATESENDER_H
#define VSS_CORE_STATESENDER_H

#include <zmq.hpp>
#include <Interfaces/IStateSender.h>

namespace vss{

    class StateSender : public IStateSender  {
    public:
        StateSender();

        void createSocket(ExecutionConfig&) override;
        void createSocket(Address) override;
        void createSocket() override;
        void closeSocket() override;
        void sendState(State) override;

    protected:
        void connect();

        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

}

#endif //VSS_CORE_STATESENDER_H
