#include "../include/Arbiter.h"
#include "../include/StartPositionsHelper.h"

Arbiter::Arbiter(){
	refresh = false;
	relative_qtd_steps = 0;
}

void Arbiter::allocPhysics( Physics *physics ){
	this->physics = physics;
}

void Arbiter::allocReport( Report *report ){
	this->report = report;
}

void Arbiter::allocPaused( bool *paused ){
	this->paused = paused;
}

int Arbiter::checkWorld(){
	int situation = NONE;
	btVector3 ball = physics->getBallPosition();

	if(ball.getX() > 160) {
		refresh = true;
		situation = GOAL_TEAM1;
		report->total_of_goals_team[0]++;
		cerr << "---Goal RIGHT---" << endl;
		position_objects_after_goal_team_1();
	}else
	if(ball.getX() < 10) {
		refresh = true;
		situation = GOAL_TEAM2;
		report->total_of_goals_team[1]++;
		cerr << "---Goal LEFT---" << endl;
		position_objects_after_goal_team_2();
	}

	vector<RobotPhysics*> listRobots = physics->getAllRobots();

	//! A cada minuto mostra o tempo, isto é, 1 min, 2 min, n min.
	if(report->qtd_of_steps > relative_qtd_steps + 3500) {
		//! É necessário verificar dessa maneira, pois como qtd_of_steps é um variavel que roda na simulação de física
		//! e a simulação física trabalha em uma frequência maior que o resto do programa, nem sempre o loop no "valor 3500"
		//! caia na verificação. Dessa forma é garantido que sempre irá ser printado o tempo a cada minuto
		relative_qtd_steps += 3500;
		cout << "---" << relative_qtd_steps / 3500 << " MIN---" << endl;
	}

	report->qtd_of_steps++;

	return situation;
}

void Arbiter::position_objects_after_goal_team_1(){
	vector<btVector3> positions;
	vector<btVector3> orientations;

	for(int i = 0; i < StartPositionsHelper::positions.size(); i++) {
		positions.push_back(StartPositionsHelper::positions[i]);
		orientations.push_back(StartPositionsHelper::angulations[i]);
	}

	physics->setBallPosition( btVector3( (simulator::FIELD_WIDTH / 2.0) + 10, 2.0, simulator::FIELD_HEIGHT / 2.0 ));
	physics->setRobotsPosition( positions, orientations );
}

void Arbiter::position_objects_after_goal_team_2(){
	vector<btVector3> positions;
	vector<btVector3> orientations;

	for(int i = 0; i < StartPositionsHelper::positions.size(); i++) {
		positions.push_back(StartPositionsHelper::positions[i]);
		orientations.push_back(StartPositionsHelper::angulations[i]);
	}

	physics->setBallPosition( btVector3( (simulator::FIELD_WIDTH / 2.0) + 10, 2.0, simulator::FIELD_HEIGHT / 2.0 ));
	physics->setRobotsPosition( positions, orientations );
}
