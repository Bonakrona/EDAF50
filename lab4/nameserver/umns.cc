#include "umns.h"

#include <string>
#include <vector>
#include <unordered_map>

IPAddress UMNS::lookup(const std::string& host) const{
    auto it = map_name_server.find(host);

    if(it != map_name_server.end()){
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}

void UMNS::insert(const HostName& host, const IPAddress& address) {
    auto result = lookup(host);

    if(result == NON_EXISTING_ADDRESS){
        map_name_server[host] = address;
    }
}

bool UMNS::remove(const HostName& host) {
    auto result = lookup(host);

    if(result != NON_EXISTING_ADDRESS){
        map_name_server.erase(host);
        return true;
    } else {
        return false;
    }
}