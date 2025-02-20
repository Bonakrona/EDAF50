#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"

#include <string>
#include <vector>
#include <algorithm>

class VNS : public NameServerInterface {
public:
    VNS() = default;
    IPAddress lookup(const HostName& host) const override;
    void insert(const HostName& host, const IPAddress& address) override;
    bool remove(const HostName& host) override;
    
private:
    std::vector<std::pair<HostName, IPAddress>> vector_name_server;
};

#endif