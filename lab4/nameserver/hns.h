#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
 
class HNS : public NameServerInterface {
public:
    HNS(size_t size);
    size_t hashFunction(const HostName& host) const;
    IPAddress lookup(const HostName& host) const override;
    void insert(const HostName& host, const IPAddress& address) override;
    bool remove(const HostName& host) override;
private:
    size_t table_size;
    std::vector<std::vector<std::pair<HostName, IPAddress>>> hash_name_server;
};

#endif