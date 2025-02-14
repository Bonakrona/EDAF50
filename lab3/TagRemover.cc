#include <string>
#include <fstream>
#include <iostream>

#include "tag_remover.h"

int main()
{
    TagRemover tr(std::cin); // read from cin
    tr.print(std::cout); // print on cout

    return 0;
}