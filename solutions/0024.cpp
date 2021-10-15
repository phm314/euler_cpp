// lexicographic permutations
//
// == 2783915460

#include <iostream>
#include <vector>
#include <algorithm>

int main () {
    int numbers[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int perm = 1;
    int target = 1'000'000;
    while (std::next_permutation(numbers, numbers+10)) {
        ++perm;
        if (!(perm % target)) {
            std::cout << '\n';
            std::cout << perm << ": ";
            for (auto x: numbers) {
                    std::cout << x << " ";
            }
            break;
        }
    }
}
