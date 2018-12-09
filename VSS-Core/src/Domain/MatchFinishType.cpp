//
// Created by johnathan on 06/07/18.
//

#include <string>
#include <Domain/MatchFinishType.h>

namespace vss {

    std::string toDescription(MatchFinishType matchFinishType) {
        switch(matchFinishType){
            case MatchFinishType::TenGoalsDifference:
                return "TenGoalsDifference";
            case MatchFinishType::TimeUp:
                return "TimeUp";
            default:
                return "TenGoalsDifference";
        }
    }

    MatchFinishType toMatchFinishType(std::string matchFinishType) {
        if(matchFinishType == "TenGoalsDifference")
            return MatchFinishType::TenGoalsDifference;

        if(matchFinishType == "TimeUp")
            return MatchFinishType::TimeUp;

        return MatchFinishType::TenGoalsDifference;
    }

};