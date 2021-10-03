// even fibonacci numbers
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// != 14930347, 4613730
// == 4613732, include 2

#include <iostream>
#include <cmath>

bool is_even(int num);

int main () {
    int total = 0;
    int t1 = 1;
    int t2 = 1;
    int t3 = 0;
    int limit = 4'000'000;

    while (t3 < limit) {
        t3 = t1 + t2;
        if (is_even(t3)){
            std::cout << t3 << '\n';
            total += t3;
        }
        t1 = t2;
        t2 = t3;
    }

    std::cout << "total: " << total;
}
bool is_even(int num) {
    return (!(num % 2));
}
