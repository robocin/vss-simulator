//
// Created by johnathan on 27/05/18.
//

#include "Domain/WheelsCommand.h"

namespace vss{
    WheelsCommand::WheelsCommand(){
        leftVel = 0;
        rightVel = 0;
    }

    WheelsCommand::WheelsCommand(float leftVel, float rightVel) {
        this->leftVel = leftVel;
        this->rightVel = rightVel;
    }

    std::ostream &operator<<(std::ostream &os, const WheelsCommand &wheelsCommand) {
        return os << "WheelsCommand(" << wheelsCommand.leftVel << ", " << wheelsCommand.rightVel << ")";;
    }
}

