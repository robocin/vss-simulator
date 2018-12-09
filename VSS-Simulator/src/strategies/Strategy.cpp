/*
   The MIT License (MIT)

   Copyright (c) 2016 Lucas Borsatto Simão

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
 */

#include "../../include/strategies/Strategy.h"

Strategy::Strategy(){
	areaTarget = 10.f * SIMULATOR_TO_VSS;
	distProjBallWall = 5.f * SIMULATOR_TO_VSS;
	maxDiffRobotPos = 3.5f * SIMULATOR_TO_VSS;

	for(int i = 0; i < 2; i++) {
		framesStopped[i] = 0;
		framesBackward[i] = 0;
	}

	sizeRobot = 8 * SIMULATOR_TO_VSS;
	attackDir = 1;
	deltaTime = 0.001f;
	timeToFullHistory = 0.f;
	numFramesPerSec = 30;
	ballTarget = btVector3( 0, 0, 0 );

	begin_time = clock();
}

Strategy::~Strategy(){
	strategyHistory.clear();
}

void Strategy::runStrategy( vector<RobotStrategy*> robotStrategiesTeam, vector<RobotStrategy*> robotStrategiesAdv, btVector3 ballPos ){
	deltaTime = float( clock () - begin_time ) / CLOCKS_PER_SEC;
	begin_time = clock();
	ballTarget = ballPos;

	this->robotStrategiesTeam = robotStrategiesTeam;
	this->robotStrategiesAdv = robotStrategiesAdv;
	this->ballPos = ballPos;

	if(strategyHistory.size() == numFramesPerSec) {
		updateDynamics();
		calcBallTarget();
	}

	updateFunctions();

	for(int i = 0; i < robotStrategiesTeam.size(); i++) {
		controlLocalStrategy( robotStrategiesTeam[i] );
	}

	updateStrategiesHistory();
}

void Strategy::calcBallTarget(){
	btVector3 proj = 2 * ballPos - strategyHistory[numFramesPerSec / 2 - 1]->getBallPosition();

	if(simulator::FIELD_WIDTH < proj.getX() || proj.getX() < 0 || proj.getZ() < 0 || proj.getZ() > simulator::FIELD_HEIGHT) {
		proj = ballPos;
	}

	ballTarget = proj;
}

void Strategy::updateStrategiesHistory(){

	//Consuming CPU!! Fix it to your PC don't stop
	Strategy* oldStrategy = new Strategy();
	*oldStrategy = *this;

	if(timeToFullHistory < numFramesPerSec) {
		timeToFullHistory++;
		strategyHistory.push_back( oldStrategy );
	}else{
		Strategy* strategyAux = new Strategy();
		for(int i = 0; i < numFramesPerSec; i++) {
			*strategyAux = *((Strategy*)strategyHistory.at( i ));
			*strategyHistory.at( i ) = *oldStrategy;
			*oldStrategy = *strategyAux;
		}

		delete oldStrategy;
		delete strategyAux;
	}
}

void Strategy::updateFunctions(){
	for(int i = 0; i < robotStrategiesTeam.size(); i++) {

		int angRobotBall = robotStrategiesTeam[i]->getPointAngle( ballTarget );
		int distanceRobotBall = (robotStrategiesTeam[i]->getPosition() - ballTarget).length();

		switch(robotStrategiesTeam[i]->getId()) {
		case 0: {
			robotStrategiesTeam[i]->setLocalFunction( LocalFunc::goal );
		} break;
		case 1: {
			robotStrategiesTeam[i]->setLocalFunction( LocalFunc::deffense );
		} break;
		case 2: {
			robotStrategiesTeam[i]->setLocalFunction( LocalFunc::attack );
		} break;
		}
	}
}

void Strategy::controlLocalStrategy( RobotStrategy* robotStrategy ){
	updateTargetPosition( robotStrategy );
	if(!updateTwistAction( robotStrategy ))
		updateLocalFuncAction( robotStrategy );

	updateActionStopped( robotStrategy );

	//robotStrategy->updateCommand(0,0);
}

