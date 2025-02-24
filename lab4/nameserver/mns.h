#ifndef MNS_H
#define MNS_H

#include "nameserverinterface.h"
#include <map>

using namespace std;
using std::map;
using std::string;

class mns : public NameServerInterface
{
public:
    void insert(const HostName &name, const IPAddress &address) override;
    bool remove(const HostName &name) override;
    IPAddress lookup(const HostName &name) const override;

private:
    map<HostName, IPAddress> pairs;
};

#endif