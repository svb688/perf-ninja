
#include "solution.h"
#include <random>

void init(std::array<S, N> &arr)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<uint8_t> distribution(minRandom, maxRandom - 1);

    for (int i = 0; i < N; i++)
    {
        uint8_t random_int1 = distribution(generator);
        uint8_t random_int2 = distribution(generator);
        arr[i] = S(static_cast<float>(random_int1) / maxRandom, random_int1 * random_int2, random_int1, random_int2,random_int1 < random_int2 );
    }
}
