// amicable numbers
// 283 % 220
// == 31626

#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::sqrt, std::vector;

vector<int> perfect_divisors(int num);
int vector_sum(vector<int> vect);

int main () {
    int solution = 0;
    int limit = 10'000;

    for (int num=1; num<limit; ++num) {
        auto div = perfect_divisors(num);
        auto sum = vector_sum(div);

        if (sum != num) {
            auto div2 = perfect_divisors(sum);
            auto sum2 = vector_sum(div2);
            if (sum2 == num)
                solution += num;
                // could change to not check sum number (num2)
        }
    }
    cout << solution;
}

vector<int> perfect_divisors(int num) {
    vector<int> result;
    result.push_back(1);
    for (int div=2; div<=sqrt(num); ++div) {
        if (!(num % div)) {
            result.push_back(div);
            if (num/div != div)
                result.push_back(num / div);
        }
    }
    return result;
}

int vector_sum(vector<int> vect) {
    int result = 0;
    for (auto i: vect) {
        result += i;
    }
    return result;
}
