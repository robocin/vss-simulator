//
// Created by johnathan on 01/07/18.
//

#include <Domain/TimeExecutionType.h>
#include <string>

namespace vss {

    std::string toDescription(TimeExecutionType timeExecutionType) {
        switch (timeExecutionType){
            case TimeExecutionType::Normal:
                return "Normal";
            case TimeExecutionType::Fast:
                return "Fast";
            default:
                return "Normal";
        }
    }

    TimeExecutionType toTimeExecutionType(std::string timeExecutionType) {
        if(timeExecutionType == "Normal")
            return TimeExecutionType::Normal;

        if(timeExecutionType == "Fast")
            return TimeExecutionType::Fast;

        return TimeExecutionType::Normal;
    }

};