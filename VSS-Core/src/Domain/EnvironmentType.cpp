//
// Created by johnathan on 01/07/18.
//

#include <string>
#include <Domain/EnvironmentType.h>

namespace vss {

    std::string toDescription(EnvironmentType environmentType) {
        switch (environmentType){
            case EnvironmentType::Simulation:
                return "Simulation";
            case EnvironmentType::Real:
                return "Real";
            default:
                return "Simulation";
        }
    }

    EnvironmentType toEnvironmentType(std::string environmentType) {
        if(environmentType == "Simulation")
            return EnvironmentType::Simulation;

        if(environmentType == "Real")
            return EnvironmentType::Real;

        return EnvironmentType::Simulation;
    }

};