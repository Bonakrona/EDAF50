#ifndef UMNS_H
#define UMNS_H

#include "nameserverinterface.h"
#include <unordered_map>

using namespace std;
using std::unordered_map;

class umns : public NameServerInterface
{
public:
    void insert(const HostName &name, const IPAddress &address) override;
    bool remove(const HostName &name) override;
    IPAddress lookup(const HostName &name) const override;

private:
    unordered_map<HostName, IPAddress> pairs;
};

#endif