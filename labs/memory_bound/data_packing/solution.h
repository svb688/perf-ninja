#include <array>
#include <random>
#include <algorithm>


// Assume those constants never change
constexpr int N = 10000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

// FIXME: this data structure can be reduced in size
struct S1 {
  int i;
  long long l;
  short s;
  double d;
  bool b;

  bool operator<(const S1 &s) const { return this->i < s.i; }
};

struct S2 {
  float d; // double -> float since we don't care about precision
  short l; // maximum number can be just 10000, since 100*100=10000, only needs 16 bits = 2 bytes
  unsigned short i:8; // only needs 7 bits, using 8 so it is aligned
  unsigned short s:7;
  bool b:1;

  bool operator<(const S2 &s) const { return this->i < s.i; }
};

// to get size of a class, Scott Meyer's trick
template<int N>
class TD;

// TD<sizeof(S1)> td1; // 40
// TD<sizeof(S2)> td2; // just 8!

template<class T>
T create_entry(int first_value, int second_value) {
  T entry;

  entry.i = first_value; // only needs 7 bits
  entry.s = static_cast<short>(second_value);
  entry.l = static_cast<long long>(first_value * second_value); // maximum number can be just 10000, since 100*100=10000, only needs 16 bits
  entry.d = static_cast<double>(first_value) / maxRandom;
  entry.b = first_value < second_value;

  return entry;
}

template<class T>
void init(std::array<T, N> &arr) {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(minRandom, maxRandom - 1);

  for (int i = 0; i < N; i++) {
    int random_int1 = distribution(generator);
    int random_int2 = distribution(generator);

    arr[i] = create_entry<T>(random_int1, random_int2);
  }
}

template<class T>
void solution(std::array<T, N> &arr) {
  // 1. shuffle
  static std::random_device rd;
  static std::mt19937 g(rd());
  std::shuffle(arr.begin(), arr.end(), g);

  // 2. sort
  std::sort(arr.begin(), arr.end());
}
