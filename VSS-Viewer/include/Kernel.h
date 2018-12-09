/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef KERNEL_H
#define KERNEL_H

#include <Domain/ExecutionConfig.h>
#include "mutex"
#include "thread"
#include "functional"

#include "CompetitionEnum.h"
#include "SimpleRobotDrawer.h"
#include "SimpleBallDrawer.h"
#include "FieldDrawerVerySmallSize.h"
#include "OriginalDebugDrawer.h"

#include "StateReceiverAdapter.h"
#include "DebugReceiverAdapter.h"

#include "TopCamera.h"
#include "World.h"

#include "Domain/Pose.h"
#include "Robot3d.h"
#include "Domain/Path.h"

class Kernel {
private:

	int argc;
	char **argv;
	vss::ExecutionConfig executionConfig;

    vss::Pose ball;
	std::vector<Robot3d> robots;
	std::vector<vss::Pose> teamOneFinalPoses;
	std::vector<vss::Pose> teamOneStepPoses;
	std::vector<vss::Path> teamOnePaths;
	std::vector<vss::Pose> teamTwoFinalPoses;
	std::vector<vss::Pose> teamTwoStepPoses;
	std::vector<vss::Path> teamTwoPaths;

	std::thread *worldThread;
	std::thread *receiveStateThread;
	std::thread *receiveDebugTeam1Thread;
	std::thread *receiveDebugTeam2Thread;

    std::mutex mutexDebugTeamYellow;
    std::mutex mutexDebugTeamBlue;

public:

	Kernel( int argc, char **argv, vss::ExecutionConfig );

	void init();
	void initialMessage();
	void instanceRobots();
	void instanceDebug();
	void worldThreadWrapper();
	void receiveStateThreadWrapper();
	void receiveDebugTeam1ThreadWrapper();
	void receiveDebugTeam2ThreadWrapper();

};

#endif // KERNEL_H
