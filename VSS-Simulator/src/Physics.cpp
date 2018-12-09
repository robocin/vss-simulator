/*
   The MIT License (MIT)

   Copyright (c) 2016 Lucas Borsatto Simão

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
 */

#include "../include/Physics.h"
#include "../../bullet/BulletDynamics/Dynamics/btRigidBody.h"
#include "../include/StartPositionsHelper.h"

Physics::Physics( int numTeams ){

  this->numTeams = numTeams;
  this->numRobotsTeam = NUM_ROBOTS_TEAM;

  broadphase = new btDbvtBroadphase();
  collisionConfig = new btDefaultCollisionConfiguration();
  dispatcher = new btCollisionDispatcher( collisionConfig );
  solver = new btSequentialImpulseConstraintSolver;
  world = new btDiscreteDynamicsWorld( dispatcher, broadphase, solver, collisionConfig );
  world->setGravity( btVector3( 0, -9.81 * simulator::SCALE_WORLD, 0 ));

  //glDebugDrawer = new GLDebugDrawer();
  //world->setDebugDrawer(glDebugDrawer);
  gContactAddedCallback = callBackHitFunc;

  registBodies();
}

Physics::~Physics(){
  deleteWorldObj();

  if(collisionConfig) delete collisionConfig;
  if(dispatcher) delete dispatcher;
  if(broadphase) delete broadphase;
  if(solver) delete solver;
  if(world) delete world;
}

void Physics::deleteWorldObj(){
  for(int i = 0; i < bodies.size(); i++) {
    delete bodies[i];
  }

  for(int i = 0; i < genRobots.size(); i++) {
    delete genRobots[i];
  }
}

