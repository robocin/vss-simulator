//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_SIDEATTACKTYPE_H
#define VSS_CORE_SIDEATTACKTYPE_H

#include <string>

namespace vss {

    enum SideAttackType{
        Left = 0,
        Right = 1
    };

    std::string toDescription(SideAttackType);
    SideAttackType toSideAttackType(std::string);

};

#endif //VSS_CORE_SIDEATTACKTYPE_H
