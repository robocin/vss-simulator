//
// Created by manoel on 04/04/18.
//

#include "../include/StartPositionsHelper.h"

vector<btVector3> StartPositionsHelper::positions = {btVector3(155, 4, 65),
                                                      btVector3(95, 4, 55),
                                                      btVector3(95, 4, 95),

                                                      btVector3(15, 4, 65),
                                                      btVector3(75, 4, 75),
                                                      btVector3(75, 4, 35)};

vector<btVector3> StartPositionsHelper::angulations = {btVector3( 0, 90, 0 ),
                                              btVector3( 0, 90, 0 ),
                                              btVector3( 0, 90, 0 ),
                                              btVector3( 0, -140, 0 ),
                                              btVector3( 0, 90, 0 ),
                                              btVector3( 0, 90, 0 )};

btVector3 StartPositionsHelper::positionBall = btVector3( 85, 0, 65 );

bool StartPositionsHelper::useFile = false;

bool StartPositionsHelper::parse(string path){

    /**
     * File should follow the template:
     * x1 y1 th1
     * x2 y2 th2
     * ...
     * xB yB
     *
     * Where, x1 corresponds to robot's 1 x coordinate and y1 to robot 1 y coordinate
     * Should repeat for every robot and finish with ball's coordinates
     */

    ifstream file(path);
    if(!file.is_open()) return false;

    positions.clear(); angulations.clear();

    positions.resize(6);
    angulations.resize(6);

    useFile = true;

    int ang, x, y;

    for(int i=0 ; i<6 ; i++){
        file >> x; file >> y; file >> ang;

        positions[i] = btVector3(x, 4, y);
        angulations[i] = btVector3(0, ang, 0);
    }

    file >> x; file >> y;
    positionBall = btVector3(x, 0, y);

//    for(auto i : positions){
//        cout << i.x() << " " << i.z() << endl;
//    }
//
//    for(auto i : angulations){
//        cout << i.y() << endl;
//    }
//
//    cout << positionBall.x() << " " << positionBall.z() << endl;

    file.close();

    return true;
}