void Physics::registBodies(){
  addFloor();

  addBall( 2.5, StartPositionsHelper::positionBall, 0.08 );

  btVector3 posTeam1[] = {btVector3( 25, 4, simulator::FIELD_HEIGHT - 55 ), btVector3( 35, 4, 30 ), btVector3( 55, 4, 45 )};
  btVector3 posTeam2[] = {btVector3( simulator::FIELD_WIDTH - 15, 4, 55 ), btVector3( simulator::FIELD_WIDTH - 25, 4, simulator::FIELD_HEIGHT - simulator::FIELD_HEIGHT / 2.5 + 20 ), btVector3( simulator::FIELD_WIDTH - 55, 4, 85 )};

    //Create robots here
    //Team 1
    if(numTeams >= 1) {
        for(int i = 0; i < numRobotsTeam; i++) {
            addRobot( Color( 0.3, 0.3, 0.3 ), StartPositionsHelper::positions[i], StartPositionsHelper::angulations[i], 8, 0.25, clrPlayers[i], clrTeams[0], i );
        }
    }

    if(numTeams == 2) {
        for(int i = 0; i < numRobotsTeam; i++) {
            addRobot( Color( 0.3, 0.3, 0.3 ), StartPositionsHelper::positions[i+3], StartPositionsHelper::angulations[i+3], 8, 0.25, clrPlayers[i], clrTeams[1], numRobotsTeam + i );
        }
    }

//    for(int i = 0; i < (numRobotsTeam * numTeams); i++) {
//      addRobot( Color( 0.3, 0.3, 0.3 ), StartPositionsHelper::positions[i], StartPositionsHelper::angulations[i], 8, 0.25, clrPlayers[i % numRobotsTeam], clrTeams[i / numRobotsTeam], i );
//    }

  // PAREDE DE CIMA
  addWall( Color( 0, 0, 0 ), btVector3((simulator::FIELD_WIDTH / 2.0) + simulator::GOAL_WIDTH, 0, 0 ), simulator::FIELD_WIDTH, 15, 2.5, 0 );
  // PAREDE DE BAIXO
  addWall( Color( 0, 0, 0 ), btVector3((simulator::FIELD_WIDTH / 2.0) + simulator::GOAL_WIDTH, 0, simulator::FIELD_HEIGHT ), simulator::FIELD_WIDTH, 15, 2.5, 0 );

  // GOL ESQUERDO
  addWall( Color( 0, 0, 0 ), btVector3( 0, 0, simulator::FIELD_HEIGHT / 2.0 ), 2.5, 15, 40.0, 0 );
  // PAREDE DE CIMA DO GOL ESQUERDO
  addWall( Color( 0, 0, 0 ), btVector3( simulator::GOAL_WIDTH, 0, 45 / 2.0 - 1.25 ), 2.5, 15, 45.0, 0 );
  // PAREDE DE BAIXO DO GOL ESQUERDO
  addWall( Color( 0, 0, 0 ), btVector3( simulator::GOAL_WIDTH, 0, simulator::FIELD_HEIGHT - (45 / 2.0) + 1.25 ), 2.5, 15, 45.0, 0 );
  // PAREDE DE CIMA DENTRO DO GOL ESQUERDO
  addWall( Color( 0, 0, 0 ), btVector3((simulator::GOAL_WIDTH / 2.0), 0, simulator::FIELD_HEIGHT / 2.0 - (45 / 2.0) ), simulator::GOAL_WIDTH, 15, 2.5, 0 );
  // PAREDE DE BAIXO DENTRO DO GOL ESQUERDO
  addWall( Color( 0, 0, 0 ), btVector3((simulator::GOAL_WIDTH / 2.0), 0, simulator::FIELD_HEIGHT / 2.0 + (45 / 2.0) ), simulator::GOAL_WIDTH, 15, 2.5, 0 );

  // GOL DIREITO
  addWall( Color( 0, 0, 0 ), btVector3( simulator::FIELD_WIDTH + (2.0 * simulator::GOAL_WIDTH), 0, simulator::FIELD_HEIGHT / 2.0 ), 2.5, 15, 40.0, 0 );
  // PAREDE DE CIMA DO GOL DIREITO
  addWall( Color( 0, 0, 0 ), btVector3( simulator::FIELD_WIDTH + simulator::GOAL_WIDTH, 0, (45 / 2.0) - 1.25 ), 2.5, 15, 45.0, 0 );
  // PAREDE DE BAIXO DO GOL DIREITO
  addWall( Color( 0, 0, 0 ), btVector3( simulator::FIELD_WIDTH + simulator::GOAL_WIDTH, 0, simulator::FIELD_HEIGHT - (45 / 2.0) + 1.25 ), 2.5, 15, 45.0, 0 );
  // PAREDE DE CIMA DENTRO DO GOL DIREITO
  addWall( Color( 0, 0, 0 ), btVector3( simulator::FIELD_WIDTH + (2.0 * simulator::GOAL_WIDTH) - (simulator::GOAL_WIDTH / 2.0), 0, simulator::FIELD_HEIGHT / 2.0 - (45 / 2.0)), simulator::GOAL_WIDTH, 15, 2.5, 0 );
  // PAREDE DE BAIXO DENTRO DO GOL DIREITO
  addWall( Color( 0, 0, 0 ), btVector3( simulator::FIELD_WIDTH + (2.0 * simulator::GOAL_WIDTH) - (simulator::GOAL_WIDTH / 2.0), 0, simulator::FIELD_HEIGHT / 2.0 + (45 / 2.0)), simulator::GOAL_WIDTH, 15, 2.5, 0 );

  // TRIANGULO SUPERIOR ESQUERDO
  addCorner( Color( 0, 0, 0 ), btVector3( simulator::FIELD_WIDTH + (simulator::GOAL_WIDTH), 0, simulator::GOAL_WIDTH + 1.25 ), 45, 15, btVector3( 0, -45, 0 ));
  // TRIANGULO SUPERIOR DIREITO
  addCorner( Color( 0, 0, 0 ), btVector3( simulator::GOAL_WIDTH, 0, simulator::GOAL_WIDTH + 1.25 ), 45, 15, btVector3( 0, 45, 0 ));

  // TRIANGULO INFERIOR ESQUERDO
  addCorner( Color( 0, 0, 0 ), btVector3( simulator::GOAL_WIDTH + 1.25, 0, simulator::FIELD_HEIGHT - simulator::GOAL_WIDTH + 1.25 ), 45, 15, btVector3( 0, -45, 0 ));
  // TRIANGULO INFERIOR DIREITO
  addCorner( Color( 0, 0, 0 ), btVector3( simulator::FIELD_WIDTH + simulator::GOAL_WIDTH - 1.25, 0, simulator::FIELD_HEIGHT - simulator::GOAL_WIDTH - 1.25 ), 45, 15, btVector3( 0, 45, 0 ));

}

