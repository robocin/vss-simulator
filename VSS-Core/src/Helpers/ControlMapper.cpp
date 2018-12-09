//
// Created by johnathan on 31/05/18.
//

#include "Helpers/ControlMapper.h"

namespace vss {

    namespace ControlMapper {

        vss_control::User_Control controlToUserControl(Control control) {
            vss_control::User_Control userControl;

            userControl.set_paused(control.paused);
            userControl.mutable_new_ball_pose()->set_x( control.ball.x );
            userControl.mutable_new_ball_pose()->set_y( control.ball.y );

            for(unsigned int i = 0 ; i < control.teamYellow.size() ; i++){
                auto yellowRobot = userControl.add_new_robots_yellow_pose();
                setupNewRobotPose(yellowRobot, control.teamYellow[i]);
            }

            for(unsigned int i = 0 ; i < control.teamBlue.size() ; i++){
                auto blueRobot = userControl.add_new_robots_blue_pose();
                setupNewRobotPose(blueRobot, control.teamBlue[i]);
            }

            return userControl;
        }

        void setupNewRobotPose(vss_control::Pose *pose, Robot robot){
            pose->set_x(robot.x);
            pose->set_y(robot.y);
            pose->set_yaw(robot.angle);
        }

        Control userControlToControl(vss_control::User_Control userControl) {
            Control control;

            control.paused = userControl.paused();
            control.ball.x = userControl.mutable_new_ball_pose()->x();
            control.ball.y = userControl.mutable_new_ball_pose()->y();

            for(int i = 0; i < userControl.new_robots_yellow_pose_size(); i++) {
                auto robot = newRobotPoseToRobot(userControl.new_robots_yellow_pose(i));
                control.teamYellow.push_back(robot);
            }

            for(int i = 0; i < userControl.new_robots_blue_pose_size(); i++) {
                auto robot = newRobotPoseToRobot(userControl.new_robots_blue_pose(i));
                control.teamBlue.push_back(robot);
            }

            return control;
        }

        Robot newRobotPoseToRobot(vss_control::Pose newRobotPose){
            Robot robot;

            robot.x = newRobotPose.x();
            robot.y = newRobotPose.y();
            robot.angle = newRobotPose.yaw();

            return robot;
        }
    }

}