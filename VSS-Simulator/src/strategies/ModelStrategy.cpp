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

#ifndef ModelStrategy_CPP_
#define ModelStrategy_CPP_

#include "../../include/strategies/ModelStrategy.h"

ModelStrategy::ModelStrategy(){
	this->ballVel = btVector3( 0, 0, 0 );
	this->ballAce = btVector3( 0, 0, 0 );
	attackDir = 1;
	deltaTime = 0.001f;
	numFramesPerSec = 30;

	begin_time = clock();
}

void ModelStrategy::runStrategy(){
	deltaTime = float( clock () - begin_time ) / CLOCKS_PER_SEC;
	begin_time = clock();

	if(strategyHistory.size() > numFramesPerSec) updateDynamics();

	for(int i = 0; i < robotStrategiesTeam.size(); i++) {
		updateTargetPosition( robotStrategiesTeam[i] );
	}

	updateStrategiesHistory();
}

void ModelStrategy::updateTargetPosition( RobotStrategy* robotStrategy ){
	robotStrategy->setTargetPosition( ballPos );
}

void ModelStrategy::updateStrategiesHistory(){
	strategyHistory.clear();
	strategyHistory.push_back( this );
}

void ModelStrategy::setFramesSec( int numFramesSec ){
	this->numFramesPerSec = numFramesSec;
}

void ModelStrategy::setAttackDir( int att ){
	posGoalpost = btVector3( simulator::FIELD_WIDTH, 0, simulator::FIELD_HEIGHT / 2 );
	this->attackDir = att;
}

void ModelStrategy::updateDynamics(){
	for(int i = 0; i < robotStrategiesTeam.size(); i++) {
		updateLocalDynamics( robotStrategiesTeam[i], strategyHistory[strategyHistory.size() - 1]->getRobotStrategiesTeam()[i] );
		updateLocalDynamics( robotStrategiesAdv[i], strategyHistory[strategyHistory.size() - 1]->getRobotStrategiesAdv()[i] );
	}

	btVector3 diffBallVel = ballVel - strategyHistory[strategyHistory.size() - 1]->getBallVelocity();
	ballAce = attackDir * diffBallVel / deltaTime;

	btVector3 diffBallPos = ballPos - strategyHistory[strategyHistory.size() - 1]->getBallPosition();
	ballVel = attackDir * diffBallPos / deltaTime;
}

void ModelStrategy::updateLocalDynamics( RobotStrategy* curRbSt, RobotStrategy* oldRbSt ){
	btVector3 diffVel = curRbSt->getLinearVelocity() - oldRbSt->getLinearVelocity();
	curRbSt->setLinearAcceleration( diffVel / deltaTime );

	btVector3 diffPos = curRbSt->getPosition() - oldRbSt->getPosition();
	curRbSt->setLinearVelocity( diffPos / deltaTime );

	float diffAng = curRbSt->getFieldAngle() - oldRbSt->getFieldAngle();
	curRbSt->setAngularVelocity( diffAng / deltaTime );

	float diffVelAng = curRbSt->getFieldAngle() - oldRbSt->getFieldAngle();
	curRbSt->setAngularAcceleration( diffVelAng / deltaTime );
}

#endif
