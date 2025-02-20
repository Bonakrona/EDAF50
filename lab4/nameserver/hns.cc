#include "hns.h"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>

HNS::HNS(size_t size){
    table_size = size;
    hash_name_server = std::vector<std::vector<std::pair<HostName, IPAddress>>>(size);
}

size_t HNS::hashFunction(const HostName& host) const {
    return std::hash<std::string>{}(host) % table_size;  // Ensures the index fits within the table
}

/*
size_t hash_function(const HostName& host) const {
    size_t hash = 0;
    for (char c : host) {
        hash = (hash * 31) + c;
    }
    return hash % table_size;
}
*/

IPAddress HNS::lookup(const HostName& host) const{
    size_t hash = hashFunction(host);

    auto it = std::find_if(hash_name_server[hash].begin(), hash_name_server[hash].end(), [&host](const std::pair<std::string, unsigned int>& check) {return check.first == host;});

    if (it != hash_name_server[hash].end()) {
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}

void HNS::insert(const HostName& host, const IPAddress& address) {
    auto result = lookup(host);
    if(result == NON_EXISTING_ADDRESS){
        size_t hash = hashFunction(host);
        hash_name_server[hash].push_back({host, address});
    }
}

bool HNS::remove(const HostName& host) {
    auto result = lookup(host);

    if(result != NON_EXISTING_ADDRESS){
        size_t hash = hashFunction(host);
        auto it = std::find_if(hash_name_server[hash].begin(), hash_name_server[hash].end(), [&host](const std::pair<std::string, unsigned int>& check) {return check.first == host;});
        hash_name_server[hash].erase(it);
        return true;
    } else {
        return false;
    }
}