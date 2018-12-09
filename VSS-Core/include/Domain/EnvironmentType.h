//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_ENVIRONMENTTYPE_H
#define VSS_CORE_ENVIRONMENTTYPE_H

namespace vss {

    enum EnvironmentType{
        Simulation = 0,
        Real = 1
    };

    std::string toDescription(EnvironmentType);
    EnvironmentType toEnvironmentType(std::string);

};

#endif //VSS_CORE_ENVIRONMENTTYPE_H