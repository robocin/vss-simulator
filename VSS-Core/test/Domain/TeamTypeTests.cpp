//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/TeamType.h>

TEST(TeamType_toDescription, WhenGetDescriptionOfYellow_ShouldReturnStringYellow){
    auto string = vss::toDescription(vss::TeamType::Yellow);
    EXPECT_EQ(string, "Yellow");
}

TEST(TeamType_toDescription, WhenGetDescriptionOfBlue_ShouldReturnStringBlue){
    auto string = vss::toDescription(vss::TeamType::Blue);
    EXPECT_EQ(string, "Blue");
}

TEST(TeamType_toTeamType, WhenSendYellowString_ShouldGetYellow){
    auto teamType = vss::toTeamType("Yellow");
    EXPECT_EQ(teamType, vss::TeamType::Yellow);
}

TEST(TeamType_toTeamType, WhenSendBlueString_ShouldGetBlue){
    auto teamType = vss::toTeamType("Blue");
    EXPECT_EQ(teamType, vss::TeamType::Blue);
}

TEST(TeamType_toTeamType, WhenSendInvalidString_ShouldGetYellow){
    auto teamType = vss::toTeamType("Invalid");
    EXPECT_EQ(teamType, vss::TeamType::Yellow);
}