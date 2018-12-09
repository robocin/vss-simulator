//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/SideAttackType.h>

TEST(SideAttackType_toDescription, WhenGetDescriptionOfLeft_ShouldReturnStringLeft){
    auto string = vss::toDescription(vss::SideAttackType::Left);
    EXPECT_EQ(string, "Left");
}

TEST(SideAttackType_toDescription, WhenGetDescriptionOfRight_ShouldReturnStringRight){
    auto string = vss::toDescription(vss::SideAttackType::Right);
    EXPECT_EQ(string, "Right");
}

TEST(SideAttackType_toSideAttackType, WhenSendLeftString_ShouldGetLeft){
    auto sideAttackType = vss::toSideAttackType("Left");
    EXPECT_EQ(sideAttackType, vss::SideAttackType::Left);
}

TEST(SideAttackType_toSideAttackType, WhenSendRightString_ShouldGetRight){
    auto sideAttackType = vss::toSideAttackType("Right");
    EXPECT_EQ(sideAttackType, vss::SideAttackType::Right);
}

TEST(SideAttackType_toSideAttackType, WhenSendInvalidString_ShouldGetLeft){
    auto sideAttackType = vss::toSideAttackType("Invalid");
    EXPECT_EQ(sideAttackType, vss::SideAttackType::Left);
}