//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ICONTROLSENDER_H
#define VSS_CORE_ICONTROLSENDER_H

#include <Domain/Address.h>
#include <Domain/ExecutionConfig.h>
#include "Domain/Control.h"

namespace vss {

    class IControlSender {
    public:
        virtual void createSocket(ExecutionConfig&) = 0;
        virtual void createSocket(Address) = 0;
        virtual void createSocket() = 0;
        virtual void closeSocket() = 0;
        virtual void sendControl(Control) = 0;
    };

}

#endif //VSS_CORE_ICONTROLSENDER_H
