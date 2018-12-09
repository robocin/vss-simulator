/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef VIEWER_ROBOT_H
#define VIEWER_ROBOT_H

#include <Domain/Pose.h>
#include "Domain/Pose.h"
#include "ColorEnum.h"
#include "iostream"

class Robot3d {
public:

	vss::Pose pose;
	bool selected;
	ColorName teamColor;
	ColorName robotColor;

	Robot3d();
	Robot3d( vss::Pose *pose, ColorName teamColor, ColorName robotColor );
	Robot3d( Robot3d *robot );

	void setSelected( bool selected );
	bool getSelected();

	void setPose( vss::Pose pose );
	vss::Pose getPose();

	friend std::ostream& operator<<( std::ostream& os, const Robot3d& robot );
};

#endif // VIEWER_ROBOT_H
