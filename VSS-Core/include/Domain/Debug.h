//
// Created by johnathan on 29/05/18.
//

#ifndef VSS_CORE_DEBUGINFO_H
#define VSS_CORE_DEBUGINFO_H

#include <vector>
#include "Point.h"
#include "Pose.h"
#include "Path.h"

namespace vss {

    class Debug {
    public:
        Debug();
        Debug(std::vector<Point> stepPoints, std::vector<Pose> finalPoses, std::vector<Path> paths);

        friend std::ostream& operator<<(std::ostream& os, const Debug& debug);

        std::vector<Point> stepPoints;
        std::vector<Pose> finalPoses;
        std::vector<Path> paths;
    };

}

#endif //VSS_CORE_DEBUGINFO_H
