#include "coding.h"
#include <iostream>
#include <string>

const std::string albet = { "abcdefghijklmnopqrstuvwxyza" };

unsigned char encode(unsigned char c)
{
    //encoded character
    unsigned char c_enc;
    for (size_t i = 0; i < albet.length()-1; ++i)
    {
        if (c == albet[i]) {
            c_enc = albet[i+1];
           return c_enc;
        }
        
    }
    
    // if the character is not found like a space or a sign
    // the charcater just stays the same and is returned
    c_enc = c;
    return c_enc;
}

unsigned char decode(unsigned char c)
{
    //decoded character
    unsigned char c_dec;
    for (size_t i = 1; i < albet.length(); ++i)
    {
        if (c == albet[i]) {
           c_dec = albet[i-1];
           return c_dec;
        }
        
    }
    
    // if the character is not found like a space or a sign
    // the charcater just stays the same and is returned
    c_dec = c;
    return c_dec;
}
