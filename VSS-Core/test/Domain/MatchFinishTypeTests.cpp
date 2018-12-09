//
// Created by johnathan on 06/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/MatchFinishType.h>

TEST(MatchFinishType_toDescription, WhenGetDescriptionOfTenGoalsDifference_ShouldReturnStringTenGoalsDifference){
    auto string = vss::toDescription(vss::MatchFinishType::TenGoalsDifference);
    EXPECT_EQ(string, "TenGoalsDifference");
}

TEST(MatchFinishType_toDescription, WhenGetDescriptionOfTimeUp_ShouldReturnStringTimeUp){
    auto string = vss::toDescription(vss::MatchFinishType::TimeUp);
    EXPECT_EQ(string, "TimeUp");
}

TEST(MatchFinishType_toMatchFinishType, WhenSendTenGoalsDifferenceString_ShouldGetTenGoalsDifference){
    auto matchFinishType = vss::toMatchFinishType("TenGoalsDifference");
    EXPECT_EQ(matchFinishType, vss::MatchFinishType::TenGoalsDifference);
}

TEST(MatchFinishType_toMatchFinishType, WhenSendTimeUpString_ShouldGetTimeUp){
    auto matchFinishType = vss::toMatchFinishType("TimeUp");
    EXPECT_EQ(matchFinishType, vss::MatchFinishType::TimeUp);
}

TEST(MatchFinishType_toMatchFinishType, WhenSendInvalidString_ShouldGetTenGoalsDifference){
    auto matchFinishType = vss::toMatchFinishType("Invalid");
    EXPECT_EQ(matchFinishType, vss::MatchFinishType::TenGoalsDifference);
}