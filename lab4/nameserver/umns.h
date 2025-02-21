#include "nameserverinterface.h"
#include <unordered_map>
#include <string>

using namespace std;
using std::string;
using std::unordered_map;

class umns : public NameServerInterface
{
public:
    void insert(const HostName&, const IPAddress&) = 0;
    bool remove(const HostName&) = 0;
    IPAddress lookup(const HostName&) const = 0;
private:
    unordered_map<HostName, IPAddress> pairs;
};