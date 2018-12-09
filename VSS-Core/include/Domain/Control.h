//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_CONTROL_H
#define VSS_CORE_CONTROL_H

#include <vector>
#include "Ball.h"
#include "Robot.h"

namespace vss {

    class Control {
    public:
        Control();
        Control(bool paused, Ball ball, std::vector<Robot> teamYellow, std::vector<Robot> teamBlue);

        friend std::ostream& operator<<(std::ostream& os, const Control& control);

        bool paused;
        Ball ball;
        std::vector<Robot> teamYellow;
        std::vector<Robot> teamBlue;
    };

}

#endif //VSS_CORE_CONTROL_H
