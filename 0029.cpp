// distinct powers
// 2->5 & 2->5 : 15 terms
// != 9801, 9220 (unique, set,), 9134 (Large)
// == 9183 (py)

#include <iostream>
#include <set>
#include <vector>

// brute force
#include "Large.h"

int main () {
    auto expo = Large (5);
    std::set<Large> powers;
    std::vector<Large> pows;

    for (int a=2; a<=100; ++a) {
        std::cout << '\n' << a << ": ";
        Large base {a};
        
        for (int b=2; b<=100; ++b) {
            std::cout << b << ", ";
            Large result {1};
            for (int e=0; e<b; ++e) {
                result = result * base;
            }
            bool push = true;
            for (auto i: pows) {
                if (result == i) {
                    push = false;
                    break;
                }
                    
            }
            if (push)
                pows.push_back(result);
        }
    }
    std::cout << '\n' << pows.size();
}
