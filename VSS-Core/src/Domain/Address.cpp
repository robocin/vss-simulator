//
// Created by johnathan on 23/06/18.
//

#include <Domain/Address.h>

namespace vss {

    Address::Address() {
        ip = "";
        port = 0;
    }

    Address::Address(std::string ip, int port) {
        this->ip = ip;
        this->port = port;
    }

    void Address::setIp(std::string ip) {
        this->ip = ip;
    }

    void Address::setPort(int port) {
        this->port = port;
    }

    std::string Address::getIp() {
        return ip;
    }

    int Address::getPort() {
        return port;
    }

    std::string Address::getFullAddress() {
        std::stringstream ss;
        ss << ip << ":" << port;
        return ss.str();
    }

    std::ostream &operator<<(std::ostream &os, const Address &address) {
        return os << address.ip << ":" << address.port;
    }

}