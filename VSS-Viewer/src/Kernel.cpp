#include "Kernel.h"

Kernel::Kernel( int argc, char **argv, vss::ExecutionConfig executionConfig ){
	this->argc = argc;
	this->argv = argv;
	this->executionConfig = executionConfig;

	ball = vss::Pose( 0, 0, 0 );

	instanceRobots();
	instanceDebug();
	initialMessage();
}

void Kernel::instanceDebug(){
	for(int i = 0; i < 3; i++) {
		auto path = vss::Path();
		path.points.push_back( Core::originInGlut());

		teamOneStepPoses.push_back( Core::originInGlut());
		teamOneFinalPoses.push_back( Core::originInGlut());
		teamOnePaths.push_back( path );

		teamTwoStepPoses.push_back( Core::originInGlut());
		teamTwoFinalPoses.push_back( Core::originInGlut());
		teamTwoPaths.push_back( path );
	}
}

void Kernel::instanceRobots(){
	for(int i = 0; i < 6; i++) {
		robots.push_back( new Robot3d());
		if(i > 2)
			robots.at( i ).teamColor = ColorName::Blue;
	}

	robots.at( 0 ).setPose( vss::Pose( 0, 70, 0 ));
	robots.at( 0 ).robotColor = ColorName::Red;

	robots.at( 1 ).setPose( vss::Pose( -10, 10, 0 ));
	robots.at( 1 ).robotColor = ColorName::Green;

	robots.at( 2 ).setPose( vss::Pose( 30, 10, 0 ));
	robots.at( 2 ).robotColor = ColorName::Purple;

	robots.at( 3 ).setPose( vss::Pose( 0, -70, 0 ));
	robots.at( 3 ).robotColor = ColorName::Red;

	robots.at( 4 ).setPose( vss::Pose( 10, -10, 0 ));
	robots.at( 4 ).robotColor = ColorName::Green;

	robots.at( 5 ).setPose( vss::Pose( -30, -10, 0 ));
	robots.at( 5 ).robotColor = ColorName::Purple;
}

void Kernel::init(){
	worldThread = new std::thread( std::bind( &Kernel::worldThreadWrapper, this ));
	receiveStateThread = new std::thread( std::bind( &Kernel::receiveStateThreadWrapper, this ));
	receiveDebugTeam1Thread = new std::thread( std::bind( &Kernel::receiveDebugTeam1ThreadWrapper, this ));
	receiveDebugTeam2Thread = new std::thread( std::bind( &Kernel::receiveDebugTeam2ThreadWrapper, this ));

	worldThread->join();
	receiveStateThread->join();
	receiveDebugTeam1Thread->join();
	receiveDebugTeam2Thread->join();
}

void Kernel::worldThreadWrapper(){
	auto fieldDrawer = new FieldDrawerVerySmallSize();
	auto robotDrawer = new SimpleRobotDrawer();
	auto ballDrawer = new SimpleBallDrawer();
	auto debugDrawer = new OriginalDebugDrawer();
	auto camera = new TopCamera();

	auto world = new World(debugDrawer, fieldDrawer, robotDrawer, ballDrawer, camera, &ball, &robots,
			&teamOnePaths, &teamOneStepPoses, &teamOneFinalPoses, &teamTwoPaths, &teamTwoStepPoses,
						   &teamTwoFinalPoses, &mutexDebugTeamYellow, &mutexDebugTeamBlue, &executionConfig );
	world->start( argc, argv );
}

void Kernel::receiveStateThreadWrapper(){
	auto stateReceiver = new StateReceiverAdapter( &ball, &robots, &executionConfig );
	stateReceiver->loop();
}

void Kernel::receiveDebugTeam1ThreadWrapper(){
	auto debugReceiver = new DebugReceiverAdapter( &teamOnePaths, &teamOneStepPoses, &teamOneFinalPoses, &mutexDebugTeamYellow, &executionConfig );
	debugReceiver->loop( vss::TeamType::Yellow );
}

void Kernel::receiveDebugTeam2ThreadWrapper(){
	auto debugReceiver = new DebugReceiverAdapter( &teamTwoPaths, &teamTwoStepPoses, &teamTwoFinalPoses, &mutexDebugTeamBlue, &executionConfig );
	debugReceiver->loop( vss::TeamType::Blue );
}

void Kernel::initialMessage(){
	std::cout << "VSS-Viewer" << std::endl;
	std::cout << "[Info]: Waiting VSS-Simulator..." << std::endl;
	std::cout << "[Info]: Waiting debug messages..." << std::endl;
	std::cout << "[Info]: Simulation is paused by default and camera exchange is disabled. Press <space> to start simulation and enable camera exchange." << std::endl;
	std::cout << "[Info]: To exchange between cameras press <c>." << std::endl;
}
