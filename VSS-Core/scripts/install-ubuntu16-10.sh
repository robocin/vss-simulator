#!/usr/bin/env bash

INSTALL_UBUNTU_16_10 () {
    apt-get -y install pkgconf
    apt-get -y install g++ cmake libzmq5 libzmq3-dev protobuf-compiler libprotobuf-dev libboost-all-dev
    INSTALLED=1
}