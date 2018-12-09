//
// Created by johnathan on 31/05/18.
//

#include <Domain/Ball.h>
#include <Domain/Robot.h>
#include <Domain/State.h>
#include <Domain/WheelsCommand.h>
#include <Domain/Command.h>
#include <Domain/Path.h>
#include <Domain/Constants.h>
#include <Domain/Debug.h>
#include <Domain/Control.h>
#include <protos/command.pb.h>
#include <Domain/Address.h>

namespace vss {

    namespace DomainRandomizer {

        Point createRandomPoint() {
            srand(static_cast<unsigned int>(time(NULL)));

            Point point;

            point.x = rand() % MAX_COORDINATE_X;
            point.y = rand() % MAX_COORDINATE_Y;

            return point;
        }

        Pose createRandomPose() {
            srand(static_cast<unsigned int>(time(NULL)));

            Pose pose;

            pose.x = rand() % MAX_COORDINATE_X;
            pose.y = rand() % MAX_COORDINATE_Y;
            pose.angle = rand() % MAX_ANGLE_VALUE;

            return pose;
        }

        Ball createRandomBall() {
            srand(static_cast<unsigned int>(time(NULL)));

            Ball ball;

            ball.x = rand() % MAX_COORDINATE_X;
            ball.y = rand() % MAX_COORDINATE_Y;
            ball.speedX = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);
            ball.speedY = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);

            return ball;
        }

        Robot createRandomRobot() {
            srand(static_cast<unsigned int>(time(NULL)));

            Robot robot;

            robot.x = rand() % MAX_COORDINATE_X;
            robot.y = rand() % MAX_COORDINATE_Y;
            robot.angle = rand() % MAX_ANGLE_VALUE;
            robot.speedX = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);
            robot.speedY = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);
            robot.speedAngle = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);

            return robot;
        }

        Path createRandomPath() {
            srand(static_cast<unsigned int>(time(NULL)));
            Path path;

            auto size = static_cast<unsigned int>(rand() % MAX_RANDOM_PATH_SIZE);

            for(unsigned int i = 0 ; i < size ; i++){
                path.points.push_back(createRandomPoint());
            }

            return path;
        }

        State createRandomState(){
            srand(static_cast<unsigned int>(time(NULL)));
            State state;

            auto sizeTeamYellow = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);
            auto sizeTeamBlue = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);
            state.ball = createRandomBall();

            for(unsigned int i = 0 ; i < sizeTeamYellow ; i++){
                state.teamYellow.push_back(createRandomRobot());
            }

            for(unsigned int i = 0 ; i < sizeTeamBlue ; i++){
                state.teamBlue.push_back(createRandomRobot());
            }

            return state;
        }

        WheelsCommand createRandomWheelsCommand() {
            srand(static_cast<unsigned int>(time(NULL)));
            WheelsCommand wheelsCommand;

            wheelsCommand.leftVel = (rand() % MAX_RANDOM_WHEEL_COMMAND) * (rand()%2 == 0 ? -1 : 1);
            wheelsCommand.rightVel = (rand() % MAX_RANDOM_WHEEL_COMMAND) * (rand()%2 == 0 ? -1 : 1);

            return wheelsCommand;
        }

        Command createRandomCommand() {
            srand(static_cast<unsigned int>(time(NULL)));
            Command command;

            auto size = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);

            for(unsigned int i = 0 ; i < size ; i++){
                command.commands.push_back(createRandomWheelsCommand());
            }

            return command;
        }

        Debug createRandomDebug() {
            srand(static_cast<unsigned int>(time(NULL)));
            Debug debug;

            auto robotsAmount = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);

            for(unsigned int i = 0 ; i < robotsAmount ; i++){
                debug.stepPoints.push_back(createRandomPoint());
                debug.finalPoses.push_back(createRandomPose());
                debug.paths.push_back(createRandomPath());
            }

            return debug;
        }

        Control createRandomControl() {
            srand(static_cast<unsigned int>(time(NULL)));
            Control control;

            control.paused = (rand()%2 == 0);
            control.ball = createRandomBall();

            auto robotsAmount = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);

            for(unsigned int i = 0 ; i < robotsAmount ; i++){
                control.teamYellow.push_back(createRandomRobot());
                control.teamBlue.push_back(createRandomRobot());
            }

            return control;
        }

        Address createRandomAddress() {
            srand(static_cast<unsigned int>(time(NULL)));
            std::stringstream ss;

            ss << (rand() % MAX_RANDOM_IP_VALUE) << "." << (rand() % MAX_RANDOM_IP_VALUE) << "." << (rand() % MAX_RANDOM_IP_VALUE) << "." << (rand() % MAX_RANDOM_IP_VALUE);

            return Address(ss.str(), (rand() % MAX_RANDOM_PORT_VALUE));
        }

        vss_command::Robot_Command createRandomRobotCommand(){
            vss_command::Robot_Command robotCommand;

            robotCommand.set_left_vel((rand() % MAX_RANDOM_WHEEL_COMMAND) * (rand()%2 == 0 ? -1 : 1));
            robotCommand.set_right_vel((rand() % MAX_RANDOM_WHEEL_COMMAND) * (rand()%2 == 0 ? -1 : 1));

            return robotCommand;
        }

        vss_command::Global_Commands createRandomGlobalCommands(){
            srand(static_cast<unsigned int>(time(NULL)));
            vss_command::Global_Commands globalCommands;

            auto size = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);

            for(unsigned int i = 0 ; i < size ; i++){
                auto robot_command = globalCommands.add_robot_commands();
                *robot_command = createRandomRobotCommand();
            }

            return globalCommands;
        }

    }

}