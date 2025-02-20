#ifndef MNS_H
#define MNS_H

#include "nameserverinterface.h"

#include <string>
#include <vector>
#include <map>

class MNS : public NameServerInterface {
public:
    MNS() = default;
    IPAddress lookup(const HostName& host) const override;
    void insert(const HostName& host, const IPAddress& address) override;
    bool remove(const HostName& host) override;
private:
    std::map<HostName, IPAddress> map_name_server;
};

#endif