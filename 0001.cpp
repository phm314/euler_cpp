// multiples of 3 & 5
// 10 : 23
// 233168
#include <iostream>

bool valid(int i);

int main () {
    constexpr int limit = 1000;
    int total = 0;

    for (int i=1; i<limit; ++i) {
        if (valid(i))
            total += i;
//            std::cout << i << '\n';
    }
    std::cout << total;
}

bool valid(int i) {
    int val1 = i % 3;
    int val2 = i % 5;
    return (!val1 or !val2);
//    std::cout << i << ", " << val1 << val2 << "\n";
}
