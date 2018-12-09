//
// Created by johnathan on 31/05/18.
//

#include <cmath>
#include "Helpers/Math.h"

namespace vss {

    namespace Math {

        float distance( const vss::Point &t1, const vss::Point &t2 ){
            return std::sqrt(((t1.x - t2.x) * (t1.x - t2.x)) + ((t1.y - t2.y) * (t1.y - t2.y)));
        }

        float angleBetween(const vss::Point &t1, const vss::Point &t2) {
            return static_cast<float>(std::atan2(t2.x - t1.x, t2.y - t1.y) * (180.0 / M_PI));
        }

        float radianBetween(const vss::Point &t1, const vss::Point &t2) {
            return static_cast<float>(std::atan2(t2.x - t1.x, t2.y - t1.y));
        }

    }

}