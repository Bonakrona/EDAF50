#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"
#include <vector>
#include <string>

using namespace std;
using std::string;
using std::vector;

class vns : public NameServerInterface
{
public:
void insert(const HostName& name, const IPAddress& address) override;
bool remove(const HostName& name) override;
IPAddress lookup(const HostName& name) const override;

private:
    vector<std::pair<HostName, IPAddress>> pairs;
};

#endif