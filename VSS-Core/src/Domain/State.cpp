#include "Domain/State.h"

namespace vss{
    State::State() { }

    State::State(Ball ball, std::vector<Robot> teamYellow, std::vector<Robot> teamBlue) {
        this->ball = ball;
        this->teamBlue = teamBlue;
        this->teamYellow = teamYellow;
    }

    std::ostream &operator<<(std::ostream &os, const State &state) {
        os << "State {" << std::endl;

        os << "\t" << state.ball << std::endl;
        os << "\tTeamYellow:" << std::endl;

        for(unsigned int i = 0 ; i < state.teamYellow.size() ; i++){
            os << "\t\t" << state.teamYellow[i] << std::endl;
        }

        os << "\tTeamBlue:" << std::endl;

        for(unsigned int i = 0 ; i < state.teamBlue.size() ; i++){
            os << "\t\t" << state.teamBlue[i] << std::endl;
        }

        os << "}";

        return os;
    }
}