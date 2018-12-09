//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_WHEELSCOMMAND_H
#define VSS_CORE_WHEELSCOMMAND_H

#include <iostream>

namespace vss {

    class WheelsCommand {
    public:
        WheelsCommand();
        WheelsCommand(float leftVel, float rightVel);

        friend std::ostream& operator<<(std::ostream& os, const WheelsCommand& wheelsCommand);

        float leftVel;
        float rightVel;
    };

}

#endif //VSS_CORE_WHEELSCOMMAND_H