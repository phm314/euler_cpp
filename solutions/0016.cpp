// power digit sum
// 2^15 : 26
// != 1189 (floor), 1188, 1195 (ceil), 1118(^1001)

// == 1366 (string)

#include <iostream>
#include <cmath>
#include <string>
std::string test = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";

int main () {
    double big = std::pow(2, 1001);
    int solution = 0;
//    while (big>1) {
//        double digit = std::fmod(big, 10.0);
//        big = std::floor(big / 10);
//        solution += digit;
//    }

    for (auto d: test) {
        int num = d - '0';
        solution += num;
    }
    std::cout << solution;
}
