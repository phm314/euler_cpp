// largest palindrome product
// 2 digit numbers: 9009 = 91 × 99
// != 998001
// == 906609

#include <iostream>
#include <cmath>
#include <vector>

bool is_palnum(int num);
int num_len(int num);
bool check_vector(std::vector<int> vect);

int main () {
    int LPP = 0;
    for (int t1=100; t1<1000; ++t1) {
        for (int t2=100; t2<1000; ++t2) {
            int product = t1 * t2;
            if (is_palnum(product))
                if (product > LPP) {
//                    std::cout << product << ", " << LPP << '\n';
                    LPP = product;
                }
        }
    }
    std::cout << LPP;
}

int num_len(int num) {
    int len;
    while (num) {
        num /= 10;
        len++;
    }
    return len;
}

bool check_vector(std::vector<int> vect) {
    int sz = vect.size();
    for (int i=0; i<sz; ++i) {
        int j = (sz-1) - i;
        if (vect[i] != vect[j])
            return false;
    }
    return true;
}

bool is_palnum(int num) {
    int len = num_len(num);
    std::vector<int> vect;

    for (int index=0; index<len; ++index) {
        int i = num % 10;
        vect.push_back(i);
        num /= 10;

    }
    return check_vector(vect);
}





















