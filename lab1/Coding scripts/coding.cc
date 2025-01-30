#include "coding.h"
#include <string>

const std::string albet{"abcdefghijklmnopqrstuvwxyz"};

unsigned char encode(unsigned char c)
{
    return c +1;
}
unsigned char decode(unsigned char c)
{
    return c -1;
}
