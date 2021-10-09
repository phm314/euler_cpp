// powerful digit sum
// 10^100 : 1
// != 684
// == 972

#include <iostream>
#include <vector>

std::vector<int> vect_from_int(int i);
std::vector<int> vect_mult_int(std::vector<int> vect, int i);
int vect_sum(std::vector<int> vect);
void printv(std::vector<int> v);

int main () {
    int solution = 0;
    for (int a=2; a<=99; ++a) {
        for (int b=2; b<=99; ++b) {
            auto num = vect_from_int(a);
            for (int e=1; e<b; ++e) {
                num = vect_mult_int(num, a);
            }
            int vsum = vect_sum(num);
            if (vsum > solution)
                solution = vsum;
        }
    }
    std::cout << solution;
}
void printv(std::vector<int> v) {
    for (auto x: v) {
        std::cout << x << " ";
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

int vect_sum(std::vector<int> vect) {
    int result = 0;
    for (auto i: vect) {
        result += i;
    }
    return result;
}
