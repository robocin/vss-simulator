//
// Created by johnathan on 27/05/18.
//

#include "Domain/Command.h"

namespace vss {
    Command::Command() = default;

    Command::Command(std::vector<WheelsCommand> commands) {
        this->commands = commands;
    }

    std::ostream &operator<<(std::ostream &os, const Command &command) {
        os << "Commands {" << std::endl;

        for(unsigned int i = 0 ; i < command.commands.size() ; i++){
            os << "\t" << command.commands[i] << std::endl;
        }

        os << "}";

        return os;
    }
}
