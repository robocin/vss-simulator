//
// Created by manoel on 04/04/18.
//

#ifndef VSS_SIMULATOR_INPUTPARSER_HPP
#define VSS_SIMULATOR_INPUTPARSER_HPP

#include "../include/Header.h"

#include <fstream>

class StartPositionsHelper {

public:

    static bool parse(string path);

    static vector<btVector3> positions;
    static vector<btVector3> angulations;

    static btVector3 positionBall;

    static bool useFile;
};

#endif //VSS_SIMULATOR_INPUTPARSER_HPP