void Physics::resetRobotPositions(){
  btVector3 posTeam1[] = {btVector3( 15, 4, simulator::FIELD_HEIGHT - 55 ), btVector3( 35, 4, 30 ), btVector3( 55, 4, 45 )};
  btVector3 posTeam2[] = {btVector3( simulator::FIELD_WIDTH - 15, 4, 55 ), btVector3( simulator::FIELD_WIDTH - 25, 4, simulator::FIELD_HEIGHT - simulator::FIELD_HEIGHT / 2.5 + 20 ), btVector3( simulator::FIELD_WIDTH - 55, 4, 85 )};

  /*
     btVector3 axis = rotation.normalize();
      btQuaternion quat(axis,rad);
      t.setRotation(quat);
   */
  for(int i = 0; i < genRobots.size() / 2; i++) {
    btTransform t;
    genRobots[i]->getRigidBody()->getMotionState()->getWorldTransform( t );

    t.setIdentity();
    t.setOrigin( StartPositionsHelper::positions[i] );

    btMotionState* motion = new btDefaultMotionState( t );

    genRobots[i]->getRigidBody()->setMotionState( motion );
    genRobots[i]->getRigidBody()->setLinearVelocity( btVector3( 0, 0, 0 ));
    genRobots[i]->getRigidBody()->setAngularVelocity( btVector3( 0, 0, 0 ));
  }

  for(int i = genRobots.size() / 2; i < genRobots.size(); i++) {
    btTransform t;
    genRobots[i]->getRigidBody()->getMotionState()->getWorldTransform( t );

    t.setIdentity();
    t.setOrigin( StartPositionsHelper::positions[i] );

    btMotionState* motion = new btDefaultMotionState( t );

    genRobots[i]->getRigidBody()->setMotionState( motion );
    genRobots[i]->getRigidBody()->setLinearVelocity( btVector3( 0, 0, 0 ));
    genRobots[i]->getRigidBody()->setAngularVelocity( btVector3( 0, 0, 0 ));
  }
}

void Physics::stepSimulation( float timeW, float subStep, float timeStep ){
  setupBodiesProp();
  world->stepSimulation( timeW, subStep, timeStep );
}

void Physics::setupBodiesProp(){
  for(int i = 0; i < genRobots.size(); i++) {
    bodies.at( i )->hitRobot = false;
    bodies.at( i )->hit = false;
  }
}

vector<BulletObject*> Physics::getAllBtRobots(){
  vector<BulletObject*> listRobots;
  string prefix = "robot";
  for(int i = 0; i < bodies.size(); i++) {
    string name = bodies.at( i )->name;
    if(!name.compare( 0, prefix.size(), prefix )) {
      listRobots.push_back( bodies.at( i ));
    }
  }

  return listRobots;
}

bool Physics::callBackHitFunc( btManifoldPoint& cp, const btCollisionObjectWrapper* obj1, int id1, int index1, const btCollisionObjectWrapper* obj2, int id2, int index2 ){
  string prefix = "robot";

  const btCollisionObjectWrapper* wrappers[] = {obj1, obj2};

  vector<BulletObject*> vecObj;

  int contAgent = 0;
  for(int i = 0; i < 2; i++) {
    BulletObject* btObj = (BulletObject*)wrappers[i]->getCollisionObject()->getUserPointer();

    vecObj.push_back( btObj );

    string name = btObj->name;
    if (!name.compare( 0, prefix.size(), prefix ) || name == "ball")
      btObj->hit = true;

    if(!name.compare( 0, prefix.size(), prefix )) {
      contAgent++;
    }
  }

  if(contAgent == 2) {
    vecObj.at( 0 )->hitRobot = true;
    vecObj.at( 1 )->hitRobot = true;
  }

  return false;
}

btVector3 Physics::getBallPosition(){
  btVector3 ballPos;
  for(int i = 0; i < bodies.size(); i++) {
    if(bodies[i]->name.compare( "ball" ) == 0) {
      btTransform t;
      bodies[i]->body->getMotionState()->getWorldTransform( t );
      ballPos = t.getOrigin();
      break;
    }
  }
  return ballPos;
}

btVector3 Physics::getBallVelocity(){
  btVector3 ballVel;
  for(int i = 0; i < bodies.size(); i++) {
    if(bodies[i]->name.compare( "ball" ) == 0) {
      //btTransform t;
      //bodies[i]->body->getMotionState()->getWorldTransform(t);
      ballVel = bodies[i]->body->getLinearVelocity();
      break;
    }
  }
  //cout << ballVel.getX() << ", " << ballVel.getY() << ", " << ballVel.getZ() << endl;
  return ballVel;
}

