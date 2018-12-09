//
// Created by john on 01/09/18.
//

#ifndef VSS_SIMULATOR_STATESENDERADAPTER_H
#define VSS_SIMULATOR_STATESENDERADAPTER_H

#include <Interfaces/IStateSenderAdapter.h>
#include <Physics.h>
#include <Domain/ExecutionConfig.h>
#include <Interfaces/IStateSender.h>

class StateSenderAdapter : public IStateSenderAdapter {
public:
    StateSenderAdapter(vss::ExecutionConfig*, Physics*);

    void send() override;

    Physics *physics;
    vss::IStateSender *stateSender;
    vss::ExecutionConfig *executionConfig;

protected:
    btVector3 getRobotPosition( RobotPhysics* robot );
    btVector3 getRobotOrientation( RobotPhysics* robot );
    btVector3 getRobotVelocity( RobotPhysics* robot );

    bool hasACustomAddress();
};

#endif //VSS_SIMULATOR_STATESENDERADAPTER_H
