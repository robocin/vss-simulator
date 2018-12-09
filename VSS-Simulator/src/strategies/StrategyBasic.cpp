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

#include "../../include/strategies/StrategyBasic.h"

StrategyBasic::StrategyBasic() : framesStopped( 0 ), framesBackward( 0 ){
	attackDir = 1;
	deltaTime = 0.001f;
	timeToFullHistory = 0.f;
	numFramesPerSec = 30;

	begin_time = clock();
}

StrategyBasic::~StrategyBasic(){
	strategyHistory.clear();
}

void StrategyBasic::runStrategy( vector<RobotStrategy*> robotStrategiesTeam, vector<RobotStrategy*> robotStrategiesAdv, btVector3 ballPos ){
	deltaTime = float( clock () - begin_time ) / CLOCKS_PER_SEC;
	begin_time = clock();

	this->robotStrategiesTeam = robotStrategiesTeam;
	this->robotStrategiesAdv = robotStrategiesAdv;
	this->ballPos = ballPos;

	if(strategyHistory.size() > numFramesPerSec) updateDynamics();

	updateFunctions();

	for(int i = 0; i < robotStrategiesTeam.size(); i++) {
		controlLocalStrategy( robotStrategiesTeam[i] );
	}

	updateStrategiesHistory();
}
void StrategyBasic::updateStrategiesHistory(){

	StrategyBasic* oldStrategy = new StrategyBasic();
	*oldStrategy = *this;

	if(timeToFullHistory < numFramesPerSec) {
		timeToFullHistory++;
		strategyHistory.push_back( oldStrategy );
	}else{
		StrategyBasic* strategyAux = new StrategyBasic();
		for(int i = 0; i < numFramesPerSec; i++) {
			*strategyAux = *((StrategyBasic*)strategyHistory.at( i ));
			*strategyHistory.at( i ) = *oldStrategy;
			*oldStrategy = *strategyAux;
		}

		delete oldStrategy;
		delete strategyAux;
	}
}

