// digit fifth powers
// 1634, 8208, 9474
// != 441139,
// == 443839 (add)
//4150, 4151, 54748, 92727, 93084, 194979

#include <iostream>
#include <cmath>

long long int powersum(int num);
//int table[10] {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561}; // 4th
int table[10] {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049}; // 5th
// pow can be inaccurate
int main () {

    int solution;
    for (int num=10; num < 1'000'000'000; ++num) {
        auto res = powersum(num);
        if (res == num)
            std::cout << num << '\n';
        if (!(num % 10'000'000)) {
            std::cout << "num: " << num << ": " << res << '\n';
        }
    }
}

long long int powersum(int n) {
    long long int result = 0;
    while (n) {
        int digit = n % 10;
        int x = table[digit];
        result += x;
        n /= 10;
    }
    return result;
}
