#include "hns.h"
#include <algorithm>

using namespace std;
using std::string;
using std::vector;

hns::hns(size_t tableSize) : table(tableSize), size(tableSize) {}

void hns::insert(const HostName &name, const IPAddress &address)
{
    size_t index = hashFunction(name) % size;
    table[index].emplace_back(name, address);
}

bool hns::remove(const HostName &name)
{
    size_t index = hashFunction(name) % size;
    auto &bucket = table[index];

    auto it = std::find_if(bucket.begin(), bucket.end(), [&](const std::pair<HostName, IPAddress> &pair)
                           { return pair.first == name; });

    if (it != bucket.end())
    {
        bucket.erase(it);
        return true;
    }
    return false;
}

IPAddress hns::lookup(const HostName &name) const
{
    size_t index = hashFunction(name) % size;
    const auto &bucket = table[index];

    auto it = std::find_if(bucket.begin(), bucket.end(), [&](const std::pair<HostName, IPAddress> &pair)
                           { return pair.first == name; });

    if (it != bucket.end())
    {
        return it->second;
    }
    else
    {
        return NON_EXISTING_ADDRESS;
    }
}