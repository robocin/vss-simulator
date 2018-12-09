//
// Created by johnathan on 06/07/18.
//

#include <Domain/DurationType.h>

namespace vss {

    std::string toDescription(DurationType durationType) {
        switch(durationType){
            case DurationType::TenMinutes:
                return "TenMinutes";
            case DurationType::UnlimitedMinutes:
                return "UnlimitedMinutes";
            default:
                return "TenMinutes";
        }
    }

    DurationType toDurationType(std::string durationType) {
        if(durationType == "TenMinutes")
            return DurationType::TenMinutes;

        if(durationType == "UnlimitedMinutes")
            return DurationType::UnlimitedMinutes;

        return DurationType::TenMinutes;
    }

};