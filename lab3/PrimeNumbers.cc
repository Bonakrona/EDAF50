#include <iostream>
#include <vector>

#include "prime_numbers.h"

int main()
{
    std::vector<std::size_t> primes_up_to_200 = get_primes(200);

    std::cout << "Prime numbers between 1 and 200: ";
    for (const auto& prime : primes_up_to_200)
    {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    int largest_prime = biggest_prime(100000);
    std::cout << "The largest prime less than 100 000 is: " << largest_prime << std::endl;

    return 0;
}