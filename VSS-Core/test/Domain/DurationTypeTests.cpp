//
// Created by johnathan on 06/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include "Domain/DurationType.h"

TEST(DurationType_toDescription, WhenGetDescriptionOfTenMinutes_ShouldReturnStringTenMinutes){
    auto string = vss::toDescription(vss::DurationType::TenMinutes);
    EXPECT_EQ(string, "TenMinutes");
}

TEST(DurationType_toDescription, WhenGetDescriptionOfUnlimitedMinutes_ShouldReturnStringUnlimitedMinutes){
    auto string = vss::toDescription(vss::DurationType::UnlimitedMinutes);
    EXPECT_EQ(string, "UnlimitedMinutes");
}

TEST(DurationType_toDurationType, WhenSendTenMinutesString_ShouldGetTenMinutes){
    auto durationType = vss::toDurationType("TenMinutes");
    EXPECT_EQ(durationType, vss::DurationType::TenMinutes);
}

TEST(DurationType_toDurationType, WhenSendUnlimitedMinutesString_ShouldGetUnlimitedMinutes){
    auto durationType = vss::toDurationType("UnlimitedMinutes");
    EXPECT_EQ(durationType, vss::DurationType::UnlimitedMinutes);
}

TEST(DurationType_toDurationType, WhenSendInvalidString_ShouldGetTenMinutes){
    auto durationType = vss::toDurationType("Invalid");
    EXPECT_EQ(durationType, vss::DurationType::TenMinutes);
}