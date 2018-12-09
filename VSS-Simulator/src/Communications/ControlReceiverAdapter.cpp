//
// Created by johnathan on 07/07/18.
//

#include "Domain/Constants.h"
#include <Communications/ControlReceiver.h>
#include <Helpers/Math.h>
#include "Communications/ControlReceiverAdapter.h"

ControlReceiverAdapter::ControlReceiverAdapter(vss::ExecutionConfig *executionConfig, Physics* physics, bool *paused){
    this->executionConfig = executionConfig;
    this->physics = physics;
    this->paused = paused;
}

void ControlReceiverAdapter::loop() {
    controlReceiver = new vss::ControlReceiver();

    if(hasACustomAddress())
        controlReceiver->createSocket(executionConfig->ctrlRecvAddr);
    else
        controlReceiver->createSocket();

    while(true){
        auto control = controlReceiver->receiveControl();

        *paused = control.paused;

        if(!*paused) {
            vector<btVector3> positions;
            vector<btScalar> orientations;

            for(int i = 0; i < control.teamYellow.size(); i++) {
                positions.push_back( btVector3( control.teamYellow[i].x, 4, control.teamYellow[i].y ));
                orientations.push_back(btScalar(Math::degreeToRadian(control.teamYellow[i].angle)));
            }

            for(int i = 0; i < control.teamBlue.size(); i++) {
                positions.push_back( btVector3( control.teamBlue[i].x, 4, control.teamBlue[i].y ));
                orientations.push_back(btScalar(Math::degreeToRadian(control.teamBlue[i].angle)));
            }

            physics->setRobotsPose( positions, orientations );
            physics->setBallPosition(btVector3(control.ball.x, 4, control.ball.y));
        }
    }
}

bool ControlReceiverAdapter::hasACustomAddress() {
    if(executionConfig->ctrlRecvAddr.getIp() != vss::DEFAULT_CTRL_RECV_ADDR)
        return true;

    if(executionConfig->ctrlRecvAddr.getPort() != vss::DEFAULT_CTRL_PORT)
        return true;

    return false;
}