void Physics::setBallPosition( btVector3 newPos ){
  for(int i = 0; i < bodies.size(); i++) {
    if(bodies[i]->name.compare( "ball" ) == 0) {
      btTransform t;
      bodies[i]->body->getMotionState()->getWorldTransform( t );

      t.setIdentity();
      t.setOrigin( newPos );

      btMotionState* motion = new btDefaultMotionState( t );

      bodies[i]->body->setMotionState( motion );
      bodies[i]->body->setLinearVelocity( btVector3( 0, 0, 0 ));
      bodies[i]->body->setAngularVelocity( btVector3( 0, 0, 0 ));

      break;
    }
  }
}

void Physics::setBallVelocity( btVector3 newVel ){
  for(int i = 0; i < bodies.size(); i++) {
    if(bodies[i]->name.compare( "ball" ) == 0) {
      btTransform t;

      bodies[i]->body->applyLinearVelocity( newVel );

      break;
    }
  }
}

void Physics::setRobotsPosition( vector<btVector3> newPositions, vector<btVector3> newOrientations){
    for(int i = 0; i < newPositions.size(); i++) {
        btTransform t;
        genRobots.at(i)->getRigidBody()->getMotionState()->getWorldTransform( t );

        t.setIdentity();
        t.setOrigin( newPositions.at(i) );
        if(newOrientations[i].length() != 0) {
            newOrientations[i] *= simulator::PI / 180;
            float rad = newOrientations[i].length();
            btVector3 axis = newOrientations[i].normalize();
            btQuaternion quat( axis, rad );
            t.setRotation( quat );
        }

        btMotionState* motion = new btDefaultMotionState( t );

        genRobots.at(i)->getRigidBody()->setMotionState( motion );
        genRobots.at(i)->getRigidBody()->setLinearVelocity( btVector3( 0, 0, 0 ));
        genRobots.at(i)->getRigidBody()->setAngularVelocity( btVector3( 0, 0, 0 ));
    }
}

void Physics::startDebug(){
  world->debugDrawWorld();
}

void Physics::setDebugWorld( int debugMode ){
  vector<int> debugDrawMode;
  //((GLDebugDrawer*)world-> getDebugDrawer())->setDrawScenarioMode(true);
  switch (debugMode) {
    case 0: {
      //debugDrawMode.push_back(btIDebugDraw::DBG_NoDebug);
      //world->getDebugDrawer()->setDebugMode(debugDrawMode);
    } break;
    case 1: {
      //debugDrawMode.push_back(btIDebugDraw::DBG_DrawLocalProperties);
      //debugDrawMode.push_back(btIDebugDraw::DBG_DrawWireframe);
      //world->getDebugDrawer()->setDebugMode(debugDrawMode);
      //((GLDebugDrawer*)world-> getDebugDrawer())->setDrawScenarioMode(false);
    } break;
    case 2: {
      //debugDrawMode.push_back(btIDebugDraw::DBG_DrawWireframe);
      //debugDrawMode.push_back(btIDebugDraw::DBG_DrawLocalProperties);
      //world-> getDebugDrawer()->setDebugMode(debugDrawMode);
    } break;
  }
}

btRigidBody* Physics::addFloor(){
  string name = "floor";
  btStaticPlaneShape* plane = new btStaticPlaneShape( btVector3( 0, 1, 0 ), 0 );
  btRigidBody* body = addGenericBody( plane, name, Color( 0.0, 0.0, 0.0 ), btVector3( 1.0, 0.0, 0.0 ), 0 );
  return body;
}

btRigidBody* Physics::addBall( float rad, btVector3 pos, float mass )
{
  string name = "ball";
  btSphereShape* ball = new btSphereShape( rad );
  btRigidBody* body = addGenericBody( ball, name, Color( 1.0, 0.0, 0.0 ), pos, mass );
  return body;
}

btRigidBody* Physics::addWall( Color clr, btVector3 pos, float width, float height, float depth, float mass ){
  string name = "wall";
  btBoxShape* wall = new btBoxShape( btVector3( width / 2.0, height / 2.0, depth / 2.0 ));
  btRigidBody* body = addGenericBody( wall, name, clr, pos, mass );
  return body;
}

btRigidBody* Physics::addCorner( Color clr, btVector3 pos, float width, float height, btVector3 rotation ){
  float mass = 0.f;
  float depth = 0.01f;
  btVector3 rotRad = rotation * simulator::PI / 180;
  string name = "corner";
  btBoxShape* corner = new btBoxShape( btVector3( width / 2.0, height / 2.0, depth / 2.0 ));
  btRigidBody* body = addGenericBody( corner, name, clr, pos, mass, rotRad );
  return body;
}

