#!/usr/bin/env bash

INSTALL_MINT_18_2 () {
    apt-get -y install pkg-config
    apt-get -y install g++ cmake libzmqpp3 libzmqpp-dev protobuf-compiler libprotobuf-dev libboost-all-dev
    INSTALLED=1
}