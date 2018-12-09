//
// Created by johnathan on 06/07/18.
//

#ifndef VSS_CORE_MATCHFINISHTYPE_H
#define VSS_CORE_MATCHFINISHTYPE_H

#include <string>

namespace vss {

    enum MatchFinishType{
        TenGoalsDifference = 0,
        TimeUp = 1
    };

    std::string toDescription(MatchFinishType);
    MatchFinishType toMatchFinishType(std::string);

}

#endif //VSS_CORE_MATCHFINISHTYPE_H
