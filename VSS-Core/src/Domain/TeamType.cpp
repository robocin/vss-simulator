//
// Created by johnathan on 01/07/18.
//

#include <string>
#include <Domain/TeamType.h>
#include <iostream>

namespace vss {

    std::string toDescription(TeamType teamType) {
        switch (teamType){
            case TeamType::Yellow:
                return "Yellow";
            case TeamType::Blue:
                return "Blue";
            default:
                return "Yellow";
        }
    }

    TeamType toTeamType(std::string teamType) {
        if(teamType == "Yellow")
            return TeamType::Yellow;

        if(teamType == "Blue")
            return TeamType::Blue;

        return TeamType::Yellow;
    }

};