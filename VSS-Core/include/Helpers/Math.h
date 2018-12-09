//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_MATH_H
#define VSS_CORE_MATH_H

#include <Domain/Point.h>

namespace vss {

    namespace Math {

        float distance(const vss::Point &t1, const vss::Point &t2);
        float angleBetween(const vss::Point &t1, const vss::Point &t2);
        float radianBetween(const vss::Point &t1, const vss::Point &t2);

    }

}

#endif //VSS_CORE_MATH_H