void Strategy::updateTargetPosition( RobotStrategy* robotStrategy ){
	float zBall = 0.f;
	float xBall = 0.f;

	btStraight stTarget( ballTarget, posGoalpost );

	xBall = ballTarget.getX() - stTarget.getNormalVector().getX() * areaTarget;

	zBall = xBall * stTarget.getInclination() + stTarget.getN();

	robotStrategy->setTargetPosition( btVector3( xBall, 0, zBall ));
}

void Strategy::updateLocalFuncAction( RobotStrategy* robotStrategy ){
	switch(robotStrategy->getLocalFunction()) {
	case LocalFunc::goal: {
		updateGoalStrategyAction( robotStrategy );
	} break;
	case LocalFunc::deffense: {
		updateDeffenseStrategyAction( robotStrategy );
	} break;
	case LocalFunc::attack: {
		updateAttackStrategyAction( robotStrategy );
	} break;
	}
}

void Strategy::updateGoalStrategyAction( RobotStrategy* robotStrategy ){
	btStraight ballGoalSt( btVector3( 0, 0, posGoalpost.getZ()), ballPos );
	btStraight stProjGoal( ballPos, ballTarget );
	float maxVelocity = robotStrategy->getMaxCommand();
	float maxDistTwist = 8.15f * SIMULATOR_TO_VSS;
	float actXPoint = 0.1 * simulator::FIELD_WIDTH;
	float maxZtarget = simulator::FIELD_HEIGHT / 3;
	float minDsBall = 4 * SIMULATOR_TO_VSS;

	btVector3 dsBall = ballTarget - ballPos;

	float distKeeperBall = fabs( ballPos.getX() - actXPoint );
	float zTarget = actXPoint * ballGoalSt.getInclination() + ballGoalSt.getN();

	if(ballPos.getX() < robotStrategy->getPosition().getX()) {
		actXPoint = ballPos.getX();
		zTarget = actXPoint * ballGoalSt.getInclination() + ballGoalSt.getN();
	}else {
		if(minDsBall < dsBall.length()) {
			if(dsBall.getZ() < 0)
				zTarget = ballPos.getZ() - fabs( stProjGoal.getInclination() * distKeeperBall );
			else
				zTarget = ballPos.getZ() + fabs( stProjGoal.getInclination() * distKeeperBall );

			if(dsBall.getX() > 0)
				zTarget = actXPoint * ballGoalSt.getInclination() + ballGoalSt.getN();

			//cout << "z:\t" << ztar << endl;
		}
	}

	if(zTarget > maxZtarget * 2) zTarget = maxZtarget * 2;
	else
	if(zTarget < maxZtarget) zTarget = maxZtarget;

	btVector3 relTargetPos( actXPoint, 0, zTarget );

	robotStrategy->setTargetPosition( relTargetPos );
	float targetXDistance = robotStrategy->getPosition().getX() - robotStrategy->getTargetPosition().getX();

	btVector3 distBall = ballPos - robotStrategy->getPosition();
	if(distBall.length() > maxDistTwist) {
		if(robotStrategy->getPosition().getX() > actXPoint) {
			updateVerticalAlign( robotStrategy );
		}else
		if(ballPos.getZ() > maxZtarget * 2 && robotStrategy->getPosition().getZ() < maxZtarget * 2)
			updateActionMotion( robotStrategy );
		else
		if(ballPos.getZ() < maxZtarget && robotStrategy->getPosition().getZ() > maxZtarget)
			updateActionMotion( robotStrategy );
		else
		if(ballPos.getZ() > maxZtarget && ballPos.getZ() < 2 * maxZtarget)
			updateActionMotion( robotStrategy );
		else
		if(robotStrategy->getPosition().getX() > actXPoint + maxDistTwist || robotStrategy->getPosition().getX() < actXPoint)
			updateActionMotion( robotStrategy );
		else
			updateHorizontalAlign( robotStrategy );
	}else{
		if(distBall.getZ() > 0)
			robotStrategy->updateCommand( -maxVelocity, maxVelocity );
		else
			robotStrategy->updateCommand( maxVelocity, -maxVelocity );
	}
}

