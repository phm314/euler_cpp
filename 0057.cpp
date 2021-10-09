// square root convergents
// n > d : 8 = 1st

#include <iostream>


int main () {
    int numer = 1;
    int denom = 1;

    for (int i; i<10; ++i) {
        int tmp = numer + (2 * denom);
        denom = denom + numer;
        numer = tmp;

        std::cout << numer << ", " << denom << '\n';
    }
}
