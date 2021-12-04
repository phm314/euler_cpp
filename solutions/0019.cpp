// counting sundays
// 1901->2001
// != 173, 174
// == 171

#include <iostream>

constexpr int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argv, char* argc[]) {
    int weekday  = 0;
    int   month  = 0;
    int    year  = 1901;
    int solution = 0;

    while (year < 2001) {
        weekday = (weekday + months[month]) % 7;
        ++month;
        if (!(year % 4) && month == 1) {
            weekday += 1;
        }
        if (month == 12) {
            year += 1;
            month = 0;
        }
        if (weekday == 6 && year != 2001) {
            ++solution;
        }
    }
    std::cout << solution;
}
