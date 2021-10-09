// truncatable primes
// 3797 : 797, 97, 7 & 379, 37, 3
// 748317 (1 is not prime!)

#include <iostream>

// n cannot have 2, 4, 8, 6, 5, 0 for (n / 2 or n / 5, n / 10)

bool is_truncprime(int n);
bool is_prime(int n);

int main () {
    int limit = 1000'000;
    int solution = 0;
    for (int n=1; n <= limit; ++n) {
        if (is_prime(n) and is_truncprime(n)) {
            std::cout << n << '\n';
            solution += n;
        }
    }
    std::cout << solution;
}

bool is_prime(int n) {
    if (n == 1) return false;
    for (int d=2; d*d<=n; ++d) {
        if (!(n % d)) {
            return false;
        }
    }
    return true;
}

bool is_truncprime(int n) {
    if (n==2 || n==3 || n==5 || n==7) return false;
    int c = 1;
    while (true) {
        int d1 = n % (10 * c);
        int d2 = n / (10 * c);

        if (!is_prime(d1) or !is_prime(d2))
            return false;
        c *= 10;
        if (c > n) break;
    }
    return true;
}