void Strategy::updateDeffenseStrategyAction( RobotStrategy* robotStrategy ){
	btStraight ballGoalSt( btVector3( 0, 0, posGoalpost.getZ()), ballPos );
	float actXPoint = 0.4 * simulator::FIELD_WIDTH;
	float actXArea = 0.5 * simulator::FIELD_WIDTH;

	float zTarget = actXPoint * ballGoalSt.getInclination() + ballGoalSt.getN();
	btVector3 relTargetPos( actXPoint, 0, zTarget );

	if(actXArea > robotStrategy->getTargetPosition().getX()) {
		if(!verifyDeffenseTarget( robotStrategy )) handleLocalActions( robotStrategy );
		else updateActionMotion( robotStrategy );
	}
	else{
		robotStrategy->setTargetPosition( relTargetPos );

		float diffXTarget = robotStrategy->getTargetPosition().getX() - robotStrategy->getPosition().getX();
		if(fabs( diffXTarget ) > areaTarget) updateActionMotion( robotStrategy );
		else updateVerticalAlign( robotStrategy );
	}
}

void Strategy::updateAttackStrategyAction( RobotStrategy* robotStrategy ){
	float actXArea = 0.5 * simulator::FIELD_WIDTH;
	float actXPoint = 0.8 * simulator::FIELD_WIDTH;
	float actZPoint = (ballPos.getZ() > simulator::FIELD_HEIGHT / 2) ? simulator::FIELD_HEIGHT / 5 : 4 * simulator::FIELD_HEIGHT / 5;
	float noReflecArea = 0.8 * simulator::FIELD_WIDTH;

	if(actXArea < robotStrategy->getTargetPosition().getX()) {
		if(ballPos.getX() > noReflecArea) {
			if(!verifyDeffenseTarget( robotStrategy )) {
				if(robotStrategy->getPosition().getX() < ballPos.getX())
					robotStrategy->setTargetPosition( btVector3( ballPos.getX() - areaTarget, 0, ballPos.getZ() - areaTarget / 2 ));
				else
					robotStrategy->setTargetPosition( btVector3( ballPos.getX() - areaTarget, 0, ballPos.getZ() + areaTarget / 2 ));
			}
			if(sizeRobot > robotStrategy->getTargetDistance())
				updateActionShoot( robotStrategy );
			else
				updateActionMotion( robotStrategy );
		}else{
			if(!verifyDeffenseTarget( robotStrategy )) handleLocalActions( robotStrategy );
			else updateActionMotion( robotStrategy );
		}
	}else{
		robotStrategy->setTargetPosition( btVector3( actXPoint, 0, actZPoint ));
		updateActionMotion( robotStrategy );
	}
}

