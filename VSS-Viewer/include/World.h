/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "typeinfo"
#include <vector>
#include "mutex"

#include "GlutFramework.h"
#include "IFieldDrawer.h"
#include "IRobotDrawer.h"
#include "IBallDrawer.h"
#include "IDebugDrawer.h"
#include "ICamera.h"
#include "Domain/Pose.h"
#include "Robot3d.h"
#include "Domain/Path.h"
#include "AsciiEnum.h"
#include "ColorEnum.h"
#include "Material.h"
#include "Math.h"
#include "ControlSenderAdapter.h"

class World : public GlutFramework {
public:

	MouseAction mouseAction;
	MouseState mouseState;

	std::string sendControlAddress;

	bool paused;
	IFieldDrawer *fieldDrawer;
	IRobotDrawer *robotDrawer;
	IBallDrawer *ballDrawer;
	IDebugDrawer *debugDrawer;
	ICamera *camera;
	ControlSenderAdapter *controlSender;
	vss::ExecutionConfig *executionConfig;

	vss::Pose *ball;
	bool isBallSelected;
	std::vector<Robot3d> *robots;
	std::vector<vss::Path> *pathsTeam1;
	std::vector<vss::Pose> *stepPosesTeam1;
	std::vector<vss::Pose> *finalPosesTeam1;

	std::vector<vss::Path> *pathsTeam2;
	std::vector<vss::Pose> *stepPosesTeam2;
	std::vector<vss::Pose> *finalPosesTeam2;
    std::mutex *mutexDebugTeamYellow;
    std::mutex *mutexDebugTeamBlue;

	Material *material;

	World( IDebugDrawer *debugDrawer, IFieldDrawer *fieldDrawer, IRobotDrawer *robotDrawer, IBallDrawer *ballDrawer,
		   ICamera *camera, vss::Pose *ball, std::vector<Robot3d> *robots, std::vector<vss::Path> *pathsTeam1, std::vector<vss::Pose> *stepPosesTeam1,
		   std::vector<vss::Pose> *finalPosesTeam1, std::vector<vss::Path> *pathsTeam2, std::vector<vss::Pose> *stepPosesTeam2, std::vector<vss::Pose> *finalPosesTeam2,
		   std::mutex *mutexDebugTeamYellow, std::mutex *mutexDebugTeamBlue, vss::ExecutionConfig *executionConfig );

	void display() override;
	void keyboardDown( unsigned char key, int x, int y ) override;
	void mouseButtonPress( int button, int state, int x, int y ) override;
	void reshape( int width, int height ) override;
	void mouseMove( int x, int y ) override;
	void specialKeyboardDown( int key, int x, int y ) override;

	// Strategies
	void closeStrategy();
	void changeCameraStrategy();
	void pauseStrategy();
	void startStrategy();
	void toggleSelectedRobotStrategy( vss::Pose pose );
	void moveRobotStrategy( vss::Pose pose );
	void rotateRobotStrategy( bool direction );

	void moveBall( vss::Pose pose );
};

#endif // WORLD_H
