//
// Created by johnathan on 30/05/18.
//

#include <Domain/Point.h>

namespace vss {

    Point::Point() {
        x = 0;
        y = 0;
    }

    Point::Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    std::ostream &operator<<(std::ostream &os, const Point &point) {
        return os << "Point(" << point.x << ", " << point.y << ")";
    }

    bool operator==(const Point &lhs, const Point &rhs) {
        if(lhs.x != rhs.x)
            return false;

        if(lhs.y != rhs.y)
            return false;

        return true;
    }

    bool operator!=(const Point &lhs, const Point &rhs) {
        if(lhs.x != rhs.x)
            return true;

        if(lhs.y != rhs.y)
            return true;

        return false;
    }

    Point operator-(const Point &lhs, const Point &rhs) {
        return Point(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    Point operator+(const Point &lhs, const Point &rhs) {
        return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    }

}