void Strategy::handleLocalActions( RobotStrategy* robotStrategy ){
	btVector3 robotPos = robotStrategy->getPosition();
	btVector3 relPosRobotBall = ballPos - robotPos;

	float angGoalpost = 0.f, angBallGoalRt = 0.f, angBallGoalLf = 0.f;
	btVector3 vecGoalRight;
	btVector3 vecGoalLeft;

	btStraight stGoalRightSd( btVector3( posGoalpost.getX(), 0, 2 * simulator::FIELD_HEIGHT / 3 ), robotPos );
	btStraight stGoalLeftSd( btVector3( posGoalpost.getX(), 0, simulator::FIELD_HEIGHT / 3 ), robotPos );

	vecGoalRight = stGoalRightSd.getNormalVector();
	vecGoalLeft = stGoalLeftSd.getNormalVector();

	btVector3 perpLfGoal = -vecGoalLeft.rotate( btVector3( 0, 1, 0 ), simulator::PI + 2 * atan( vecGoalLeft.getZ() / vecGoalLeft.getX()));
	btVector3 perpRtGoal = -vecGoalRight.rotate( btVector3( 0, 1, 0 ), simulator::PI + 2 * atan( vecGoalRight.getZ() / vecGoalRight.getX()));
	float angBallPerpGoalLf = relPosRobotBall.angle( perpLfGoal ) * 180 / simulator::PI;
	float angBallPerpGoalRt = relPosRobotBall.angle( perpRtGoal ) * 180 / simulator::PI;

	angGoalpost = vecGoalLeft.angle( vecGoalRight ) * 180 / simulator::PI;
	angBallGoalRt = relPosRobotBall.angle( vecGoalRight ) * 180 / simulator::PI;
	angBallGoalLf = relPosRobotBall.angle( vecGoalLeft ) * 180 / simulator::PI;

	if(angGoalpost > angBallGoalLf && angGoalpost > angBallGoalRt && robotStrategy->getTargetDistance() < areaTarget) {
		updateActionShoot( robotStrategy );
	}else{
		updateActionMotion( robotStrategy );
	}
}

bool Strategy::updateActionStopped( RobotStrategy* robotStrategy ){
	float maxVelocity = robotStrategy->getMaxCommand();
	bool backwardMotion = false;
	btVector3 distToBall = ballPos - robotStrategy->getPosition();

	btVector3 oldPosition;
	if((timeToFullHistory == numFramesPerSec)) oldPosition = strategyHistory[numFramesPerSec - 1]->getRobotStrategiesTeam()[robotStrategy->getId()]->getPosition();
	else oldPosition = btVector3( 0, 0, 0 );

	btVector3 diffRobotPos = robotStrategy->getPosition() - oldPosition;

	float timeExecBackCmd = 0.5f;
	//cout << robotStrategy->getLocalFunction() << "\t" << oldPosition.getX() << " - " << oldPosition.getZ() << endl;
	framesStopped[robotStrategy->getId()] += deltaTime;

	if((diffRobotPos.length() < maxDiffRobotPos &&  distToBall.length() > sizeRobot / 2) && (robotStrategy->getCommand()[0] != 0 && robotStrategy->getCommand()[1] != 0)) {
		if(framesStopped[robotStrategy->getId()] > 1.f) {
			if(framesBackward[robotStrategy->getId()] < timeExecBackCmd) {
				robotStrategy->updateCommand( -maxVelocity, -maxVelocity );
				framesBackward[robotStrategy->getId()] += deltaTime;
				backwardMotion = true;
			} else {
				backwardMotion = false;
				framesBackward[robotStrategy->getId()] = 0;
				framesStopped[robotStrategy->getId()] = 0;
			}
		}
	}
	return backwardMotion;
}

void Strategy::updateVerticalAlign( RobotStrategy* robotStrategy ){
	float sideDist = 3.f * SIMULATOR_TO_VSS;
	float maxVelocity = robotStrategy->getMaxCommand();
	float diffZTarget = robotStrategy->getTargetPosition().getZ() - robotStrategy->getPosition().getZ();
	if(fabs( diffZTarget ) > sideDist) {
		if(robotStrategy->getLocalFront().getZ() * diffZTarget < 0)
			robotStrategy->invertLocalFront();

		float angToAlign = 180 / simulator::PI * (robotStrategy->getLocalFront().angle( btVector3( 0, 0, diffZTarget )));
		if(angToAlign > 20.f) {
			if(robotStrategy->getLocalFront().getX() * diffZTarget > 0) robotStrategy->updateCommand( maxVelocity / TURN_ROBOT, -maxVelocity / TURN_ROBOT );
			else robotStrategy->updateCommand( maxVelocity / TURN_ROBOT, -maxVelocity / TURN_ROBOT );
		}else{
			updateActionMotion( robotStrategy );
		}
	}else{
		robotStrategy->updateCommand( 0, 0 );
	}
}

