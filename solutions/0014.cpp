// longest collatz sequence
// even: n / 2; odd: 3*n + 1;
// == 83779 (overflow)

#include <iostream>
#include <unordered_map>

bool is_even(int num);
int collatz_len(double num);

std::unordered_map<int, int> table;

int main () {
    int maxlen = 0;
    int maxnum = 0;
    for (int num=1; num<1'000'000; ++num) {
        int next = collatz_len(num) + 1; // add one for (1)
        if (next > maxlen) {
            maxlen = next;
            maxnum = num;
            std::cout << maxnum << "; " << maxlen << '\n';
        }
    }
    std::cout << maxnum << "; " << maxlen;
}

bool is_even(int num) {
    return (!(num % 2));
}

int collatz_len(double num) {
    int snum = num;
    int c = 0;
    while (num != 1) {
        if (table.find(num) != table.end()) {
            c = c+table[num];
            break;
        }
        c++;
        if (is_even(num)) {
            num /= 2;
        } else {
            num = num * 3 + 1;
        }
    }
    table[snum] = c;
    return c;
}
