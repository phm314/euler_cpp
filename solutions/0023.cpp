// non-abundant sums
//
// != 4207994 (first attempt) ,31531501 (abundant numbers <= limit / 2)
// , 391257632 (num of abundant sums),
// == 4179871 (abundant sum can be 28123!)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::vector, std::sqrt;

vector<int> proper_divisors(int num);
int vector_sum(vector<int> vect);

int main () {
    int limit = 28123;
    vector<int> abundant;

    // find abundant numbers

    for (int number=1; number <= limit; ++number) {
        auto div = proper_divisors(number);
        auto vsum = vector_sum(div);
        if (vsum > number) {
            abundant.push_back(number);
        }
    }

    // find numbers that can be written as sum of two abundant numbers < 28123

    vector<int> abundant_sums;
    // could improve w/ lookup unorderd_map
    for (int ind1=0; ind1 < abundant.size(); ++ind1) {
        int num1 = abundant[ind1];
        for (int ind2=ind1; ind2 < abundant.size(); ++ind2) {
            int num2 = abundant[ind2];
            int possible = num1 + num2;

            if (possible <= limit) // <=, not < !
                abundant_sums.push_back(possible);
        }
    }

    // sort and prune unique numbers from ab. sums

//    std::sort(abundant_sums.begin(), abundant_sums.end());
// sorting is slow, no need it
//    auto it = std::unique(abundant_sums.begin(), abundant_sums.end());
//    abundant_sums.resize(std::distance(abundant_sums.begin(), it));

    // if number not in ab.sums, then add it to solution
    std::vector<bool> truth(limit);

    for (auto i: abundant_sums) {
//        std::cout << i << ", ";
        truth[i] = true;
    }

    int solution = 0;
    for (int n=1; n <= limit; ++n) {
        if (!truth[n])
            solution += n;
    }
    std::cout << solution;
}

vector<int> proper_divisors(int num) {
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
