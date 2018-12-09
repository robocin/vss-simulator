PROJECT(vss-viewer)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11 -o2")

find_package(PkgConfig)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
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

include_directories(${PROTOBUF_INCLUDE_DIR} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})
include_directories(src src/Interfaces src/Cameras src/Communications src/Domain src/Drawers src/Framework src/Core)
include_directories(include include/Interfaces include/Cameras include/Communications include/Domain include/Drawers include/Framework include/Core)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE H include/*.h)

set (VSS_CORE libvss-core.so)
link_directories(usr/lib)
include_directories(usr/local/include)

ADD_LIBRARY(vss-viewer-core ${SRC} ${H})

TARGET_LINK_LIBRARIES(vss-viewer-core ${VSS_CORE} ${PROTOBUF_LIBRARY} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_include_directories(vss-viewer-core PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(vss-viewer-core PUBLIC ${ZeroMQ_LIBRARY})
TARGET_LINK_LIBRARIES(vss-viewer-core LINK_PUBLIC ${Boost_LIBRARIES})
target_link_libraries(vss-viewer-core ${PROTOBUF_LIBRARIES})

ADD_EXECUTABLE(vss-viewer src/Main.cpp)
TARGET_LINK_LIBRARIES(vss-viewer vss-viewer-core)

IF(RELEASE)
    SET(CMAKE_CXX_FLAGS "-Wall -Werror -o2 -std=c++11 -pthread")

    INCLUDE(CPack)

    INSTALL(TARGETS vss-viewer DESTINATION bin)

    SET(CPACK_GENERATOR "DEB")
    SET(CPACK_DEBIAN_PACKAGE_NAME "vss-viewer")
    SET(CPACK_DEBIAN_PACKAGE_DESCRIPTION "A 3D Software of visualization of states given by VSS-Simulator and VSS-Vision")
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
            vss-viewer-core)

    SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11 -pthread")
ENDIF()