/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef CONTROL_SENDER_H
#define CONTROL_SENDER_H

#include "vector"
#include "Robot3d.h"
#include "Interfaces/IControlSender.h"
#include "Domain/ExecutionConfig.h"

class ControlSenderAdapter {
public:

	vss::IControlSender *controlSender;
	vss::ExecutionConfig *executionConfig;
	vss::Pose *ball;
	std::vector<Robot3d> *robots;

	ControlSenderAdapter( vss::Pose *ball, std::vector<Robot3d> *robots, vss::ExecutionConfig *executionConfig );

	void send( bool paused );

protected:
	bool hasACustomAddress();
};

#endif // CONTROL_SENDER_H
