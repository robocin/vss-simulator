//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_COMMANDMAPPER_H
#define VSS_CORE_COMMANDMAPPER_H

#include <protos/command.pb.h>
#include <Domain/Command.h>

namespace vss {

    namespace CommandMapper {

        vss_command::Global_Commands commandToGlobalCommands(Command command);
        void setupWheelCommand(vss_command::Robot_Command *robotCommand, WheelsCommand wheelsCommand);

        Command globalCommandsToCommand(vss_command::Global_Commands);
        WheelsCommand robotCommandToWheelsCommand(vss_command::Robot_Command robotCommand);

    }

}

#endif //VSS_CORE_COMMANDMAPPER_H
