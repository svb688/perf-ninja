
#include "solution.h"
#include <random>

void init(std::array<S, N> &arr) {
  std::default_random_engine generator;
  std::uniform_int_distribution<uint8_t> distribution(minRandom, maxRandom - 1);

  for (int i = 0; i < N; i++) {
      uint8_t random_int1 = distribution(generator);
      uint8_t random_int2 = distribution(generator);

    arr[i].i = random_int1; // only need to be 8 bit
    arr[i].s = random_int2 | ((random_int1 < random_int2) << 7); // 8 bits as well
    arr[i].l = random_int1 * random_int2; // 99 * 99 = 9801 need to be short
    arr[i].d = static_cast<float>(random_int1) / maxRandom; // could be downgrade to float
  }
}
