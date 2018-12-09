//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_TIMEEXECUTIONTYPE_H
#define VSS_CORE_TIMEEXECUTIONTYPE_H

#include <string>

namespace vss {

    enum TimeExecutionType {
        Normal = 0,
        Fast = 1
    };

    std::string toDescription(TimeExecutionType);
    TimeExecutionType toTimeExecutionType(std::string);

};

#endif //VSS_CORE_TIMEEXECUTIONTYPE_H
