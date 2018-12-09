//
// Created by johnathan on 03/07/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include <Domain/Address.h>
#include <Domain/Constants.h>
#include <Helpers/DomainRandomizer.h>

TEST(Address_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Address address;

    EXPECT_EQ(address.getPort(), 0);
    EXPECT_EQ(address.getIp(), "");
    EXPECT_EQ(address.getFullAddress(), ":0");
}

TEST(Address_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    vss::Address address("127.0.0.1", 5555);

    EXPECT_EQ(address.getPort(), 5555);
    EXPECT_EQ(address.getIp(), "127.0.0.1");
    EXPECT_EQ(address.getFullAddress(), "127.0.0.1:5555");
}

TEST(Address_cout, WhenCoutShouldPrintRight){
    auto address = vss::DomainRandomizer::createRandomAddress();

    testing::internal::CaptureStdout();
    std::cout << address;
    std::string output = testing::internal::GetCapturedStdout();
    std::stringstream mock_output;
    mock_output << address.getIp() << ":" << address.getPort();

    EXPECT_STREQ(mock_output.str().c_str(), output.c_str());
}