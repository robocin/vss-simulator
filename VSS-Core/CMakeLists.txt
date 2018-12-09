cmake_minimum_required(VERSION 2.8.9)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

project(vss-core)

include_directories(src)
include_directories(include)

INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})

find_package(PkgConfig)
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

include_directories(${Boost_INCLUDE_DIRS})

file(GLOB_RECURSE CPP "src/*.cpp")
file(GLOB_RECURSE CC "src/*.cc")
file(GLOB_RECURSE H "include/*.h")

set(CLION SOURCE ${CC} ${CPP} ${H})

add_library(vss-core SHARED ${CPP} ${CC} ${H})

target_link_libraries(vss-core ${Boost_PROGRAM_OPTIONS_LIBRARY})
target_include_directories(vss-core PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(vss-core PUBLIC ${ZeroMQ_LIBRARY})
target_link_libraries(vss-core ${PROTOBUF_LIBRARIES})

IF(RELEASE)
    set(CMAKE_BUILD_TYPE Release)
    SET(CMAKE_CXX_FLAGS "-Wall -Werror -o2 -std=c++11")

    install(TARGETS vss-core DESTINATION /usr/lib)
    install(DIRECTORY include/ DESTINATION include/ FILES_MATCHING PATTERN "*.h")
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
            vss-core
            ${PROTOBUF_LIBRARIES})

    SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")
ENDIF()


