//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_STATEMAPPER_H
#define VSS_CORE_STATEMAPPER_H

#include <protos/state.pb.h>
#include "Domain/State.h"
#include "Domain/Robot.h"
#include "Domain/Ball.h"

namespace vss {

    namespace StateMapper {

        State globalStateToState(vss_state::Global_State globalState);
        Robot robotStateToRobot(vss_state::Robot_State robotState);
        Ball ballStateToBall(vss_state::Ball_State ballState);
        vss_state::Global_State stateToGlobalState(State state);
        void setupRobotState(vss_state::Robot_State *robotState, Robot robot);
        void setupBallState(vss_state::Ball_State *ballState, Ball ball);

    }

}

#endif //VSS_CORE_STATEMAPPER_H
