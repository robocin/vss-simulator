/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include <Domain/ExecutionConfig.h>
#include <Communications/StateReceiverAdapter.h>
#include <Domain/Constants.h>

#include "StateReceiverAdapter.h"
#include "Communications/StateReceiver.h"
#include "Math.h"

StateReceiverAdapter::StateReceiverAdapter( vss::Pose *ball, std::vector<Robot3d> *robots, vss::ExecutionConfig *executionConfig ){
    this->ball = ball;
    this->robots = robots;
    this->executionConfig = executionConfig;
}

void StateReceiverAdapter::loop(){
    stateReceiver = new vss::StateReceiver();

    if(hasCustomAddress())
        stateReceiver->createSocket(executionConfig->stateRecvAddr);
    else
        stateReceiver->createSocket();

    while(true) {
        auto state = stateReceiver->receiveState(vss::FieldTransformationType::None);

        auto newBall = Core::bulletToGlut( vss::Pose( state.ball.x, state.ball.y, 0.0 ) );
        ball->x = newBall.x;
        ball->y = newBall.y;

        for(int i = 0; i < 3; i++) {
            robots->at( i ).pose = Core::bulletToGlut( vss::Pose( state.teamYellow[i].x, state.teamYellow[i].y, state.teamYellow[i].angle));
            robots->at( i + 3 ).pose = Core::bulletToGlut( vss::Pose( state.teamBlue[i].x, state.teamBlue[i].y, state.teamBlue[i].angle));
        }
    }
}

bool StateReceiverAdapter::hasCustomAddress() {
    if(executionConfig->stateRecvAddr.getIp() != vss::DEFAULT_STATE_RECV_ADDR)
        return true;

    if(executionConfig->stateRecvAddr.getPort() != vss::DEFAULT_STATE_PORT)
        return true;

    return false;
}
