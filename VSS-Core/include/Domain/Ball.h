#ifndef _BALL_H_
#define _BALL_H_

#include "Point.h"

namespace vss {

    class Ball : public Point {
    public:
        Ball();
        Ball(float x, float y, float speedX, float speedY);

        friend std::ostream& operator<<(std::ostream& os, const Ball& ball);
        friend bool operator==(const Ball& lhs, const Ball& rhs);
        friend bool operator!=(const Ball& lhs, const Ball& rhs);
        friend Ball operator-(const Ball& lhs, const Ball& rhs);
        friend Ball operator+(const Ball& lhs, const Ball& rhs);

        float speedX;
        float speedY;
    };

}

#endif