// integer right trianges
// 120: 3
// == 840

#include <iostream>
bool is_right(int a, int b, int c);


int main () {
    int maxp = 0;
    int maxn = 0;

    for (int p=3; p<=1000; ++p) {
        int n = 0;

        for (int a=1; a<=(p-1)/2; ++a) {
            for (int b=a+1; b<=(p-a)/2; ++b) {
                int c = p - (a + b);
                if (c == a or c == b) break;
                if (is_right(a, b, c)) ++n;
            }
        }
        if (n > maxn) {
            std::cout << p << ": " << n << '\n';
            maxp = p;
            maxn = n;

        }
    }
    std::cout << "solution: " << maxp << ": " << maxn;
}

bool is_right(int a, int b, int c) {
    bool result =
    a * a + b * b == c * c;


    return result;
}
