//
// Created by johnathan on 23/06/18.
//

#ifndef VSS_CORE_ADDRESS_H
#define VSS_CORE_ADDRESS_H

#include <string>
#include <sstream>

namespace vss {

    class Address {
    public:
        Address();
        Address(std::string ip, int port);

        friend std::ostream& operator<<(std::ostream& os, const Address& address);

        void setIp(std::string ip);
        void setPort(int port);

        std::string getIp();
        int getPort();

        std::string getFullAddress();

        std::string ip;
        int port;
    };

}

#endif //VSS_CORE_ADDRESS_H
