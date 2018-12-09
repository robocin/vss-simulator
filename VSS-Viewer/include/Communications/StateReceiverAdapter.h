/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef STATE_RECEIVER_H
#define STATE_RECEIVER_H

#include <Interfaces/IStateReceiver.h>
#include "vector"
#include "Robot3d.h"

class StateReceiverAdapter {
public:

    vss::IStateReceiver *stateReceiver;
    vss::ExecutionConfig *executionConfig;
    vss::Pose *ball;
    std::vector<Robot3d> *robots;

    StateReceiverAdapter( vss::Pose *ball, std::vector<Robot3d> *robots, vss::ExecutionConfig *executionConfig );

    void loop();

protected:
    bool hasCustomAddress();
};

#endif
