// factorial digit sum
// 10 -> 3628800 : 27
// != 734 overflow
// == 648 (vector)

#include <iostream>
#include <vector>

std::vector<int> vfri(int i);
std::vector<int> vbys (std::vector<int> vect, int s);
void printv(std::vector<int> vect);

int main() {
    auto n = vfri(1);
    for (int i=1; i <= 100; ++i) {
        n = vbys(n ,i);
    }

    int solution = 0;
    for (auto i: n) {
        solution += i;
    }
    std::cout << solution;
}

std::vector<int> vfri(int i) {
    std::vector<int> result;
    while (i) {
        int digit = i % 10;
        i /= 10;
        result.push_back(digit);
    }
    result.push_back(0);
    printv(result);

    return result;
}

std::vector<int> vbys (std::vector<int> vect, int s) {
    std::vector<int> result;
    int carry = 0;
    for (auto digit: vect) {
        int num = digit * s + carry;
        carry = 0;
        if (num >= 10) {
            int c = 1;
            while (num >= 10) {
                carry += (num / 10) * c;
                num %= 10;
            }
        }
        result.push_back(num);
        // num is < 10, carry has value
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
void printv(std::vector<int> v) {
    for (auto i: v) {
        std::cout << i << ", ";
    }
    std::cout << '\n';
}
