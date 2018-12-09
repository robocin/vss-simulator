//
// Created by johnathan on 29/05/18.
//

#include <Domain/Debug.h>

namespace vss{

    Debug::Debug() {

    }

    Debug::Debug(std::vector<Point> stepPoints, std::vector<Pose> finalPoses, std::vector<Path> paths) {
        this->stepPoints = stepPoints;
        this->finalPoses = finalPoses;
        this->paths = paths;
    }

    std::ostream &operator<<(std::ostream &os, const Debug &debug) {
        os << "Debug {" << std::endl;

        for(unsigned int i = 0 ; i < debug.finalPoses.size() ; i++){
            os << "\tRobot {" << std::endl;
            os << "\t\tStep: " << debug.stepPoints[i] << std::endl;
            os << "\t\tFinal: " << debug.finalPoses[i] << std::endl;
            os << "\t\tPath {" << std::endl;
            for(unsigned int j = 0 ; j < debug.paths[i].points.size() ; j++){
                os << "\t\t\t" << debug.paths[i].points[j] << std::endl;
            }
            os << "\t\t}" << std::endl;
            os << "\t}" << std::endl;
        }

        os << "}";

        return os;
    }

}

