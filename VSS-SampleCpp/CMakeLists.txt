PROJECT(vss-sample)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11 -pthread")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
find_package(PkgConfig)
INCLUDE(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)


file(GLOB_RECURSE SRCS_CPP src/*.cpp)
file(GLOB_RECURSE SRCS_CC src/*.cc)
file(GLOB_RECURSE INCLUDE include/*.h)

set (VSS_CORE libvss-core.so)
link_directories(usr/lib)
include_directories(usr/local/include)

ADD_EXECUTABLE(vss-sample ${SRCS_CPP} ${SRCS_CC} ${INCLUDE})

target_include_directories(vss-sample PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(vss-sample PUBLIC ${ZeroMQ_LIBRARY})

TARGET_LINK_LIBRARIES(vss-sample ${VSS_CORE} ${PROTOBUF_LIBRARY})

INSTALL(TARGETS vss-sample DESTINATION bin)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_NAME "vss-sample")
SET(CPACK_DEBIAN_PACKAGE_DESCRIPTION "A simple way to send commands for robots on VSS-Simulator or real robots.")
SET(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://sirlab.github.io/VSS-SDK/")
SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "all")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Johnathan Fercher")
SET(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

INCLUDE(CPack)
