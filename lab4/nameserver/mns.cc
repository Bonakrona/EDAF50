#include "mns.h"

void mns::insert(const HostName &name, const IPAddress &address)
{
    pairs[name] = address;
}

bool mns::remove(const HostName &name)
{
    return pairs.erase(name) > 0;
}

IPAddress mns::lookup(const HostName& name) const {
    auto it = pairs.find(name);
    if (it != pairs.end()) {
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}
