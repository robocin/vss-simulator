//
// Created by johnathan on 27/05/18.
//

#include <iostream>
#include "Helpers/CommandMapper.h"

namespace vss {

    namespace CommandMapper {

        vss_command::Global_Commands commandToGlobalCommands(Command command) {
            vss_command::Global_Commands commands;

            for (unsigned int i = 0; i < command.commands.size() ; i++) {
                auto ref = commands.add_robot_commands();
                setupWheelCommand(ref, command.commands[i]);
            }

            return commands;
        }

        void setupWheelCommand(vss_command::Robot_Command *robotCommand, WheelsCommand wheelsCommand) {
            robotCommand->set_left_vel(wheelsCommand.leftVel);
            robotCommand->set_right_vel(wheelsCommand.rightVel);
        }

        Command globalCommandsToCommand(vss_command::Global_Commands globalCommands) {
            Command command;

            for (int i = 0 ; i < globalCommands.robot_commands_size() ; i++){
                auto wheelsCommand = robotCommandToWheelsCommand(globalCommands.robot_commands(i));
                command.commands.push_back(wheelsCommand);
            }

            return command;
        }

        WheelsCommand robotCommandToWheelsCommand(vss_command::Robot_Command robotCommand){
            WheelsCommand wheelsCommand;

            wheelsCommand.rightVel = robotCommand.right_vel();
            wheelsCommand.leftVel = robotCommand.left_vel();

            return wheelsCommand;
        }

    }

}

