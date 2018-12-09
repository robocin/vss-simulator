/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include <Domain/TeamType.h>
#include <Domain/ExecutionConfig.h>
#include <Communications/DebugReceiverAdapter.h>

#include "Domain/Constants.h"
#include "DebugReceiverAdapter.h"
#include "Communications/DebugReceiver.h"

DebugReceiverAdapter::DebugReceiverAdapter( std::vector<vss::Path> *paths, std::vector<vss::Pose> *stepPoses, std::vector<vss::Pose> *finalPoses, std::mutex *mutexDebug, vss::ExecutionConfig *executionConfig ){
	this->paths = paths;
	this->stepPoses = stepPoses;
	this->finalPoses = finalPoses;
	this->mutexDebug = mutexDebug;
	this->executionConfig = executionConfig;
}

void DebugReceiverAdapter::loop( vss::TeamType teamType ){
	debugReceiver = new vss::DebugReceiver();

	if(hasACustomAddress())
		if(teamType == vss::TeamType::Yellow)
			debugReceiver->createSocket(executionConfig->debugYellowRecvAddr);
		else
			debugReceiver->createSocket(executionConfig->debugBlueRecvAddr);
	else
		debugReceiver->createSocket(teamType);

	while(true) {
		auto debug = debugReceiver->receiveDebug();

		mutexDebug->lock();

		for(unsigned int i = 0 ; i < debug.stepPoints.size() ; i++){
			stepPoses->at(i).x = debug.stepPoints[i].y - (vss::MAX_COORDINATE_Y / 2.0);
			stepPoses->at(i).y = debug.stepPoints[i].x - (vss::MAX_COORDINATE_X / 2.0);
		}

		for(unsigned int i = 0 ; i < debug.finalPoses.size() ; i++){
			finalPoses->at(i).x = debug.finalPoses[i].y - (vss::MAX_COORDINATE_Y / 2.0);
			finalPoses->at(i).y = debug.finalPoses[i].x - (vss::MAX_COORDINATE_X / 2.0);
			finalPoses->at(i).angle = debug.finalPoses[i].angle * (vss::MAX_ANGLE_VALUE/2) / M_PI;
		}

		for(unsigned int i = 0; i < debug.paths.size(); i++) {
            vss::Path path;
			for(unsigned int j = 0; j < debug.paths[i].points.size(); j++) {
                vss::Pose pose;
				pose.x = debug.paths[i].points[j].y - (130 / 2.0);
				pose.y = debug.paths[i].points[j].x - (170 / 2.0);

				path.points.push_back(pose);
			}
			paths->at(i) = path;
		}

		mutexDebug->unlock();
	}
}

bool DebugReceiverAdapter::hasACustomAddress() {
	if(executionConfig->debugYellowRecvAddr.getIp() != vss::DEFAULT_DEBUG_RECV_ADDR)
		return true;

	if(executionConfig->debugBlueRecvAddr.getIp() != vss::DEFAULT_DEBUG_RECV_ADDR)
		return true;

	if(executionConfig->debugYellowRecvAddr.getPort() != vss::DEFAULT_DEBUG_YELLOW_PORT)
		return true;

	if(executionConfig->debugBlueRecvAddr.getPort() != vss::DEFAULT_DEBUG_BLUE_PORT)
		return true;

	return false;
}
