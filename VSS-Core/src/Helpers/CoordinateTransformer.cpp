#include <Domain/Constants.h>
#include "Helpers/CoordinateTransformer.h"

namespace vss{

    namespace CoordinateTransformer{

        State spinField180Degrees(State state){

            state.ball = spin180Degrees(state.ball);

            for (unsigned int i = 0; i < state.teamYellow.size(); i++) {
                state.teamYellow[i] = spin180Degrees(state.teamYellow[i]);
            }

            for (unsigned int i = 0; i < state.teamBlue.size(); i++) {
                state.teamBlue[i] = spin180Degrees(state.teamBlue[i]);
            }

            return state;
        }

        Robot spin180Degrees(Robot robot){
            robot.x = vss::MAX_COORDINATE_X - robot.x;
            robot.y = vss::MAX_COORDINATE_Y - robot.y;

            if (robot.angle + (vss::MAX_ANGLE_VALUE/2) > vss::MAX_ANGLE_VALUE){
                robot.angle = robot.angle - (vss::MAX_ANGLE_VALUE/2);
            } else {
                robot.angle = robot.angle + (vss::MAX_ANGLE_VALUE/2);
            }

            robot.speedX = -robot.speedX;
            robot.speedY = -robot.speedY;
            robot.speedAngle = -robot.speedAngle;

            return robot;
        }

        Ball spin180Degrees(Ball ball){
            ball.x = vss::MAX_COORDINATE_X - ball.x;
            ball.y = vss::MAX_COORDINATE_Y - ball.y;

            ball.speedX = -ball.speedX;
            ball.speedY = -ball.speedY;

            return ball;
        }

    }

}