void Strategy::updateHorizontalAlign( RobotStrategy* robotStrategy ){
	float sideDist = 4.f * SIMULATOR_TO_VSS;
	float maxVelocity = robotStrategy->getMaxCommand();
	float diffXTarget = robotStrategy->getTargetPosition().getX() - robotStrategy->getPosition().getX();

	if(fabs( diffXTarget ) > sideDist) {
		if(robotStrategy->getLocalFront().getX() * diffXTarget < 0)
			robotStrategy->invertLocalFront();

		float angToAlign = 180 / simulator::PI * (robotStrategy->getLocalFront().angle( btVector3( diffXTarget, 0, 0 )));
		if(angToAlign > 20.f) {
			if(robotStrategy->getLocalFront().getZ() * diffXTarget > 0) robotStrategy->updateCommand( maxVelocity / TURN_ROBOT, -maxVelocity / TURN_ROBOT );
			else robotStrategy->updateCommand( maxVelocity / TURN_ROBOT, -maxVelocity / TURN_ROBOT );
		}else{
			updateActionMotion( robotStrategy );
		}
	}else{
		robotStrategy->updateCommand( 0, 0 );
	}
}

void Strategy::updateActionShoot( RobotStrategy* robotStrategy ){
	robotStrategy->setTargetPosition( ballPos );
	btVector3 robotPos = robotStrategy->getPosition();
	btVector3 relPosRobotBall = ballPos - robotPos;
	float robotSize = 8.15f * SIMULATOR_TO_VSS;

	float currAngToBall = robotStrategy->getTargetAngle();

	float shootAngle = atan( robotSize / relPosRobotBall.length()) * 180 / simulator::PI;
	float maxVelocity = robotStrategy->getMaxCommand();

	if(fabs( currAngToBall ) > shootAngle) {
		if(currAngToBall < 0) {
			robotStrategy->updateCommand( -maxVelocity / TURN_ROBOT, maxVelocity / TURN_ROBOT );
		}else{
			robotStrategy->updateCommand( maxVelocity / TURN_ROBOT, -maxVelocity / TURN_ROBOT );
		}
	}else{
		robotStrategy->updateCommand( maxVelocity, maxVelocity );
	}
}

float Strategy::handleLocalMaxVelocity( RobotStrategy* robotStrategy ){
	float perc;

	float distToBall = robotStrategy->getTargetDistance();
	float actDistBall = robotStrategy->getActDistToTarget();

	if(distToBall < actDistBall) perc = distToBall / actDistBall;
	else perc = 1;

	if(perc < 0.7 && !(robotStrategy->getLocalFunction() == LocalFunc::goal)) perc = 0.7;
	else
	if(perc < 0.4) perc = 0.4;

	return perc;
}

void Strategy::updateActionMotion( RobotStrategy* robotStrategy ){
	float maxAngToBall = robotStrategy->getMaxAngToTarget();
	float currAngToBall = robotStrategy->getPointAngle( robotStrategy->getTargetPosition());
	float maxVelocity = robotStrategy->getMaxCommand();

	float handMaxVel = maxVelocity * handleLocalMaxVelocity( robotStrategy );
	float percAng = 1 - fabs( currAngToBall ) / maxAngToBall;
	float handLowVel = handMaxVel * percAng;

	if(fabs( currAngToBall ) < maxAngToBall) {
		if(currAngToBall < 0) {
			robotStrategy->updateCommand( handLowVel, handMaxVel );
		}else{
			robotStrategy->updateCommand( handMaxVel, handLowVel );
		}
		robotStrategy->setStandardMotion( true );
	}else{
		if(currAngToBall < 0) {
			robotStrategy->updateCommand( -maxVelocity / TURN_ROBOT, maxVelocity / TURN_ROBOT );
		}else{
			robotStrategy->updateCommand( maxVelocity / TURN_ROBOT, -maxVelocity / TURN_ROBOT );
		}
	}
}

