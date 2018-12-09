
#include <Domain/Ball.h>

#include "Domain/Ball.h"

namespace vss{

    Ball::Ball() {
        x = 0;
        y = 0;
        speedX = 0;
        speedY = 0;
    }

    Ball::Ball(float x, float y, float speedX, float speedY) {
        this->x = x;
        this->y = y;
        this->speedX = speedX;
        this->speedY = speedY;
    }

    std::ostream &operator<<(std::ostream &os, const Ball &ball) {
        return os << "Ball(" << ball.x << ", " << ball.y << ", " << ball.speedX << ", " << ball.speedY << ")";
    }

    bool operator==(const Ball &lhs, const Ball &rhs) {
        if(lhs.x != rhs.x)
            return false;

        if(lhs.y != rhs.y)
            return false;

        if(lhs.speedX != rhs.speedX)
            return false;

        if(lhs.speedY != rhs.speedY)
            return false;

        return true;
    }

    bool operator!=(const Ball &lhs, const Ball &rhs) {
        if(lhs.x != rhs.x)
            return true;

        if(lhs.y != rhs.y)
            return true;

        if(lhs.speedX != rhs.speedX)
            return true;

        if(lhs.speedY != rhs.speedY)
            return true;

        return false;
    }

    Ball operator-(const Ball &lhs, const Ball &rhs) {
        return Ball(lhs.x - rhs.x, lhs.y - rhs.y, lhs.speedX - rhs.speedX, lhs.speedY - rhs.speedY);
    }

    Ball operator+(const Ball &lhs, const Ball &rhs) {
        return Ball(lhs.x + rhs.x, lhs.y + rhs.y, lhs.speedX + rhs.speedX, lhs.speedY + rhs.speedY);
    }

}