#include <iostream>
#include "SimpleConfig.h"
#include "coding.h"
#include "list.h"



using std::cout;
using std::endl;

/* A small example of a project built using CMake.
 * The Simple_VERSION_* variables are included
 * to show how a header file with configuration macros
 * can be generated from the CMakeLists.txt.
 */
int main()
{
    cout << "This is version " << Simple_VERSION_MAJOR << "." <<
        Simple_VERSION_MINOR << "\n";
    cout << "Hello, world!\n";
    unsigned char a;
    a = 'a';
    unsigned char test_enc = encode(a);
    unsigned char test_dec = decode(a);
}


