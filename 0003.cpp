// largest prime factor of big number
// 13195 -> 29
// 6857

#include <iostream>
#include <cmath>
#include <vector>

bool isprime(long long int num);
std::vector<long long int> factors(long long int num);

int main () {
    constexpr long long int number = 600'851'475'143;
    long long int LPF = 0;
    std::vector test = factors(number);
    for (long long int i: test) {
        std::cout << i << "\n";
        if (isprime(i)) {
            std::cout << "is prime" << i << '\n';
            if (i > LPF) {
                LPF = i;
            }

        }
    }
    std::cout << "largest prime factor: " << LPF;
}

std::vector<long long int> factors(long long int num) {
    std::vector<long long int> result;
    for (int div=2; div < sqrt(num); ++div) {
        if (!(num % div)) {
            result.push_back(div);
            result.push_back(num / div);
        }
    }
    return result;
}

bool isprime(long long int num) {
    for (int div=2; div < sqrt(num); ++div){
        if (!(num % div)){
            return false;
        }
    }
    return true;
}
