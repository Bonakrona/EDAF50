#ifndef UMNS_H
#define UMNS_H

#include "nameserverinterface.h"

#include <string>
#include <vector>
#include <unordered_map>

class UMNS : public NameServerInterface{
public:
    UMNS()= default;
    IPAddress lookup(const HostName& host) const override;
    void insert(const HostName& host, const IPAddress& address) override;
    bool remove(const HostName& host) override;
private:
    std::unordered_map<HostName, IPAddress> map_name_server;
};

#endif