RobotPhysics* Physics::addRobot( Color clr, btVector3 pos, btVector3 rotation, float sizeRobot, float mass, Color colorPlayer, Color colorTeam, int id ){
  btBoxShape* modelShape = new btBoxShape( btVector3( sizeRobot / 2, sizeRobot / 2, sizeRobot / 2 ));
  btCompoundShape* compound = new btCompoundShape();

  btTransform localTrans;
  localTrans.setIdentity();
  localTrans.setOrigin( btVector3( 0.0, 4.0, 0 ));

  compound->addChildShape( localTrans, modelShape );

  btTransform transRobot;
  transRobot.setIdentity();
  transRobot.setOrigin( btVector3( pos.getX(), pos.getY(), pos.getZ()));
  if(rotation.length() != 0) {
    rotation *= simulator::PI / 180;
    float rad = rotation.length();
    btVector3 axis = rotation.normalize();
    btQuaternion quat( axis, rad );
    transRobot.setRotation( quat );
  }

  btVector3 localInertia( 0, 0, 0 );
  compound->calculateLocalInertia( mass, localInertia );

  btMotionState* robotMotState = new btDefaultMotionState( transRobot );
  btRigidBody::btRigidBodyConstructionInfo cInfo( mass, robotMotState, compound, localInertia );
  btRigidBody* bdRobot = new btRigidBody( cInfo );
  bdRobot->setCollisionFlags( bdRobot->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK );

  bdRobot->setLinearVelocity( btVector3( 0, 0, 0 ));
  bdRobot->setAngularVelocity( btVector3( 0, 0, 0 ));

  world->getBroadphase()->getOverlappingPairCache()->cleanProxyFromPairs(
          bdRobot->getBroadphaseHandle(),
          world->getDispatcher()
  );

  //bdRobot->setIdDebug(1);

  stringstream st;
  st << "robot-";
  st << id;
  string nameRobot = st.str();

  bodies.push_back( new BulletObject( bdRobot, nameRobot, clr ));
  bodies[bodies.size() - 1]->halfExt = modelShape->getHalfExtentsWithMargin();
  bdRobot->setUserPointer( bodies[bodies.size() - 1] );

  world->addRigidBody ( bdRobot );

  RobotPhysics* localRobot = new RobotPhysics( pos, 0.2, bdRobot, colorPlayer, colorTeam );
  localRobot->buildRobot( world );

  world->addVehicle( localRobot->getRaycast());

  genRobots.push_back( localRobot );
  return localRobot;
}

btRigidBody* Physics::addGenericBody( btCollisionShape* shape, string name, Color clr, btVector3 pos, float mass, btVector3 rotation ){

  btTransform t;
  t.setIdentity();
  t.setOrigin( btVector3( pos.getX(), pos.getY(), pos.getZ()));

  if(rotation.length() != 0) {
    float rad = rotation.length();
    btVector3 axis = rotation.normalize();
    btQuaternion quat( axis, rad );
    t.setRotation( quat );
  }

  btVector3 inertia( 0, 0, 0 );
  if(mass != 0.0)
    shape->calculateLocalInertia( mass, inertia );

  btMotionState* motion = new btDefaultMotionState( t );
  btRigidBody::btRigidBodyConstructionInfo info( mass, motion, shape, inertia );
  btRigidBody* body = new btRigidBody( info );

  bodies.push_back( new BulletObject( body, name, clr ));
  body->setUserPointer( bodies[bodies.size() - 1] );
  world->addRigidBody( body );
  return body;
}

void Physics::setRobotsPose(vector<btVector3> newPositions, vector<btScalar> newOrientations) {
  for(int i = 0; i < genRobots.size(); i++) {
    btTransform t;
    genRobots[i]->getRigidBody()->getMotionState()->getWorldTransform( t );
    t.setIdentity();

    t.setOrigin( newPositions[i] );

    auto rotation = btQuaternion(btVector3(0, 1, 0), newOrientations[i]);
    t.setRotation(rotation);

    btMotionState* motion = new btDefaultMotionState( t );

    genRobots[i]->getRigidBody()->setMotionState( motion );
    genRobots[i]->getRigidBody()->setLinearVelocity( btVector3( 0, 0, 0 ));
    genRobots[i]->getRigidBody()->setAngularVelocity( btVector3( 0, 0, 0 ));
  }
}