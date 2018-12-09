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

#include "../include/strategies/Strategy.h"
#include "Builders/StdinInterpreterBuilder.h"
#include "../include/Simulator.h"

vss::ExecutionConfig loadExecutionConfig(int argc, char** argv){
    auto stdinInterpreterBuilder = new vss::StdinInterpreterBuilder();

    stdinInterpreterBuilder
            ->onStatePort()
            ->onCtrlRecvAddr()
            ->onCtrlPort()
            ->onYellowCmdPort()
            ->onBlueCmdPort()
            ->onTimeExecutionType()
            ->onMatchFinishType()
            ->onTeamInitialPositionPath();

    auto stdinInterpreter = stdinInterpreterBuilder->buildInterpreter();

    return stdinInterpreter->extractExecutionConfig(argc, argv);
}

int main( int argc, char **argv ){
    auto executionConfiguration = loadExecutionConfig(argc, argv);

    if(!executionConfiguration.isValidConfiguration)
        return 0;

    Simulator* simulator = new Simulator();
    simulator->runSimulator( argc, argv, executionConfiguration );

    return 0;
}