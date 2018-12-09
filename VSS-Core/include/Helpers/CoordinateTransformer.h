#ifndef _COORDINATE_TRANSFORMER_H_
#define _COORDINATE_TRANSFORMER_H_

#include "Domain/State.h"
#include "Domain/Robot.h"
#include "Domain/Ball.h"

namespace vss {

    namespace CoordinateTransformer {

        Ball spin180Degrees(Ball ball);
        Robot spin180Degrees(Robot robot);
        State spinField180Degrees(State state);

    };

}

#endif