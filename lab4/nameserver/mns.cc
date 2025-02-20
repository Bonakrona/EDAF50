#include "mns.h"

#include <vector>
#include <string>
#include <algorithm>
#include <map>

IPAddress MNS::lookup(const HostName& host) const{
    auto it = map_name_server.find(host);

    if(it != map_name_server.end()){
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}

void MNS::insert(const HostName& host, const IPAddress& address) {
    auto result = lookup(host);

    if(result == NON_EXISTING_ADDRESS){
        map_name_server[host] = address;
    }
}

bool MNS::remove(const HostName& host) {
    auto result = lookup(host);

    if(result != NON_EXISTING_ADDRESS){
        map_name_server.erase(host);
        return true;
    } else {
        return false;
    }
}


