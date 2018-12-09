//
// Created by johnathan on 27/05/18.
//

#include "Helpers/StateMapper.h"

namespace vss {

    namespace StateMapper {

        State globalStateToState(vss_state::Global_State _globalState){
            State state;

            state.ball = ballStateToBall(_globalState.balls(0));

            for (int i = 0; i < _globalState.robots_blue_size(); i++) {
                state.teamBlue.push_back(robotStateToRobot(_globalState.robots_blue(i)));
            }

            for (int i = 0; i < _globalState.robots_yellow_size(); i++) {
                state.teamYellow.push_back(robotStateToRobot(_globalState.robots_yellow(i)));
            }

            return state;
        }

        Robot robotStateToRobot(vss_state::Robot_State robot_state) {
            Robot robot;

            robot.x = robot_state.pose().x();
            robot.y = robot_state.pose().y();
            robot.angle = robot_state.pose().yaw();

            robot.speedX = robot_state.v_pose().x();
            robot.speedY = robot_state.v_pose().y();
            robot.speedAngle = robot_state.v_pose().yaw();

            return robot;
        }

        Ball ballStateToBall(vss_state::Ball_State ball_state) {
            Ball ball;

            ball.x = ball_state.pose().x();
            ball.y = ball_state.pose().y();

            ball.speedX = ball_state.v_pose().x();
            ball.speedY = ball_state.v_pose().y();

            return ball;
        }

        vss_state::Global_State stateToGlobalState(State state){
            vss_state::Global_State globalState;

            auto ball = globalState.add_balls();
            setupBallState(ball, state.ball);

            for(unsigned int i = 0 ; i < state.teamYellow.size() ; i++){
                auto robot = globalState.add_robots_yellow();
                setupRobotState(robot, state.teamYellow[i]);
            }

            for(unsigned int i = 0 ; i < state.teamBlue.size() ; i++){
                auto robot = globalState.add_robots_blue();
                setupRobotState(robot, state.teamBlue[i]);
            }

            return globalState;
        }

        void setupRobotState(vss_state::Robot_State *robotState, Robot robot){
            robotState->mutable_pose()->set_x(robot.x);
            robotState->mutable_pose()->set_y(robot.y);
            robotState->mutable_pose()->set_yaw(robot.angle);

            robotState->mutable_v_pose()->set_x(robot.speedX);
            robotState->mutable_v_pose()->set_y(robot.speedY);
            robotState->mutable_v_pose()->set_yaw(robot.speedAngle);
        }

        void setupBallState(vss_state::Ball_State *ballState, Ball ball){
            ballState->mutable_pose()->set_x(ball.x);
            ballState->mutable_pose()->set_y(ball.y);

            ballState->mutable_v_pose()->set_x(ball.speedX);
            ballState->mutable_v_pose()->set_y(ball.speedY);
        }

    }

}