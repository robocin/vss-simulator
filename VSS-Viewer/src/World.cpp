/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "World.h"
#include "TopCamera.h"
#include "TvCamera.h"

World::World( IDebugDrawer *debugDrawer, IFieldDrawer *fieldDrawer, IRobotDrawer *robotDrawer, IBallDrawer *ballDrawer,
              ICamera *camera, vss::Pose *ball, std::vector<Robot3d> *robots, std::vector<vss::Path> *pathsTeam1, std::vector<vss::Pose> *stepPosesTeam1,
              std::vector<vss::Pose> *finalPosesTeam1, std::vector<vss::Path> *pathsTeam2, std::vector<vss::Pose> *stepPosesTeam2, std::vector<vss::Pose> *finalPosesTeam2,
              std::mutex *mutexDebugTeamYellow, std::mutex *mutexDebugTeamBlue, vss::ExecutionConfig *executionConfig ){
    this->debugDrawer = debugDrawer;
    this->fieldDrawer = fieldDrawer;
    this->robotDrawer = robotDrawer;
    this->ballDrawer = ballDrawer;
    this->camera = camera;
    this->ball = ball;
    this->robots = robots;
    this->pathsTeam1 = pathsTeam1;
    this->stepPosesTeam1 = stepPosesTeam1;
    this->finalPosesTeam1 = finalPosesTeam1;
    this->pathsTeam2 = pathsTeam2;
    this->stepPosesTeam2 = stepPosesTeam2;
    this->finalPosesTeam2 = finalPosesTeam2;
    this->mutexDebugTeamBlue = mutexDebugTeamBlue;
    this->mutexDebugTeamYellow = mutexDebugTeamYellow;
    this->executionConfig = executionConfig;
    paused = true;

    isBallSelected = false;

    material = new Material();

    controlSender = new ControlSenderAdapter( ball, robots, executionConfig );
}

void World::display() {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();

    camera->applyPosition();
    fieldDrawer->draw();
    ballDrawer->draw( *ball );

    for(unsigned int i = 0; i < robots->size() ; i++){
        robotDrawer->draw( robots->at( i ));
    }

    mutexDebugTeamYellow->lock();

    for(unsigned int i = 0; i < stepPosesTeam1->size(); i++)
        debugDrawer->drawStep( robots->at( i ), stepPosesTeam1->at( i ) );

    for(unsigned int i = 0; i < finalPosesTeam1->size(); i++)
        debugDrawer->drawFinal( robots->at( i ), finalPosesTeam1->at( i ) );

    for(unsigned int i = 0; i < pathsTeam1->size(); i++)
        debugDrawer->drawPath( robots->at( i ), pathsTeam1->at( i ) );

    mutexDebugTeamYellow->unlock();

    mutexDebugTeamBlue->lock();

    for(unsigned int i = 0; i < stepPosesTeam2->size(); i++)
        debugDrawer->drawStep( robots->at( i+3 ), stepPosesTeam2->at( i ) );

    for(unsigned int i = 0; i < finalPosesTeam2->size(); i++)
        debugDrawer->drawFinal( robots->at( i+3 ), finalPosesTeam2->at( i ) );

    for(unsigned int i = 0; i < pathsTeam2->size(); i++)
        debugDrawer->drawPath( robots->at( i+3 ), pathsTeam2->at( i ) );

    mutexDebugTeamBlue->unlock();
}

void World::reshape( int width, int height ) {
    this->windowWidth = width;
    this->windowHeight = height;

    // Aproximadamente
    this->fieldHeight = windowHeight;

    // A largura do campo possui relação com a altura;
    this->fieldWidth = fieldHeight * 1.307592308;

    glViewport( 0, 0, (GLsizei)windowWidth, (GLsizei)windowHeight );
}

void World::mouseButtonPress( int button, int state, int x, int y ){
    mouseAction = (MouseAction)button;
    mouseState = (MouseState)state;

    switch(mouseAction) {
        case MouseAction::ScrollTop: {
            // rotateRobot left
        } break;
        case MouseAction::ScrollDown: {
            // rotateRobot right
        } break;
        case MouseAction::LeftClick: {
            toggleSelectedRobotStrategy( vss::Pose((float)x, (float)y, 0.0 ));
        } break;
        default: {
            std::cout << "[Warning]: Action not assigned." << std::endl;
        } break;
    }
}

