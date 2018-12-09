//
// Created by johnathan on 30/05/18.
//

#include <Domain/Path.h>

namespace vss {

    Path::Path() {}

    Path::Path(std::vector<Point> points) {
        this->points = points;
    }

    std::ostream &operator<<(std::ostream &os, const Path &path) {
        os << "Path {" << std::endl;

        for(unsigned int i = 0 ; i < path.points.size() ; i++){
            os << "\t" << path.points[i] << std::endl;
        }

        os << "}";

        return os;
    }
}