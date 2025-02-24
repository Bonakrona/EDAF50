#include "vns.h"
#include <algorithm>

using namespace std;
using std::string;
using std::vector;

void vns::insert(const HostName& name, const IPAddress& address) {
    pairs.push_back(make_pair(name, address));
}

bool vns::remove(const HostName& name) {
    auto it = std::find_if(pairs.begin(), pairs.end(), [&name](const pair<HostName, IPAddress>& p) {
        return p.first == name;
    });
    if (it != pairs.end()) {
        pairs.erase(it);
        return true;
    }
    return false;
}

IPAddress vns::lookup(const HostName& name) const {
    auto it = std::find_if(pairs.begin(), pairs.end(), [&name](const pair<HostName, IPAddress>& p) {
        return p.first == name;
    });
    if (it != pairs.end()) {
        return it->second;
    }
    return NON_EXISTING_ADDRESS;
}