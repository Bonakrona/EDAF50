#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"
#include <vector>
#include <list>
#include <functional>

using namespace std;
using std::list;
using std::vector;

class hns : public NameServerInterface
{
public:
    hns(size_t tableSize);
    void insert(const HostName &name, const IPAddress &address) override;
    bool remove(const HostName &name) override;
    IPAddress lookup(const HostName &name) const override;

private:
    vector<list<std::pair<HostName, IPAddress>>> table;
    size_t size;
    std::hash<HostName> hashFunction;
};

#endif