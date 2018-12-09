
#include <Domain/Robot.h>

#include "Domain/Robot.h"

namespace vss{

    Robot::Robot() {
        x = 0;
        y = 0;
        angle = 0;
        speedX = 0;
        speedY = 0;
        speedAngle = 0;
    }

    Robot::Robot(float x, float y, float angle, float speedX, float speedY, float speedAngle) {
        this->x = x;
        this->y = y;
        this->angle = angle;
        this->speedX = speedX;
        this->speedY = speedY;
        this->speedAngle = speedAngle;
    }

    std::ostream &operator<<(std::ostream &os, const Robot &robot) {
        return os << "Robot(" << robot.x << ", " << robot.y << ", " << robot.angle << ", " << robot.speedX << ", " << robot.speedY << ", " << robot.speedAngle << ")";
    }

    bool operator==(const Robot &lhs, const Robot &rhs) {
        if(lhs.x != rhs.x)
            return false;

        if(lhs.y != rhs.y)
            return false;

        if(lhs.angle != rhs.angle)
            return false;

        if(lhs.speedX != rhs.speedX)
            return false;

        if(lhs.speedY != rhs.speedY)
            return false;

        if(lhs.speedAngle != rhs.speedAngle)
            return false;

        return true;
    }

    bool operator!=(const Robot &lhs, const Robot &rhs) {
        if(lhs.x != rhs.x)
            return true;

        if(lhs.y != rhs.y)
            return true;

        if(lhs.angle != rhs.angle)
            return true;

        if(lhs.speedX != rhs.speedX)
            return true;

        if(lhs.speedY != rhs.speedY)
            return true;

        if(lhs.speedAngle != rhs.speedAngle)
            return true;

        return false;
    }

    Robot operator-(const Robot &lhs, const Robot &rhs) {
        return Robot(lhs.x - rhs.x, lhs.y - rhs.y, lhs.angle - rhs.angle, lhs.speedX - rhs.speedX, lhs.speedY - rhs.speedY, lhs.speedAngle - rhs.speedAngle);
    }

    Robot operator+(const Robot &lhs, const Robot &rhs) {
        return Robot(lhs.x + rhs.x, lhs.y + rhs.y, lhs.angle + rhs.angle, lhs.speedX + rhs.speedX, lhs.speedY + rhs.speedY, lhs.speedAngle + rhs.speedAngle);
    }

}