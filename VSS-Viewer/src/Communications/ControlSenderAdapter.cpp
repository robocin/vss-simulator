/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include <Domain/ExecutionConfig.h>
#include <Domain/Constants.h>
#include "ControlSenderAdapter.h"
#include "Communications/ControlSender.h"
#include "Math.h"

ControlSenderAdapter::ControlSenderAdapter( vss::Pose *ball, std::vector<Robot3d> *robots, vss::ExecutionConfig *executionConfig ){
	this->ball = ball;
	this->robots = robots;
	this->executionConfig = executionConfig;

	controlSender = new vss::ControlSender();

	if(hasACustomAddress())
		controlSender->createSocket(executionConfig->ctrlSendAddr);
	else
		controlSender->createSocket();
}

void ControlSenderAdapter::send( bool paused ){
	vss::Control control;

	control.paused = paused;

	auto ball_n = Core::glutToBullet( *ball );
	control.ball.x = ball_n.x;
	control.ball.y = ball_n.y;

	for(int i = 0; i < 3; i++) {
		auto robot_n = Core::glutToBullet( robots->at( i ).pose );
		control.teamYellow.push_back(vss::Robot(robot_n.x, robot_n.y, robot_n.angle, 0, 0, 0));
	}

	for(int i = 0; i < 3; i++) {
		auto robot_n = Core::glutToBullet( robots->at( i + 3 ).pose );
		control.teamBlue.push_back(vss::Robot(robot_n.x, robot_n.y, robot_n.angle, 0, 0, 0));
	}

	controlSender->sendControl(control);
}

bool ControlSenderAdapter::hasACustomAddress() {
	if(executionConfig->ctrlSendAddr.getIp() != vss::DEFAULT_CTRL_SEND_ADDR)
		return true;

	if(executionConfig->ctrlSendAddr.getPort() != vss::DEFAULT_CTRL_PORT)
		return true;

	return false;
}
