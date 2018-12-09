//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/TimeExecutionType.h>

TEST(TimeExecutionType_toDescription, WhenGetDescriptionOfNormal_ShouldReturnStringNormal){
    auto string = vss::toDescription(vss::TimeExecutionType::Normal);
    EXPECT_EQ(string, "Normal");
}

TEST(TimeExecutionType_toDescription, WhenGetDescriptionOfFast_ShouldReturnStringFast){
    auto string = vss::toDescription(vss::TimeExecutionType::Fast);
    EXPECT_EQ(string, "Fast");
}

TEST(TimeExecutionType_toTimeExecutionType, WhenSendNormalString_ShouldGetNormal){
    auto timeExecutionType = vss::toTimeExecutionType("Normal");
    EXPECT_EQ(timeExecutionType, vss::TimeExecutionType::Normal);
}

TEST(TimeExecutionType_toTimeExecutionType, WhenSendFastString_ShouldGetFast){
    auto timeExecutionType = vss::toTimeExecutionType("Fast");
    EXPECT_EQ(timeExecutionType, vss::TimeExecutionType::Fast);
}

TEST(TimeExecutionType_toTimeExecutionType, WhenSendInvalidString_ShouldGetNormal){
    auto timeExecutionType = vss::toTimeExecutionType("Invalid");
    EXPECT_EQ(timeExecutionType, vss::TimeExecutionType::Normal);
}