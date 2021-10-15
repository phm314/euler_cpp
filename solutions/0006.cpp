// sum square difference
// 1..10 = 2640
// == 25164150


#include <iostream>
#include <cmath>

int main () {
    int amt = 100;
    int sqsum = 0;
    int sumsq = 0;

    for (int num=1; num<=amt; ++num) {
        sqsum += pow(num, 2);
        sumsq += num;
    }
    sumsq = pow(sumsq, 2);
    std::cout << sumsq - sqsum;

}
