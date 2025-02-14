#include <vector>
#include <string>

#include "prime_numbers.h"
#include <cassert>
#include <iostream>

std::vector<std::size_t> get_primes(int number)
{    
    std::vector<std::size_t> primes;
    
    if (number < 2) return primes;

    std::string prime_markers(number+1, 'P');
    prime_markers[0] = prime_markers[1] = 'C';

    std::size_t prime_pos = prime_markers.find_first_of('P');
    while (prime_pos != std::string::npos)
    {   
        for (int n = prime_pos*2; n <= number; n += prime_pos)
        {
            prime_markers[n] = 'C';
        }

        primes.push_back(prime_pos);
        prime_pos = prime_markers.find_first_of('P', prime_pos+1);
    }

    return primes;
}

int biggest_prime(int number)
{
    std::vector<std::size_t> primes;
    primes = get_primes(number);

    int max_prime = 0;
    //max_prime = *std::max_element(primes.begin(), primes.end());
    if (primes.size() > 0) max_prime = primes.back();

    return max_prime;
}

void test_get_primes()
{
    std::vector<std::size_t> expected2 = {2, 3, 5, 7, 11, 13, 17, 19};
    assert(get_primes(20) == expected2);

    assert(get_primes(1).empty());
    assert(get_primes(-10).empty());
    assert(get_primes(2) == std::vector<std::size_t>{2});

    std::cout << "get_prime: All tests passed!\n";
}

void test_biggest_prime()
{
    assert(biggest_prime(3) == 3);
    assert(biggest_prime(100) == 97);
    
    assert(biggest_prime(1) == 0);
    assert(biggest_prime(-10) == 0);

    std::cout << "biggest_prime: All tests passed!\n";
}