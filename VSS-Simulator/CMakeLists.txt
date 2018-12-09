PROJECT(vss-simulator)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
FIND_PACKAGE(PkgConfig)
FIND_PACKAGE(Boost 1.40 COMPONENTS program_options REQUIRED)
INCLUDE(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)

find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
        )

find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
        )

include_directories(${PROTOBUF_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
include_directories(src src/strategies src/Communications src/Helpers)
include_directories(include include/Interfaces include/Domain include/Communications include/Helpers)
include_directories(bullet bullet/LinearMath)

file(GLOB_RECURSE SRCS_CPP src/*.cpp)
file(GLOB_RECURSE INCLUDE_H include/*.h)
file(GLOB_RECURSE BULLET_CPP bullet/*.cpp)
file(GLOB_RECURSE BULLET_H bullet/*.h)

set (VSS_CORE libvss-core.so)
link_directories(usr/lib)
include_directories(usr/local/include)

ADD_LIBRARY(vss-simulator-core ${SRCS_CPP} ${INCLUDE_H} ${UTILS_CPP} ${UTILS_H} ${BULLET_CPP} ${BULLET_H})
TARGET_LINK_LIBRARIES(vss-simulator-core ${VSS_CORE} ${PROTOBUF_LIBRARY} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
TARGET_LINK_LIBRARIES(vss-simulator-core LINK_PUBLIC ${Boost_LIBRARIES})
target_include_directories(vss-simulator-core PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(vss-simulator-core PUBLIC ${ZeroMQ_LIBRARY})

ADD_EXECUTABLE(vss-simulator src/Main.cpp)
TARGET_LINK_LIBRARIES(vss-simulator vss-simulator-core)

IF(RELEASE)
    SET(CMAKE_CXX_FLAGS "-o2 -ffast-math -lm -lc -std=c++11 -pthread -DNDEBUG")

    INCLUDE(CPack)

    INSTALL(TARGETS vss-simulator DESTINATION bin)

    SET(CPACK_GENERATOR "DEB")
    SET(CPACK_DEBIAN_PACKAGE_NAME "vss-simulator")
    SET(CPACK_DEBIAN_PACKAGE_DESCRIPTION "A Simulator for the competition of Robot Soccer IEEE Very Small Size")
    SET(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://sirlab.github.io/VSS-SDK/")
    SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "all")
    SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Johnathan Fercher")
    SET(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
ELSE()
    INCLUDE_DIRECTORIES(third-party)

    enable_testing()

    add_subdirectory(third-party/googletest)

    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

    file(GLOB_RECURSE TEST test/*.cpp)

    ADD_EXECUTABLE(tests ${TEST})

    target_link_libraries(tests
            pthread
            gtest
            gtest_main
            vss-simulator-core)

    SET(CMAKE_CXX_FLAGS "-g -ffast-math -lm -lc -std=c++11 -pthread")
ENDIF()