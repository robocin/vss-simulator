//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_DOMAINRANDOMIZER_H
#define VSS_CORE_DOMAINRANDOMIZER_H

#include <Domain/Ball.h>
#include <Domain/Robot.h>
#include <Domain/State.h>
#include <Domain/WheelsCommand.h>
#include <Domain/Command.h>
#include <Domain/Path.h>
#include <Domain/Debug.h>
#include <Domain/Control.h>
#include <Domain/Address.h>
#include <protos/command.pb.h>

namespace vss {

    namespace DomainRandomizer {

        Point createRandomPoint();
        Pose createRandomPose();
        Ball createRandomBall();
        Robot createRandomRobot();
        Path createRandomPath();
        State createRandomState();
        WheelsCommand createRandomWheelsCommand();
        Command createRandomCommand();
        Debug createRandomDebug();
        Control createRandomControl();
        Address createRandomAddress();

        vss_command::Robot_Command createRandomRobotCommand();
        vss_command::Global_Commands createRandomGlobalCommands();

    }

}

#endif //VSS_CORE_DOMAINRANDOMIZER_H
