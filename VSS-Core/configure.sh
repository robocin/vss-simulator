#!/bin/bash

DISTRO=``
RELEASE=``
RELEASE_DEBIAN=``
ARCHITECTURE=``
COMPILE_TYPE=$1

INSTALLED=0

source scripts/base.sh

source scripts/install-ubuntu14-04.sh
source scripts/install-ubuntu16-04.sh
source scripts/install-ubuntu16-10.sh
source scripts/install-ubuntu18-04.sh
source scripts/install-debian9.sh
source scripts/install-mint18-2.sh

INSTALL () {
    INSTALL_BASE;

    # Ubuntu
    if [[ "$DISTRO" == "Ubuntu" ]] && [[ "$RELEASE" == "16.04" ]]; then
        INSTALL_UBUNTU_16_04;
    fi

    if [[ "$DISTRO" == "Ubuntu" ]] && [[ "$RELEASE" == "16.10" ]]; then
        INSTALL_UBUNTU_16_10;
    fi

    if [[ "$DISTRO" == "Ubuntu" ]] && [[ "$RELEASE" == "14.04" ]]; then
        INSTALL_UBUNTU_14_04;
    fi

    if [[ "$DISTRO" == "Ubuntu" ]] && [[ "$RELEASE" == "18.04" ]]; then
        INSTALL_UBUNTU_18_04;
    fi

    # Debian
    if [[ "$DISTRO" == "Debian" ]] && [[ "$RELEASE_DEBIAN" == "9" ]]; then
        INSTALL_DEBIAN_9;
    fi

    # LinuxMint
    if [[ "$DISTRO" == "LinuxMint" ]] && [[ "$RELEASE" == "18.2" ]]; then
        INSTALL_MINT_18_2;
    fi

    if [[ $INSTALLED == 0 ]]; then
        echo "Sistema Operacional Incompatível";
    fi

    if [[ $INSTALLED == 1 ]]; then
        INIT_SUBMODULES;

        if [[ $COMPILE_TYPE == "development" ]];
        then
            CMAKE;
        else
            CMAKE_INSTALL;
        fi
    fi
}

INSTALL;
