// distinct powers
// 2->5 & 2->5 : 15 terms
// != 9801, 9220 (unique, set,)

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>

int main () {
//    std::vector<double> powers;
    std::set<double> powers;
    for (double a=2; a <= 100; ++a) {
        for (double b=2; b<= 100; ++b) {
//            powers.push_back( pow(a, b) );
            double result = pow(a, b);
            powers.insert(result);
        }
    }

//    std::sort(powers.begin(), powers.end());
//    auto it = std::unique(powers.begin(), powers.end());
//    powers.resize(std::distance(powers.begin(), it));

    std::cout << powers.size() << '\n';


}
