//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/EnvironmentType.h>

TEST(EnvironmentType_toDescription, WhenGetDescriptionOfSimulation_ShouldReturnStringSimulation){
    auto string = vss::toDescription(vss::EnvironmentType::Simulation);
    EXPECT_EQ(string, "Simulation");
}

TEST(EnvironmentType_toDescription, WhenGetDescriptionOfReal_ShouldReturnStringReal){
    auto string = vss::toDescription(vss::EnvironmentType::Real);
    EXPECT_EQ(string, "Real");
}

TEST(EnvironmentType_toEnvironmentType, WhenSendSimulationString_ShouldGetSimulation){
    auto environmentType = vss::toEnvironmentType("Simulation");
    EXPECT_EQ(environmentType, vss::EnvironmentType::Simulation);
}

TEST(EnvironmentType_toEnvironmentType, WhenSendRealString_ShouldGetReal){
    auto environmentType = vss::toEnvironmentType("Real");
    EXPECT_EQ(environmentType, vss::EnvironmentType::Real);
}

TEST(EnvironmentType_toEnvironmentType, WhenSendInvalidString_ShouldGetSimulation){
    auto environmentType = vss::toEnvironmentType("Invalid");
    EXPECT_EQ(environmentType, vss::EnvironmentType::Simulation);
}