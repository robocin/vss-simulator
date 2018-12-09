/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef DEBUG_RECEIVER_H
#define DEBUG_RECEIVER_H

#include "mutex"
#include "vector"
#include "Domain/Pose.h"
#include "Domain/Path.h"
#include "math.h"
#include "Domain/TeamType.h"
#include "Interfaces/IDebugReceiver.h"

class DebugReceiverAdapter {
public:

    vss::IDebugReceiver *debugReceiver;
    vss::ExecutionConfig *executionConfig;
    std::vector<vss::Pose> *finalPoses;
    std::vector<vss::Pose> *stepPoses;
    std::vector<vss::Path> *paths;
    std::mutex *mutexDebug;

    DebugReceiverAdapter( std::vector<vss::Path> *paths, std::vector<vss::Pose> *stepPoses, std::vector<vss::Pose> *finalPoses, std::mutex *mutexDebug, vss::ExecutionConfig* );

    void loop( vss::TeamType teamType );

protected:
    bool hasACustomAddress();
};

#endif // DEBUG_RECEIVER_H
