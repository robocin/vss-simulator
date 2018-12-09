/*
 * This file is part of the VSS-SampleStrategy project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include <Communications/StateReceiver.h>
#include <Communications/CommandSender.h>
#include <Communications/DebugSender.h>
#include "cstdlib"
#include <getopt.h>
#include <string>
#include <getopt.h>
#include <string>
#include "generic_player.hpp"
#include "generic_player1.hpp"
#include "generic_player2.hpp"

using namespace vss;

IStateReceiver *stateReceiver;
ICommandSender *commandSender;
IDebugSender *debugSender;

State state;

void send_commands(WheelsCommand, WheelsCommand, WheelsCommand ); 
void send_debug();

int main(int argc, char** argv){
    srand(time(NULL));

    TeamType team = TeamType::Yellow;

    int opt, opt_index;

    static struct option long_options[]{
        {"team", required_argument, 0, 't'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

        while ((opt = getopt_long(argc, argv, "t:h", long_options, &opt_index)) != -1)
        {
            switch (opt) {
                case 't':
                {
                    std::string arg = optarg;
                    if (arg == "blue") team = TeamType::Blue;
                    else if (arg == "yellow") team = TeamType::Yellow;
                    else {
                        printf("Invalid team.\n");
                        exit(-1);
                    }

                    break;
                }
                case 'h':
                {
                    printf("Usage: $ vss-sample [options]\n");
                    printf("-t, --team [team-type]\n\t[blue]\n\t[yellow]\n"
                           "-h, --help\n");
                    exit(0);
                    break;
                }
                case '?': {
                    printf("Invalid argument. Please try again.\n");
                    exit(-1);
                    break;
                }
                default:{
                    abort();
                }
            }
        }

        GenericPlayer player1(team);
        GenericPlayer1 player2(team);
        GenericPlayer2 player3(team);

        stateReceiver = new StateReceiver();
        commandSender = new CommandSender();
        debugSender = new DebugSender();

        stateReceiver->createSocket();
        commandSender->createSocket(team);
        debugSender->createSocket(team);

        while (true)
        {
            state = stateReceiver->receiveState(FieldTransformationType::None);

            WheelsCommand player1_command = player1.update(state, 0);
            WheelsCommand player2_command = player2.update(state, 1);
            WheelsCommand player3_command = player3.update(state, 2);

            std::cout << state << std::endl;

            send_commands(player1_command, player2_command, player3_command);
            //send_debug();
        }

        return 0;
}

void send_commands(WheelsCommand player1Command, WheelsCommand player2Command, WheelsCommand player3Command)
{
    Command command;

    for(int i = 0 ; i < 3 ; i++){
        command.commands.push_back(WheelsCommand(10, -10));
    }

    command.commands[0] = player1Command;
    command.commands[1] = player2Command;
    command.commands[2] = player3Command;

    commandSender->sendCommand(command);
}


void send_debug(){
    vss::Debug debug;

    for(unsigned int i = 0 ; i < 3 ; i++){
        debug.stepPoints.push_back(Point(85 + rand()%20, 65 + rand()%20));
    }

    for(unsigned int i = 0 ; i < 3 ; i++){
        debug.finalPoses.push_back(Pose(85 + rand()%20, 65 + rand()%20, rand()%20));
    }

    for(unsigned int i = 0 ; i < 3 ; i++){
        vss::Path path;
        path.points.push_back(Point(85, 65));
        path.points.push_back(Point(85 + rand()%20, 65 + rand()%20));
    }

    debugSender->sendDebug(debug);
}
