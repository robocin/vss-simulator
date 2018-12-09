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

#ifndef SIR_H_
#define SIR_H_

#include "Header.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

enum { NONE = 0, GOAL_TEAM1 = 1, GOAL_TEAM2 = 2, FAULT_TEAM1 = 3, FAULT_TEAM2 = 4, PENALTY_TEAM1 = 5, PENALTY_TEAM2 = 6 };

//Standard colors of the simulator
struct Color {
	float r;
	float g;
	float b;

	Color(){
	}
	Color( float r0, float g0, float b0 ) : r( r0 ), g( g0 ), b( b0 ){
	}
};

//All rigid bodies are searched by the vector of BulletObject
struct BulletObject {
	int id;
	string name;
	Color clr;
	bool hit;
	bool hitRobot;
	btRigidBody* body;
	btVector3 halfExt; //Used only for compound shapes
	BulletObject( btRigidBody* b, string n, Color clr0 ) : name( n ), body( b ), clr( clr0 ), id( -1 ), hit( false ), hitRobot( false ), halfExt( btVector3( 0, 0, 0 )) {
	}
};

struct Command {
	float left;
	float right;
	Command(){
		left = right = 0;
	};
	Command( float left, float right ){
		this->left = left;
		this->right = right;
	};
	Command( Command *cmd ){
		left = cmd->left;
		right = cmd->right;
	};
};

struct Report {
	long int qtd_of_steps;
	int total_of_goals_team[2];
	int total_of_own_goals_team[2];
	int collisions_in_high_speed_team[2][3];
	float ball_possession_team[2];
	float travelled_distance_team[2][3];
	float time_lost_stuck_team[2][3];
	Report(){
		qtd_of_steps = 0;
		for(int h = 0; h < 2; h++) {
			ball_possession_team[h] = 0;
			total_of_goals_team[h] = 0;
			total_of_own_goals_team[h] = 0;
			for(int i = 0; i < 3; i++) {
				collisions_in_high_speed_team[h][i] = 0;
				travelled_distance_team[h][i] = 0;
				time_lost_stuck_team[h][i] = 0;
			}
		}
	};
	void show(){
		cout << "---REPORT---" << endl;
		cout << "+qtd_of_steps=" << qtd_of_steps << endl;
		for(int h = 0; h < 2; h++) {
			cout << "---TEAM_" << h << "---" << endl;
			cout << "+total_of_goals_team=" << total_of_goals_team[h] << endl;
			cout << "+total_of_own_goals_team=" << total_of_own_goals_team[h] << endl;
			cout << "+ball_possession" << "=" << ball_possession_team[h] << endl;
			for(int i = 0; i < 3; i++) {
				cout << "+collision_in_high_speed_" << i << "=" << collisions_in_high_speed_team[h][i] << endl;
			}
			for(int i = 0; i < 3; i++) {
				cout << "+travelled_distance_" << i << "=" << travelled_distance_team[h][i] << endl;
			}
			for(int i = 0; i < 3; i++) {
				cout << "+time_lost_stuck" << i << "=" << time_lost_stuck_team[h][i] << endl;
			}
		}
	};
};

#endif
