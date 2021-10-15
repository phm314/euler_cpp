// smalles multiple
// 1..10 = 2520
// != 71279104, 158392057824000
// == 232792560

#include <iostream>
#include <cmath>

int lcm(int a, int b);
int gcf(int a, int b);


int main() {
    int sol = 1;
    for (int i=2; i<21; ++i) {
        sol = lcm(sol, i);
    }
    std::cout << sol;
}

int gcf(int a, int b) {
    if (!b) return a;
    return gcf(b, a % b);
}

int lcm (int a, int b) {
    return (a / gcf(a, b)) * b;
}