void StrategyBasic::updateFunctions(){
	for(int i = 0; i < robotStrategiesTeam.size(); i++) {
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

void StrategyBasic::controlLocalStrategy( RobotStrategy* robotStrategy ){
	updateTargetPosition( robotStrategy );
	updateLocalFuncAction( robotStrategy );
}

void StrategyBasic::updateTargetPosition( RobotStrategy* robotStrategy ){
	float zBall = 0.f;
	float xBall = 0.f;

	btStraight stTarget( ballPos, posGoalpost );

	xBall = ballPos.getX() - stTarget.getNormalVector().getX() * areaTarget;

	zBall = xBall * stTarget.getInclination() + stTarget.getN();

	robotStrategy->setTargetPosition( btVector3( xBall, 0, zBall ));
}

void StrategyBasic::updateLocalFuncAction( RobotStrategy* robotStrategy ){
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

void StrategyBasic::updateGoalStrategyAction( RobotStrategy* robotStrategy ){
	btStraight ballGoalSt( btVector3( 0, 0, posGoalpost.getZ()), ballPos );
	float actXPoint = 15.f;
	float actDist = 5.f;

	float zTarget = actXPoint * ballGoalSt.getInclination() + ballGoalSt.getN();
	btVector3 relTargetPos( actXPoint, 0, zTarget );

	robotStrategy->setTargetPosition( relTargetPos );
	if(robotStrategy->getTargetDistance() > actDist)
		updateActionMotion( robotStrategy );
	else
		robotStrategy->updateCommand( 0, 0 );
}

void StrategyBasic::updateDeffenseStrategyAction( RobotStrategy* robotStrategy ){
	btStraight ballGoalSt( btVector3( 0, 0, posGoalpost.getZ()), ballPos );
	float actXPoint = 55.f;
	float actXArea = 75.f;

	float zTarget = actXPoint * ballGoalSt.getInclination() + ballGoalSt.getN();
	btVector3 relTargetPos( actXPoint, 0, zTarget );

	if( actXArea > robotStrategy->getTargetPosition().getX())
		handleLocalActions( robotStrategy );
	else{
		robotStrategy->setTargetPosition( relTargetPos );
		updateActionMotion( robotStrategy );
	}
}

void StrategyBasic::updateAttackStrategyAction( RobotStrategy* robotStrategy ){
	float actXArea = 75.f;
	float actXPoint = 120.f;
	float actZPoint = (ballPos.getZ() > simulator::FIELD_HEIGHT / 2) ? simulator::FIELD_HEIGHT / 5 : 4 * simulator::FIELD_HEIGHT / 5;

	if(actXArea < robotStrategy->getTargetPosition().getX()) {
		handleLocalActions( robotStrategy );
	}else{
		robotStrategy->setTargetPosition( btVector3( actXPoint, 0, actZPoint ));
		updateActionMotion( robotStrategy );
	}
}

bool StrategyBasic::correctWallTargetPosition( RobotStrategy* robotStrategy ){
	float ballMaxZ = simulator::FIELD_HEIGHT - distProjBallWall;
	float xBall = robotStrategy->getTargetPosition().getX();
	float zBall = robotStrategy->getTargetPosition().getZ();
	bool correctTarget = false;
	btStraight stBallGoal;

	if(robotStrategy->getTargetPosition().getZ() < distProjBallWall) {
		stBallGoal = btStraight( posGoalpost, btVector3( ballPos.getX(), 0, -ballPos.getZ()));
		correctTarget = true;
	}

	if(robotStrategy->getTargetPosition().getZ() > ballMaxZ) {
		float dzBall = simulator::FIELD_HEIGHT - ballPos.getZ();
		stBallGoal = btStraight( posGoalpost, btVector3( ballPos.getX(), 0, simulator::FIELD_HEIGHT + dzBall ));
		correctTarget = true;
	}

	if(correctTarget) {
		xBall = ballPos.getX() - stBallGoal.getNormalVector().getX() * areaTarget;
		zBall = ballPos.getZ() + stBallGoal.getNormalVector().getZ() * areaTarget;
		xBall = btVector3( xBall, 0, zBall ).getX();
	}

	robotStrategy->setTargetPosition( btVector3( xBall, 0, zBall ));

	return correctTarget;
}

void StrategyBasic::handleLocalActions( RobotStrategy* robotStrategy ){
	btVector3 robotPos = robotStrategy->getPosition();
	btVector3 relPosRobotBall = ballPos - robotPos;

	float angGoalpost = 0.f, angBallGoalRt = 0.f, angBallGoalLf = 0.f;
	btVector3 vecGoalRight;
	btVector3 vecGoalLeft;
	bool correctTarget = correctWallTargetPosition( robotStrategy );
	if(!correctTarget) {
		btStraight stGoalRightSd( btVector3( posGoalpost.getX(), 0, 2 * simulator::FIELD_HEIGHT / 3 ), robotPos );
		btStraight stGoalLeftSd( btVector3( posGoalpost.getX(), 0, simulator::FIELD_HEIGHT / 3 ), robotPos );

		vecGoalRight = stGoalRightSd.getNormalVector();
		vecGoalLeft = stGoalLeftSd.getNormalVector();
	}else{
		btStraight stGoalRightSd;
		btStraight stGoalLeftSd;
		if(ballPos.getZ() < simulator::FIELD_HEIGHT / 2) {
			stGoalRightSd = btStraight( btVector3( posGoalpost.getX(), 0, 2 * simulator::FIELD_HEIGHT / 3 ),
			                            btVector3( robotPos.getX(), 0, -robotPos.getZ()));
			stGoalLeftSd = btStraight( btVector3( posGoalpost.getX(), 0, simulator::FIELD_HEIGHT / 3 ),
			                           btVector3( robotPos.getX(), 0, -robotPos.getZ()));
		}else
		if(ballPos.getZ() > simulator::FIELD_HEIGHT / 2) {
			float dzRobot = simulator::FIELD_HEIGHT - robotPos.getZ();
			stGoalRightSd = btStraight( btVector3( posGoalpost.getX(), 0, 2 * simulator::FIELD_HEIGHT / 3 ),
			                            btVector3( robotPos.getX(), 0, simulator::FIELD_HEIGHT + dzRobot ));
			stGoalLeftSd = btStraight( btVector3( posGoalpost.getX(), 0, simulator::FIELD_HEIGHT / 3 ),
			                           btVector3( robotPos.getX(), 0, simulator::FIELD_HEIGHT + dzRobot ));
		}

		vecGoalRight = stGoalRightSd.getNormalVector();
		vecGoalLeft = stGoalLeftSd.getNormalVector();
	}

	btVector3 perpLfGoal = -vecGoalLeft.rotate( btVector3( 0, 1, 0 ), simulator::PI + 2 * atan( vecGoalLeft.getZ() / vecGoalLeft.getX()));
	btVector3 perpRtGoal = -vecGoalRight.rotate( btVector3( 0, 1, 0 ), simulator::PI + 2 * atan( vecGoalRight.getZ() / vecGoalRight.getX()));
	float angBallPerpGoalLf = relPosRobotBall.angle( perpLfGoal ) * 180 / simulator::PI;
	float angBallPerpGoalRt = relPosRobotBall.angle( perpRtGoal ) * 180 / simulator::PI;

	angGoalpost = vecGoalLeft.angle( vecGoalRight ) * 180 / simulator::PI;
	angBallGoalRt = relPosRobotBall.angle( vecGoalRight ) * 180 / simulator::PI;
	angBallGoalLf = relPosRobotBall.angle( vecGoalLeft ) * 180 / simulator::PI;

	if(!updateActionStopped( robotStrategy )) {
		if(correctTarget && angGoalpost > angBallPerpGoalLf && angGoalpost > angBallPerpGoalRt && relPosRobotBall.length() < areaTarget) {
			updateActionShoot( robotStrategy );
		}else
		if(angGoalpost > angBallGoalLf && angGoalpost > angBallGoalRt && relPosRobotBall.length() < areaTarget) {
			updateActionShoot( robotStrategy );
		}else{
			updateActionMotion( robotStrategy );
		}
	}
}

bool StrategyBasic::updateActionStopped( RobotStrategy* robotStrategy ){
	float maxVelocity = robotStrategy->getMaxCommand();
	bool backwardMotion = false;

	btVector3 oldPosition;
	if(!(timeToFullHistory < numFramesPerSec)) oldPosition = strategyHistory[numFramesPerSec - 1]->getRobotStrategiesTeam()[robotStrategy->getId()]->getPosition();
	else oldPosition = btVector3( 0, 0, 0 );

	btVector3 diffRobotPos = robotStrategy->getPosition() - oldPosition;

	framesStopped += deltaTime;

	float diff = diffRobotPos.length();

	float timeExecBackCmd = 1.f;

	if(framesStopped > 2.f) {
		if(framesBackward < timeExecBackCmd && diffRobotPos.length() < maxDiffRobotPos) {
			robotStrategy->updateCommand( -maxVelocity, -maxVelocity );
			framesBackward += deltaTime;
			backwardMotion = true;
		}else{
			framesStopped = 0;
			framesBackward = 0;
			backwardMotion = false;
		}
	}
	return backwardMotion;
}

void StrategyBasic::updateActionShoot( RobotStrategy* robotStrategy ){
	robotStrategy->setTargetPosition( ballPos );
	btVector3 robotPos = robotStrategy->getPosition();
	btVector3 relPosRobotBall = ballPos - robotPos;

	float currAngToBall = robotStrategy->getTargetAngle();
	float robotSize = 8.15f;
	float shootAngle = atan( robotSize / relPosRobotBall.length()) * 180 / simulator::PI;
	float maxVelocity = robotStrategy->getMaxCommand();

	if(fabs( currAngToBall ) > shootAngle) {
		if(currAngToBall < 0) {
			robotStrategy->updateCommand( -maxVelocity / 2, maxVelocity / 2 );
		}else{
			robotStrategy->updateCommand( maxVelocity / 2, -maxVelocity / 2 );
		}
	}else{
		robotStrategy->updateCommand( maxVelocity, maxVelocity );
	}
}

float StrategyBasic::handleLocalMaxVelocity( RobotStrategy* robotStrategy ){
	float perc;

	float distToBall = robotStrategy->getTargetDistance();
	float actDistBall = robotStrategy->getActDistToTarget();

	if(distToBall < actDistBall) perc = distToBall / actDistBall;
	else perc = 1;

	if(perc < 0.7) perc = 0.7;

	return perc;
}

void StrategyBasic::updateActionMotion( RobotStrategy* robotStrategy ){
	float maxAngToBall = robotStrategy->getMaxAngToTarget();
	float currAngToBall = robotStrategy->getTargetAngle();
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
	}else{
		if(currAngToBall < 0) {
			robotStrategy->updateCommand( -maxVelocity / 2, maxVelocity / 2 );
		}else{
			robotStrategy->updateCommand( maxVelocity / 2, -maxVelocity / 2 );
		}
	}
}
