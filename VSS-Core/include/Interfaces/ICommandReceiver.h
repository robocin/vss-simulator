//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ICOMMANDRECEIVER_H
#define VSS_CORE_ICOMMANDRECEIVER_H

#include <Domain/TeamType.h>
#include <Domain/Address.h>
#include <Domain/ExecutionConfig.h>
#include "Domain/Command.h"

namespace vss {

    class ICommandReceiver {
    public:
        virtual void createSocket(ExecutionConfig&) = 0;
        virtual void createSocket(Address) = 0;
        virtual void createSocket(TeamType) = 0;
        virtual void closeSocket() = 0;
        virtual Command receiveCommand() = 0;
    };

}

#endif //VSS_CORE_ICOMMANDRECEIVER_H
