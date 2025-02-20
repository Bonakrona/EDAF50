#include "vns.h"

#include <string>
#include <vector>
#include <algorithm>

IPAddress VNS::lookup(const HostName& host) const {

    //get an iterator to the element we are looking for
    auto it = std::find_if(vector_name_server.begin(), vector_name_server.end(), [&host](const std::pair<std::string, unsigned int>& check) {return check.first == host;});
    // check.first is looking at the first element of the pair that we give to the lambda which we want to know if it is our host

    if (it != vector_name_server.end()) {
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}

void VNS::insert(const HostName& host, const IPAddress& address) {
    auto result = lookup(host);
    
    // if it doesn't exst yet, we add the host and address
    if (result == NON_EXISTING_ADDRESS){
        vector_name_server.emplace_back(host, address);
    }
}

bool VNS::remove(const std::string& host){
    auto result = lookup(host);
    
    if (result != NON_EXISTING_ADDRESS){
        auto it = std::find_if(vector_name_server.begin(), vector_name_server.end(), [&host](const std::pair<std::string, unsigned int>& check) {return check.first == host;});
        vector_name_server.erase(it);
        return true;
    } else {
        return false;
    }
}