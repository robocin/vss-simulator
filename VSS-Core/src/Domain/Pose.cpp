//
// Created by johnathan on 30/05/18.
//

#include <Domain/Pose.h>

namespace vss {

    Pose::Pose() {
        x = 0;
        y = 0;
        angle = 0;
    }

    Pose::Pose(float x, float y, float angle) {
        this->x = x;
        this->y = y;
        this->angle = angle;
    }

    std::ostream &operator<<(std::ostream &os, const Pose &pose) {
        return os << "Pose(" << pose.x << ", " << pose.y << ", " << pose.angle << ")";
    }

    bool operator==(const Pose &lhs, const Pose &rhs) {
        if(lhs.x != rhs.x)
            return false;

        if(lhs.y != rhs.y)
            return false;

        if(lhs.angle != rhs.angle)
            return false;

        return true;
    }

    bool operator!=(const Pose &lhs, const Pose &rhs) {
        if(lhs.x != rhs.x)
            return true;

        if(lhs.y != rhs.y)
            return true;

        if(lhs.angle != rhs.angle)
            return true;

        return false;
    }

    Pose operator-(const Pose &lhs, const Pose &rhs) {
        return Pose(lhs.x - rhs.x, lhs.y - rhs.y, lhs.angle - rhs.angle);
    }

    Pose operator+(const Pose &lhs, const Pose &rhs) {
        return Pose(lhs.x + rhs.x, lhs.y + rhs.y, lhs.angle + rhs.angle);
    }

}

