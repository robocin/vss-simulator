#!/usr/bin/env bash

CMAKE () {
    bash scripts/protos.sh
    rm -R build
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
}

CMAKE_INSTALL () {
    bash scripts/protos.sh
    rm -R build
    mkdir -p build
    cd build
    cmake -D RELEASE=ON ..
    make install
    cd ..
}

INSTALL_BASE() {
    apt-get update && apt-get upgrade
    apt-get -y install lsb-release git

    DISTRO=`lsb_release -si`
    RELEASE=`lsb_release -sr`
    RELEASE_DEBIAN=`lsb_release -sr | cut -c1-1`
    ARCHITECTURE=`uname -m`
}

INIT_SUBMODULES() {
    git submodule init;
    git submodule update;
}