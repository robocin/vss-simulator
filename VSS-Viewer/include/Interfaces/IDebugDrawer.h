/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef IDEBUG_H
#define IDEBUG_H

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux
#include <GL/glut.h>
#endif

#include "Domain/Pose.h"
#include "Domain/Path.h"
#include "Robot3d.h"
#include "ColorEnum.h"

class IDebugDrawer {
public:

	virtual void drawPath( const Robot3d &robot, const vss::Path &path ) = 0;
	virtual void drawStep( const Robot3d &robot, const vss::Pose &stepPose ) = 0;
	virtual void drawFinal( const Robot3d &robot, const vss::Pose &finalPose ) = 0;
};

#endif // IDEBUG_H
