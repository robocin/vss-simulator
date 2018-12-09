//
// Created by johnathan on 07/07/18.
//

#ifndef VSS_SIMULATOR_CONTROLRECEIVERADAPTER_H
#define VSS_SIMULATOR_CONTROLRECEIVERADAPTER_H

#include <Interfaces/IControlReceiver.h>
#include <Domain/ExecutionConfig.h>
#include <Physics.h>
#include <StartPositionsHelper.h>
#include "Interfaces/IControlReceiverAdapter.h"

class ControlReceiverAdapter : public IControlReceiverAdapter {
public:
    ControlReceiverAdapter(vss::ExecutionConfig*, Physics*, bool*);

    void loop() override;

    vss::IControlReceiver *controlReceiver;
    vss::ExecutionConfig *executionConfig;
    Physics* physics;
    bool *paused;

protected:
    bool hasACustomAddress();
};

#endif //VSS_SIMULATOR_CONTROLRECEIVERADAPTER_H
