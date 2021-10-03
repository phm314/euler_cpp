// highly divisible triangular numbers
// 7th = 28, num divisors = 6
// == 76576500

#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> factors(int num);

int main () {
    int n = 1;
    int tri = 0;

    while (true) {
        tri += n;
        n++;
        auto fac = factors(tri);
        int numfac = fac.size();
        if (numfac > 500) {
            std::cout << n << ", " << tri << ", " << numfac << '\n';
            break;
        }
    }
}

std::vector<int> factors (int num) {
    std::vector<int> fac;
    for (int i=1; i<= std::sqrt(num); ++i) {
        if (!(num % i)) {
            fac.push_back(i);
            fac.push_back(num / i);
        }
    }
    return fac;
}
