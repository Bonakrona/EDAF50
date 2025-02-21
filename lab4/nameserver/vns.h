#include "nameserverinterface.h"
#include <vector>
#include <string>

using namespace std;
using std::string;
using std::vector;

class vns : public NameServerInterface
{
public:
    void insert(const HostName&, const IPAddress&) = 0;
    bool remove(const HostName&) = 0;
    IPAddress lookup(const HostName&) const = 0;
private:
    vector<std::pair<HostName, IPAddress>> pairs;
};