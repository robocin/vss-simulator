//
// Created by johnathan on 06/07/18.
//

#ifndef VSS_CORE_EXECUTIONTYPE_H
#define VSS_CORE_EXECUTIONTYPE_H

#include <string>

namespace vss {

    enum DurationType{
        TenMinutes = 0,
        UnlimitedMinutes = 1
    };

    std::string toDescription(DurationType);
    DurationType toDurationType(std::string);

}

#endif //VSS_CORE_EXECUTIONTYPE_H
