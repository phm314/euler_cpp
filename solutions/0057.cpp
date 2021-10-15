// square root convergents
// n > d : 8 = 1st
// == 153

#include <iostream>
#include "Large.h"

int main () {
    Large numer = 1;
    Large denom = 1;
    int solution = 0;

    for (int i=0; i<1000; ++i) {
        Large tmp = numer + (denom * 2);
        denom = denom + numer;
        numer = tmp;
        if (numer.count() > denom.count())
            ++solution;
        
    }
    std::cout << solution;
}
