#include "nameserverinterface.h"
#include <vector>
#include <string>

using namespace std;
using std::string;
using std::vector;

class hns : public NameServerInterface
{
public:
    void insert(const HostName&, const IPAddress&) = 0;
    bool remove(const HostName&) = 0;
    IPAddress lookup(const HostName&) const = 0;
private:
    vector<std::pair<HostName, IPAddress>> pairs;
};

/*
Implement a class
HNS (hash name server) that uses a hash table — a vector of vectors — to store the
name/address pairs.
The hash table implementation is open for experimentation: you must select an
appropriate size for the hash table (given as an argument to the constructor) and a
suitable hash function.18,19 You should be able to obtain approximately the same
search times as for the unordered map implementation

use:
std::hash<string>
*/