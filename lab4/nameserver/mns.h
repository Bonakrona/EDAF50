#include "nameserverinterface.h"
#include <string>
#include <map>

using namespace std;
using std::string;
using std::map;

class mns : public NameServerInterface
{
public:
    void insert(const HostName&, const IPAddress&) = 0;
    bool remove(const HostName&) = 0;
    IPAddress lookup(const HostName&) const = 0;
private:
    map<HostName, IPAddress> pairs;
};