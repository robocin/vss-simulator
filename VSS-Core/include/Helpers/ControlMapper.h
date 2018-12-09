//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_CONTROLMAPPER_H
#define VSS_CORE_CONTROLMAPPER_H

#include <Domain/Control.h>
#include "protos/control.pb.h"

namespace vss {

    namespace ControlMapper {

        vss_control::User_Control controlToUserControl(Control control);
        void setupNewRobotPose(vss_control::Pose *pose, Robot robot);

        Control userControlToControl(vss_control::User_Control);
        Robot newRobotPoseToRobot(vss_control::Pose newRobotPose);

    }

}

#endif //VSS_CORE_CONTROLMAPPER_H
