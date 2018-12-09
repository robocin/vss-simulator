//
// Created by johnathan on 31/05/18.
//

#include <Domain/Control.h>

namespace vss {

    Control::Control() {
        paused = false;
    }

    Control::Control(bool paused, Ball ball, std::vector<Robot> teamYellow, std::vector<Robot> teamBlue) {
        this->paused = paused;
        this->ball = ball;
        this->teamYellow = teamYellow;
        this->teamBlue = teamBlue;
    }

    std::ostream &operator<<(std::ostream &os, const Control &control) {
        os << "Control {" << std::endl;

        os << "\tPaused: " << control.paused << std::endl;
        os << "\tBall: " << control.ball << std::endl;
        os << "\tTeamYellow:" << std::endl;

        for(unsigned int i = 0 ; i < control.teamYellow.size() ; i++){
            os << "\t\t" << control.teamYellow[i] << std::endl;
        }

        os << "\tTeamBlue:" << std::endl;

        for(unsigned int i = 0 ; i < control.teamBlue.size() ; i++){
            os << "\t\t" << control.teamBlue[i] << std::endl;
        }

        os << "}";

        return os;
    }

}
