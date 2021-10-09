//digit factorials
// 145: 145
// != 40749, 40746
// == 40730 (initialize solution)

#include <iostream>

int fact(int n);
int dfsum(int n);
int table[10];

int main () {
    long long int solution = 0;

    for (int i=0; i<10; ++i) {
        table[i] = fact(i);
    }
    int limit = 1'000'000;
    for (int n=3; n<=limit;++n) {
        auto dfs = dfsum(n);

        if (n == dfs) {
            solution += n;
            std::cout << n << ": " << dfs << '\n';
        }
    }
    std::cout << solution;
}

int fact(int n) {
    if (n<=1)
        return 1;
    return (n * fact(n - 1));
}

int dfsum(int n) {
    int result = 0;
    while (n) {
        int digit = n % 10;
        int x = table[digit];
        result += x;

        n /= 10;
    }
    return result;
}
