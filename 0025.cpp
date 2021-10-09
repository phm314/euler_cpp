// 1000-digit fibonacci number
// 3 digits: 12
// == 4782

#include <iostream>
#include <vector>
#include <algorithm>

// storing large numbers as vectors
// leading 0 as last element for arithmetic

std::vector<int> addv(std::vector<int> a, std::vector<int> b);
std::vector<int> vfri(int i);
void printv(std::vector<int> v);

int main () {
    int index = 0;
    int target = 10000;
    std::vector<int> term = vfri(0);
    std::vector<int> next = vfri(1);
    std::vector<int> tmp;
    while (term.size() != (target + 1)) {
        ++index;
        tmp = term;
        term = addv(term, next);
        next = tmp;

    }
    std::cout << index << '\n';
    printv(term);
}

void printv(std::vector<int> v) {
    for (auto i: v) {
        std::cout << i;
    }
    std::cout << '\n';
}

std::vector<int> vfri(int i) {
    std::vector<int> result;
    while (i) {
        int digit = i % 10;
        i /= 10;
        result.push_back(digit);
    }
    result.push_back(0);
    return result;
}


std::vector<int> addv(std::vector<int> a, std::vector<int> b) {
    int msz;
    if (a.size() > b.size()) {
        msz = a.size();
        b.push_back(0);
    }
    else {
        msz = b.size();
    }

    std::vector<int> result;
    int carry = 0;
    int c;
    for (int i=0; i<msz; ++i) {
        c = a[i] + b[i] + carry;
        carry = 0;
        if (c >= 10) {
            carry = c / 10;
            c %= 10;
        }

        result.push_back(c);
    }
    if (carry || c)
    result.push_back(0);
    return result;
}
