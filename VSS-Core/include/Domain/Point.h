//
// Created by johnathan on 30/05/18.
//

#ifndef VSS_CORE_POINT_H
#define VSS_CORE_POINT_H

#include <iostream>

namespace vss {

    class Point {
    public:
        Point();
        Point(float x, float y);

        friend std::ostream& operator<<(std::ostream& os, const Point& point);
        friend bool operator==(const Point& lhs, const Point& rhs);
        friend bool operator!=(const Point& lhs, const Point& rhs);
        friend Point operator-(const Point& lhs, const Point& rhs);
        friend Point operator+(const Point& lhs, const Point& rhs);

        float x;
        float y;
    };

}

#endif //VSS_CORE_POINT_H