void World::mouseMove( int x, int y ){
    if(mouseAction == MouseAction::LeftClick and mouseState == MouseState::On) {
        if (isBallSelected) {
            moveBall( vss::Pose((float) x, (float) y, 0.0));
        }
        else {
            moveRobotStrategy( vss::Pose((float) x, (float) y, 0.0));
        }
    }
}

void World::specialKeyboardDown( int key, int x, int y ){
    auto keyPushed = (SpecialKey)key;

    switch(keyPushed) {
        case SpecialKey::Left: {
            rotateRobotStrategy( true );
        } break;
        case SpecialKey::Right: {
            rotateRobotStrategy( false );
        } break;
        default: {

        } break;
    }
}

void World::keyboardDown( unsigned char key, int x, int y ) {
    auto keyPushed = (Key)key;

    switch(keyPushed) {
        case Key::c: {
            changeCameraStrategy();
        } break;
        case Key::C: {
            changeCameraStrategy();
        } break;
        case Key::Space: {
            controlSender->send( !paused );

            if(paused)
                startStrategy();
            else
                pauseStrategy();
        } break;
        case Key::Esc: {
            closeStrategy();
        } break;
        default: {
            std::cout << keyPushed << std::endl;
        } break;
    }
}

void World::toggleSelectedRobotStrategy( vss::Pose pose ){
    if(!paused)
        return;

    auto t = Core::bulletToGlut( Core::windowToBullet( pose, windowWidth, windowHeight, fieldWidth, fieldHeight ));
    auto tupleClosestRobot = Core::robotMostCloseToClick(t, *robots);
    auto ballDistance = Core::distanceClickToBall(t, *ball);

    if (ballDistance > tupleClosestRobot.first) {
        if(mouseState == MouseState::On) {
            robots->at(tupleClosestRobot.second).setSelected(true);
        }
        else {
            for (unsigned int i = 0; i < robots->size(); i++) {
                robots->at(i).setSelected(false);
            }
        }
    }
    else {
        isBallSelected = mouseState == MouseState::On;
        for(unsigned int i = 0; i < robots->size(); i++) {
            robots->at(i).setSelected(false);
        }
    }
}

void World::moveBall( vss::Pose pose ){
    auto t = Core::bulletToGlut( Core::windowToBullet( pose, windowWidth, windowHeight, fieldWidth, fieldHeight ));
    ball->x = t.x;
    ball->y = t.y;
}


void World::moveRobotStrategy( vss::Pose pose ){
    auto t = Core::bulletToGlut( Core::windowToBullet( pose, windowWidth, windowHeight, fieldWidth, fieldHeight ));
    for(unsigned int i = 0; i < robots->size(); i++)
        if(robots->at( i ).getSelected() == true) {
            robots->at( i ).pose.x = t.x;
            robots->at( i ).pose.y = t.y;
        }
}

void World::rotateRobotStrategy( bool direction ){
    for(unsigned int i = 0; i < robots->size(); i++)
        if(robots->at( i ).getSelected() == true) {
            if(direction)
                robots->at( i ).pose.angle += 3.0;
            else
                robots->at( i ).pose.angle -= 3.0;
        }
}

void World::closeStrategy(){
    std::cout << "[Info]: Exiting VSS-Viewer..." << std::endl;
    exit( 0 );
}

void World::changeCameraStrategy(){
    if(!paused) {
        auto object = (std::string)typeid(*camera).name();

        if (object.find( "TvCamera" ) not_eq std::string::npos) {
            camera = new TopCamera();
            std::cout << "[Info]: Changed camera to Top." << std::endl;
        }else{
            camera = new TvCamera();
            std::cout << "[Info]: Changed camera to Tv." << std::endl;
        }
    }else{
        std::cout << "[Warning]: Can't change camera while simulation is paused. Press <space> to start simulation and enable camera exchange." << std::endl;
    }
}

void World::pauseStrategy(){
    paused = true;
    camera = new TopCamera();
    std::cout << "[Info]: Simulation paused, changed camera to Top and camera exchange disabled." << std::endl;
}

void World::startStrategy(){
    paused = false;
    std::cout << "[Info]: Simulation started, camera exchange enabled." << std::endl;
}
