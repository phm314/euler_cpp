// XOR decryption
// == 129448

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream input("res/0059.txt");
    std::vector<int> nums;
    int num;

    if (input) {
        std::cout << "opened file";
    } else {
        std::cout << "not opened";
    }

    while (input >> num) {  
        nums.push_back(num);
        if (input.peek() == ',')
            input.ignore();
    }
    std::cout << '\n';
    char l1='e', l2='x', l3='p';
    char cont;
    while (cont != 'y') {
        if (cont == '1') {
            ++l1;
        } else if (cont == '2') {
            ++l2;
        } else if (cont == '3') {
            ++l3;
        }

        if (l1>'z') {
            l1='a';
        }
        if (l2>'z') {
            l2='a';
        }
        if (l3>'z') {
            l3='a';
        }
        std::cout << l1 << l2 << l3 << '\n';
               
        int ind = 0;
        int bit;
        for (auto x: nums) {
            if (ind == 3)
                ind = 0;
            if (ind == 0) {
                bit = l1;
            } else if (ind == 1) {
                bit = l2;
            } else if (ind == 2) {
                bit = l3;
            }
            std::cout << (char) (x ^ bit);
            ++ind;
        }
        
        std::cin >> cont;
        std::cout << '\n';
    }

    int ind = 0;
    int bit;
    int solution = 0;
    for (auto x: nums) {
        if (ind == 3)
            ind = 0;
        if (ind == 0) {
            bit = l1;
        } else if (ind == 1) {
            bit = l2;
        } else if (ind == 2) {
            bit = l3;
        }
        solution += (char) (x ^ bit);
        ++ind;
    }
    std::cout << solution;

}
