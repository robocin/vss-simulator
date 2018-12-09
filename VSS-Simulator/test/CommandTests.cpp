//
// Created by johnathan on 02/06/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include "../include/Sir.h"

TEST(Command_Constructor, WhenDefaultBuilded_ShouldBeZero) {
    Command command;

    EXPECT_EQ(command.left, 0);
    EXPECT_EQ(command.right, 0);
}
