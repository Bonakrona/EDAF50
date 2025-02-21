#include <vector>
#include <string>
#include <algorithm>

#include "mns.h"

using namespace std;
using std::string;
using std::vector;

void mns::insert(const HostName& name, const IPAddress& address) {
    pairs.insert(make_pair(name, address));
}

bool mns::remove(const HostName& name) {
    auto it = find_if(pairs.begin(), pairs.end(), [&name](const pair<HostName, IPAddress>& p) {
        return p.first == name;
    });
    if (it != pairs.end()) {
        pairs.erase(it);
        return true;
    }
    return false;
}

IPAddress mns::lookup(const HostName& name) const {
    auto it = find_if(pairs.begin(), pairs.end(), [&name](const pair<HostName, IPAddress>& p) {
        return p.first == name;
    });
    if (it != pairs.end()) {
        return it->second;
    }
    return NON_EXISTING_ADDRESS;
}