#ifndef _ARBITER_H_
#define _ARBITER_H_

#include "iostream"
#include "Sir.h"
#include "Physics.h"

using namespace std;

//! Classe responsável por verificar ocorrencias como: gol, penalti e falta. Também é responsável por monitorar o tempo e reposicionar os objetos em campo.
class Arbiter {
protected:

	bool *paused;
	Physics *physics;
	Report *report;
	btVector3 history_ball;
	int ball_count;
	int relative_qtd_steps;
public:

	bool refresh;
	Arbiter();

	void allocPhysics( Physics* );
	void allocReport( Report* );
	void allocPaused( bool* );
	int checkWorld();

	void position_objects_after_goal_team_1();
	void position_objects_after_goal_team_2();
};

#endif // _ARBITER_H_
