// 10001st prime
// 6th = 13
// 104743

#include <iostream>
#include <cmath>

bool is_prime(int num);

int main () {
    int c = 1;
    int num = 2;
    while (c < 10001){
        ++num;
        if (is_prime(num))
            ++c;
    }
    std::cout << c << ", " << num;
}

bool is_prime(int num) {
    for (int div=2; div <= sqrt(num); ++div) {
        if (!(num % div))
            return false;
    }
    return true;
}
