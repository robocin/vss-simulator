//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_STDININTERPRETER_H
#define VSS_CORE_STDININTERPRETER_H

#include <boost/program_options.hpp>
#include <Interfaces/IStdinInterpreter.h>

namespace vss {

    class StdinInterpreter : public IStdinInterpreter {
    public:
        StdinInterpreter();

        ExecutionConfig extractExecutionConfig(int argc, char **argv) override;

    protected:
        ExecutionConfig stdinConfiguration;

        boost::program_options::options_description buildOptions();
        void buildConfiguration(boost::program_options::variables_map);
    };

};

#endif //VSS_CORE_STDININTERPRETER_H
