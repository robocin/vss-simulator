//
// Created by johnathan on 01/07/18.
//

#include <Domain/SideAttackType.h>

namespace vss {

    std::string toDescription(SideAttackType sideAttackType) {
        switch (sideAttackType){
            case SideAttackType::Left:
                return "Left";
            case SideAttackType::Right:
                return "Right";
            default:
                return "Left";
        }
    }

    SideAttackType toSideAttackType(std::string sideAttackType) {
        if(sideAttackType == "Left")
            return SideAttackType::Left;

        if(sideAttackType == "Right")
            return SideAttackType::Right;

        return SideAttackType::Left;
    }

};