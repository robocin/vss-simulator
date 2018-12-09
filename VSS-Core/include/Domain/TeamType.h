//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_TEAMS_H
#define VSS_CORE_TEAMS_H

#include <string>

namespace vss {

    enum TeamType{
        Yellow = 0,
        Blue = 1
    };

    std::string toDescription(TeamType);
    TeamType toTeamType(std::string);

}

#endif //VSS_CORE_TEAMS_H
