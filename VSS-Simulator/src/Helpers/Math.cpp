//
// Created by johnathan on 07/07/18.
//

#include <math.h>

namespace Math {

    float radianToDegree(float radian) {
        float degree = static_cast<float>(radian * 180.0 / M_PI);

        if(degree < 0)
            degree = 360 + degree;

        return degree;
    }

    float degreeToRadian(float degree) {
        if(degree > 180)
            degree = (360 - degree)*-1;

        float radian = static_cast<float>(degree * M_PI / 180.0);
        return radian;
    }

};