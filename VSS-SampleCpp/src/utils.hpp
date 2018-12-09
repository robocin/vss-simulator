#ifndef UTILS_H
#define UTILS_H

#include <math.h>

#define doublePair std::pair <double, double>

namespace Utils {

    /**
     * @brief Estrutura para guardar as informações de uma posição.
     * 
     */
    typedef struct Posture
    {
        double x, y, angle;

        Posture(double x, double y, double angle)
        {
            this->x = x;
            this->y = y;
            this->angle = angle;
        }

    } Posture;

/**
     * @brief Translate a angle from [-PI,PI] to [0, 2*PI]
     * 
     * @param angle 
     * @return double 
     */
double toPositiveAngle(double angle)
{
    return fmod(angle + 2 * M_PI, 2 * M_PI);
    }

    /**
     * @brief Return the minimun angle distance between two angles
     * 
     * @param target 
     * @param source 
     * @return double 
     */
    double smallestAngleDiff(double target, double source)
    {
        double a = Utils::toPositiveAngle(target) - Utils::toPositiveAngle(source);

        if (a > M_PI)
        {
            a = a - 2 * M_PI;
        }
        else if (a < -M_PI)
        {
            a = a + 2 * M_PI;
        }

        return a;
    }

    /**
     * @brief Transform an angle to the range [-PI, PI]
     * 
     * @param angle 
     * @return double 
     */
    double to180range(double angle) {
        angle = fmod(angle, 2 * M_PI);
        if (angle < - M_PI) {
            angle = angle + 2 * M_PI;
        } else if (angle > M_PI) {
            angle = angle - 2 * M_PI;
        }
        return angle;
    }

    /**
     * @brief Return the distance between two points
     * 
     * @param first 
     * @param second 
     * @return double 
     */
    double distance(doublePair first, doublePair second) {
        return std::sqrt(std::pow(first.first - second.first, 2) + std::pow(first.second - second.second, 2));
    }

    /**
     * @brief Transform value x in between low and high
     * 
     * @param x 
     * @param low 
     * @param high 
     * @return double 
     */
    double bound (double x, double low, double high) {
        if (x < low) x = low;
        if (x > high) x = high;
        return x;
    }
}

#endif