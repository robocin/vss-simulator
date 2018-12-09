//
// Created by john on 01/09/18.
//

#ifndef VSS_SIMULATOR_ICOMMANDRECEIVERADAPTER_H
#define VSS_SIMULATOR_ICOMMANDRECEIVERADAPTER_H

#include <Domain/TeamType.h>

class ICommandReceiverAdapter {
public:
    virtual void loop(vss::TeamType) = 0;
};

#endif //VSS_SIMULATOR_ICOMMANDRECEIVERADAPTER_H
