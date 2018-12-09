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

#ifndef ROBOT_PHYSICS_H_
#define ROBOT_PHYSICS_H_

#include "Header.h"
#include "BulletDynamics/Vehicle/btRaycastVehicle.h"

#define MAX_ACCELERATION 5.5 * simulator::SCALE_WORLD

class RobotPhysics {
private:

	int contador;

	Color clrTeam;
	Color clrPlayer;

	float sizeRobot;
	float mass;
	float wheelWidth;
	float wheelStRadius;
	float wheelFrRadius;

	float suspensionStiffness;
	float suspensionDamping;
	float suspensionCompression;
	float wheelFriction;
	float rollInfluence;
	btScalar sRestLengthSt;
	btScalar sRestLengthFr;

	float freeWheelAng;

	float forceLeftWheel;
	float forceRightWheel;
	float timeStep;

	btVector3 point;
	btRigidBody* bdRobot;

	btRaycastVehicle::btVehicleTuning tuning;
	btVehicleRaycaster* raycaster;
	btRaycastVehicle* raycast;

	void setRobotState();
	void calcProportionalVelocity( float iniWheelVel[2], float endWheelVel[2] );
public:

	RobotPhysics(){
	}
	~RobotPhysics();

	RobotPhysics( btVector3 point, float mass, btRigidBody* bdRobot, Color plrColor, Color teamColor, float wheelWidth = 0.6, float wheelStRadius = 2, float wheelFrWheel = 0.75, float sizeRobot = 8.0 );
	void buildRobot( btDynamicsWorld* world );
	void updateRobot( float* speed );

	btVector3 getLocalUnitVecX();
	btVector3 getLocalUnitVecZ();
	btVector3 getPosition();
	Color getColorTeam() {
		return clrTeam;
	}
	Color getColorPlayer() {
		return clrPlayer;
	}

	float getSteeringWheelRadius() {
		return wheelStRadius;
	}
	float getFreeWheelRadius() {
		return wheelFrRadius;
	}
	float getWheelWidth() {
		return wheelWidth;
	}

	btRaycastVehicle* getRaycast() {
		return raycast;
	}
	btRigidBody* getRigidBody() {
		return bdRobot;
	}

	void setTimeStep( float timeStep );
	bool isTrue();
};

#endif
