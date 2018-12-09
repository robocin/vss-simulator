//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/FieldTransformationType.h>

TEST(FieldTransformationType_toDescription, WhenGetDescriptionOfNone_ShouldReturnStringNone){
    auto string = vss::toDescription(vss::FieldTransformationType::None);
    EXPECT_EQ(string, "None");
}

TEST(EnvironmentType_toDescription, WhenGetDescriptionOfFlip180Degrees_ShouldReturnStringFlip180Degrees){
    auto string = vss::toDescription(vss::FieldTransformationType::Flip180Degrees);
    EXPECT_EQ(string, "Flip180Degrees");
}

TEST(EnvironmentType_toFieldTransformationType, WhenSendNoneString_ShouldGetNone){
    auto fieldTransformationType = vss::toFieldTransformationType("None");
    EXPECT_EQ(fieldTransformationType, vss::FieldTransformationType::None);
}

TEST(EnvironmentType_toFieldTransformationType, WhenSendFlip180DegreesString_ShouldGetFlip180Degrees){
    auto fieldTransformationType = vss::toFieldTransformationType("Flip180Degrees");
    EXPECT_EQ(fieldTransformationType, vss::FieldTransformationType::Flip180Degrees);
}

TEST(EnvironmentType_toFieldTransformationType, WhenSendInvalidString_ShouldGetNone){
    auto fieldTransformationType = vss::toFieldTransformationType("Invalid");
    EXPECT_EQ(fieldTransformationType, vss::FieldTransformationType::None);
}