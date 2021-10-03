// special pythagorean triplet
// == 31875000

#include <iostream>
#include <cmath>
bool is_ptriple(int a, int b, int c);

int main () {
    for (int a=1; a<1000; ++a) {
        for (int b=a+1; b<1000; ++b) {
            for (int c=b+1; c<1000; ++c) {
                if (is_ptriple(a, b, c))

                    if ((a + b + c) == 1000) {
                        std::cout << a << ", " << b << ", " << c << '\n';
                        std::cout << a * b * c;
                        return 0;
                    }
            }
        }
    }
}

bool is_ptriple(int a, int b, int c) {
    int sa = std::pow(a, 2);
    int sb = std::pow(b, 2);
    int sc = std::pow(c, 2);

    return ((sa + sb) == sc);
}
