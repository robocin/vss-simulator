//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Helpers/DomainRandomizer.h>
#include "Domain/Path.h"

TEST(Path_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Path path;

    EXPECT_EQ(path.points.size(), (unsigned int)0);
}

TEST(Path_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    int size = rand()%10;
    std::vector<vss::Point> points;

    for(int i = 0 ; i < size ; i++){
        points.push_back(vss::DomainRandomizer::createRandomPoint());
    }

    vss::Path path(points);

    EXPECT_EQ(path.points.size(), (unsigned int)size);

    for(unsigned int i = 0 ; i < path.points.size() ; i++){
        EXPECT_EQ(path.points[i].x, points[i].x);
        EXPECT_EQ(path.points[i].y, points[i].y);
    }
}

TEST(Path_cout, WhenCoutShouldPrintRight){
    auto path = vss::DomainRandomizer::createRandomPath();

    testing::internal::CaptureStdout();
    std::cout << path;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;

    mock_output << "Path {" << std::endl;
    for (auto point : path.points) {
        mock_output << "\t" << point << std::endl;
    }
    mock_output << "}";

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}