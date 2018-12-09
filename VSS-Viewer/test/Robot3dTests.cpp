//
// Created by johnathan on 03/06/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/Robot3d.h>
#include "Domain/Pose.h"

TEST(Robot3d_Constructor, WhenDefaultBuilded_ShouldBeZero){
    Robot3d robot3d;

    EXPECT_EQ(robot3d.teamColor, ColorName::Yellow);
    EXPECT_EQ(robot3d.robotColor, ColorName::Green);
    EXPECT_EQ(robot3d.pose.x, 0);
    EXPECT_EQ(robot3d.pose.y, 0);
    EXPECT_EQ(robot3d.pose.angle, 0);
    EXPECT_EQ(robot3d.selected, false);
}
