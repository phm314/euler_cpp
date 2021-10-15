// summation of primes
// 10 = 17
// != 1179908154 (overflow!)
// == 142913828922

#include <iostream>
#include <cmath>

bool is_prime(int num);

int main () {
    constexpr int limit = 2'000'000;
    long long int result = 0;
    for (int i=2; i<limit; ++i) {
        if (is_prime(i)) result += i;
    }
    std::cout << result;
}

bool is_prime(int num) {
    for (int div=2; div <= std::sqrt(num); ++div) {
        if (!(num % div)) return false;
    }
    return true;
}
