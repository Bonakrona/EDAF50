#include "umns.h"

void umns::insert(const HostName& name, const IPAddress& address) {
    pairs[name] = address;
}

bool umns::remove(const HostName& name) {
    return pairs.erase(name) > 0;
}

IPAddress umns::lookup(const HostName& name) const {
    auto it = pairs.find(name);
    if (it != pairs.end()) {
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}