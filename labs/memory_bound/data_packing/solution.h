
#include <array>
#include <cstdint>

// Assume those constants never change
constexpr int N = 10000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

// FIXME: this data structure can be reduced in size
struct S {
    float d; // 32 bit float
    unsigned short l : 15; // 99 * 99 = 9801 -> 15 bits
    uint8_t i : 7; // 0-99 = 7 bits
    uint8_t s : 7; // 0-99 = 7 bits
    bool b : 1; // bit shift it into s
    // TODO: do float really need to be decimal? It all values will be between 0.0 and 0.99

    bool operator<(const S &s) const { return this->i < s.i; }
};

void init(std::array<S, N> &arr);
void solution(std::array<S, N> &arr);
