//
// Created by john on 01/09/18.
//

#include <Communications/StateSenderAdapter.h>
#include <Domain/State.h>
#include <Helpers/Math.h>
#include <Communications/StateSender.h>
#include <Domain/Constants.h>

StateSenderAdapter::StateSenderAdapter(vss::ExecutionConfig* executionConfig, Physics *physics) {
    this->physics = physics;
    this->executionConfig = executionConfig;

    stateSender = new vss::StateSender();

    if(hasACustomAddress())
        stateSender->createSocket(executionConfig->stateSendAddr);
    else
        stateSender->createSocket();
}

void StateSenderAdapter::send() {
    vss::State state;
    vector<RobotPhysics*> listRobots = physics->getAllRobots();

    state.ball.x = physics->getBallPosition().getX();
    state.ball.y = physics->getBallPosition().getZ();
    state.ball.speedX = physics->getBallVelocity().getX();
    state.ball.speedY = physics->getBallVelocity().getZ();

    for(int i = 0; i < 3; i++) {
        btVector3 posRobot = getRobotPosition( listRobots.at( i ));
        btVector3 velRobot = getRobotVelocity( listRobots.at( i ));
        float rads = atan2( getRobotOrientation( listRobots.at( i )).getZ(), getRobotOrientation( listRobots.at( i )).getX());

        vss::Robot robot;

        robot.x = posRobot.getX();
        robot.y = posRobot.getZ();
        robot.angle = Math::radianToDegree(rads);
        robot.speedX = velRobot.getX();
        robot.speedY = velRobot.getZ();
        robot.speedAngle = 0;

        state.teamYellow.push_back(robot);
    }

    for(int i = 0; i < 3; i++) {
        btVector3 posRobot = getRobotPosition( listRobots.at( i + 3 ));
        btVector3 velRobot = getRobotVelocity( listRobots.at( i + 3 ));
        float rads = atan2( getRobotOrientation( listRobots.at( i + 3 )).getZ(), getRobotOrientation( listRobots.at( i + 3 )).getX());

        vss::Robot robot;

        robot.x = posRobot.getX();
        robot.y = posRobot.getZ();
        robot.angle = Math::radianToDegree(rads);
        robot.speedX = velRobot.getX();
        robot.speedY = velRobot.getZ();
        robot.speedAngle = 0;

        state.teamBlue.push_back(robot);
    }

    stateSender->sendState(state);
}

btVector3 StateSenderAdapter::getRobotPosition( RobotPhysics* robot ){
    btTransform transTemp;
    robot->getRigidBody()->getMotionState()->getWorldTransform( transTemp );
    return transTemp.getOrigin();
}

btVector3 StateSenderAdapter::getRobotOrientation( RobotPhysics* robot ){
    btVector3 forwardVec = robot->getRaycast()->getForwardVector();
    return forwardVec;
}

btVector3 StateSenderAdapter::getRobotVelocity( RobotPhysics* robot ){
    return robot->getRigidBody()->getLinearVelocity();
}

bool StateSenderAdapter::hasACustomAddress() {
    if(executionConfig->stateSendAddr.getIp() != vss::DEFAULT_STATE_SEND_ADDR)
        return true;

    if(executionConfig->stateSendAddr.getPort() != vss::DEFAULT_STATE_PORT)
        return true;

    return false;
}
