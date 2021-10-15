// number spiral diagonals
// 5 x 5 : 101
// == 1001 x 1001 : 669171001 (vector > array for size limit)

#include <iostream>
#include <vector>

void nx(int& dx);
int diagonal_sum (std::vector<int> nums, int sz);

int main () {
    constexpr int sz = 1001;

    int direction[] {-1, sz, 1, -sz}; // l d u r
    std::vector<int> nums(sz * sz);
    int dx = 0;
    int stind = sz - 1;

    nums[stind] = sz*sz;

    for (int val=sz*sz-1; val > 0; --val) {
        while (true) {
            int ind = stind + direction[dx];
            if (ind < 0 || ind >= sz*sz) {
                nx(dx);
            } else {
                if (nums[ind] == 0) {
                    stind = ind;
                    nums[ind] = val;
                    break;
                } else {
                    nx(dx);
                }
            }
        }
    }

    std::cout << diagonal_sum(nums, sz);
}

void nx(int& dx) {
    ++dx;
    if (dx == 4) {
        dx = 0;
    } else {
        dx = dx;
    }
}
int diagonal_sum(std::vector<int> nums, int sz) {

    long int result = 0;
    for (int r=0; r < sz; ++r) {
        int ind1 = r * sz + r;
        int ind2 = r * sz + (sz - (r + 1));
//        std::cout << ind1 << ", " << ind2 << '\n';
        result += nums[ind1] + nums[ind2];
    }
    return result - 1;
}

