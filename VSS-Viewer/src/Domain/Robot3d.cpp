/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "Robot3d.h"

Robot3d::Robot3d(){
	pose = vss::Pose();
	teamColor = ColorName::Yellow;
	robotColor = ColorName::Green;
	selected = false;
}

Robot3d::Robot3d( vss::Pose *pose, ColorName teamColor, ColorName robotColor ){
	this->pose = *pose;
	this->teamColor = teamColor;
	this->robotColor = robotColor;
	selected = false;
}

Robot3d::Robot3d( Robot3d *robot ){
	pose = robot->pose;
	teamColor = robot->teamColor;
	robotColor = robot->robotColor;
	selected = false;
}

void Robot3d::setSelected( bool selected ){
	this->selected = selected;
}

bool Robot3d::getSelected(){
	return selected;
}

void Robot3d::setPose( vss::Pose pose ){
	this->pose = pose;
}

vss::Pose Robot3d::getPose(){
	return pose;
}

std::ostream& operator<<( std::ostream& os, const Robot3d& robot )
{
	os << robot.pose << " - ";
	os << "selected: " << robot.selected << " - ";
	os << "teamColor:" << robot.teamColor << " - ";
	os << "robotColor: " << robot.robotColor << " - ";
	return os;
}