bool Strategy::updateTwistAction( RobotStrategy* robotStrategy ){
	btVector3 distToBall = ballPos - robotStrategy->getPosition();
	float minDistBall = 8.0 * SIMULATOR_TO_VSS;
	float maxVelocity = robotStrategy->getMaxCommand();
	bool twist = false;

	if(distToBall.length() < minDistBall) {
		if(distToBall.getX() > 0) {
			if(robotStrategy->getPosition().getZ() > simulator::FIELD_HEIGHT - minDistBall * 2) {
				robotStrategy->updateCommand( -maxVelocity, maxVelocity );
				twist = true;
			}else
			if(robotStrategy->getPosition().getZ() < minDistBall * 2) {
				robotStrategy->updateCommand( maxVelocity, -maxVelocity );
				twist = true;
			}
		}

		if(ballPos.getX() < areaTarget) {
			if(distToBall.getZ() < 0 && robotStrategy->getPosition().getZ() < simulator::FIELD_HEIGHT / 3) {
				robotStrategy->updateCommand( maxVelocity, -maxVelocity );
				twist = true;
			}else
			if(distToBall.getZ() > 0 && robotStrategy->getPosition().getZ() > 2 * simulator::FIELD_HEIGHT / 3) {
				robotStrategy->updateCommand( -maxVelocity, maxVelocity );
				twist = true;
			}
		}

		if(ballPos.getX() > simulator::FIELD_WIDTH - areaTarget) {
			if(distToBall.getZ() < 0 && robotStrategy->getPosition().getZ() > 2 * simulator::FIELD_HEIGHT / 3) {
				robotStrategy->updateCommand( -maxVelocity, maxVelocity );
				twist = true;
			}else
			if(distToBall.getZ() > 0 && robotStrategy->getPosition().getZ() < simulator::FIELD_HEIGHT / 3) {
				robotStrategy->updateCommand( maxVelocity, -maxVelocity );
				twist = true;
			}
		}
	}
	return twist;
}

bool Strategy::verifyDeffenseTarget( RobotStrategy* robotStrategy ){
	float xTarget = robotStrategy->getTargetPosition().getX();
	float zTarget = robotStrategy->getTargetPosition().getZ();
	bool correct = false;
	float zDistance = sizeRobot;
	float xDistance = 15.f * SIMULATOR_TO_VSS;

	if(zTarget > simulator::FIELD_HEIGHT - sizeRobot || zTarget < sizeRobot) {
		zTarget = ballPos.getZ();
		xTarget = ballPos.getX() - sizeRobot;
	}

	if(xTarget < sizeRobot && zTarget < simulator::FIELD_HEIGHT / 3 && zTarget > 2 * simulator::FIELD_HEIGHT / 3) {
		zTarget = ballPos.getZ();
		xTarget = ballPos.getX() - sizeRobot;
	}else
	if(zTarget > simulator::FIELD_HEIGHT / 3 && zTarget < 2 * simulator::FIELD_HEIGHT / 3 && xTarget > simulator::FIELD_WIDTH - 3 * sizeRobot) {
		xTarget = ballPos.getX() - sizeRobot;
		zTarget = ballPos.getZ();
	}

	if(robotStrategy->getPosition().getX() > ballPos.getX()) {
		xTarget = ballPos.getX() - xDistance;
		if(robotStrategy->getPosition().getZ() > ballPos.getZ()) {
			zTarget = ballPos.getZ() + zDistance;
		} else {
			zTarget = ballPos.getZ() - zDistance;
		}

		if(robotStrategy->getPosition().getZ() < sizeRobot && ballPos.getZ() < sizeRobot) xTarget = ballPos.getX();
		if(robotStrategy->getPosition().getZ() > simulator::FIELD_HEIGHT - sizeRobot && ballPos.getZ() > simulator::FIELD_HEIGHT - sizeRobot) xTarget = ballPos.getX();
		correct = true;
	}

	robotStrategy->setTargetPosition( btVector3( xTarget, 0, zTarget ));
	return correct;
}
