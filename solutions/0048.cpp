// self powers
// 1..10 : 10405071317
// == 9110846700

#include <iostream>
#include <vector>

std::vector<int> vect_from_int(int i);
std::vector<int> vect_mult_int(std::vector<int> vect, int i);
std::vector<int> vect_add_vect(std::vector<int> a, std::vector<int> b);
void printv(std::vector<int> v);

int main () {
    auto solution = vect_from_int(0);
    for (int i=1; i<=1000; ++i) {
        auto term = vect_from_int(i);
        for (int e=1; e<i; ++e) {
            term = vect_mult_int(term, i);
        }
        solution = vect_add_vect(term, solution);
    }
    printv(solution);
}
void printv(std::vector<int> v) {
    for (auto x: v) {
        std::cout << x;
    }
    std::cout << '\n';
}

std::vector<int> vect_from_int(int i) {
    std::vector<int> result;
    while (i) {
        int digit = i % 10;
        i /= 10;
        result.push_back(digit);
    }
    result.push_back(0);
    return result;
}

std::vector<int> vect_mult_int(std::vector<int> vect, int i){
    std::vector<int> result;
    int carry = 0;
    for (auto digit: vect) {
        int num = digit * i + carry;
        carry = 0;
        if (num >= 10) {
            int c = 1;
            while (num >= 10) {
                carry += (num / 10) * c;
                num %= 10;
            }
        }
        result.push_back(num);
    }
    if (carry) {
        while (carry >= 10) {
            result.push_back(carry % 10);
            carry /= 10;
        }
        result.push_back(carry);
    }
    return result;
}

std::vector<int> vect_add_vect(std::vector<int> a, std::vector<int> b) {
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
