//
// Created by johnathan on 30/05/18.
//

#ifndef VSS_CORE_PATH_H
#define VSS_CORE_PATH_H

#include <vector>
#include "Point.h"

namespace vss {

    class Path {
    public:
        Path();
        Path(std::vector<Point> points);

        friend std::ostream& operator<<(std::ostream& os, const Path& path);

        std::vector<Point> points;
    };

}

#endif //VSS_CORE_PATH_H
