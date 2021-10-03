// factorial digit sum
// 10 -> 3628800 : 27
// 93326215443944175354307254139643190247129328132295862491935879110669343325734178368282822618707234467717279847537548956702435362278960753539491860335688679424
// != 734,
#include <cmath>
#include <iostream>
#include <string>

double factorial(double num);

int main () {
    double num = 25;
    double f = factorial(num);
    double result = 0;

    std::string s = std::to_string(f);

    std::cout << f << '\n';
    std::cout << s << '\n';

    for (auto x: s) {
        if (x == '.')
            break;
        std::cout << x << ", ";
        result += (int) x - '0';
    }
    std::cout << '\n' << result;
}

double factorial(double num) {
    double result = 1;
    while (num) {
        result *= num;
        --num;
    }
    return result;
}
