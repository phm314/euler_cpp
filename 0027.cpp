// quadratic primes
// n^2 + n + 41 : 0 -> 39, n^2 - 79 + 1601 : 0 -> 79
// 308483 (positive), 479867 (all), -60939 (num v. n)
// -59231 (isprime & abs -)

#include <iostream>
int quad(int n, int b, int c);
bool is_prime(int num);


int main () {
    int maxn = 0;
    int solution = 0;
    for (int a=-999; a<1001; ++a) {
        for (int b=-1000; b<1001; ++b) {
            int n = 0;
            while (true) {
                auto num = quad(n, a, b);
                if (!is_prime(abs(num))) {
                    if (n > maxn) {
                        maxn = n;
                        solution = a * b;
                    }
                    break;
                }
                ++n;
            }
        }
    }
    std::cout << solution;
}

int quad(int n, int b, int a) {
    return (n * n + a * n + b);
}

bool is_prime(int num) {
    for (int div=2; div*div <= num; ++div) {
        if (!(num % div))
            return false;
    }
    return true;
}
