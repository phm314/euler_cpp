// large sum
// use doubles ( up to E308 )
// == 5537376230

#include <iostream>
#include <fstream>
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream;

int main () {
    std::ifstream input("res/0013.txt");
    double num;
    double solution = 0;
    while (input >> num) { // read lines
        solution += num;
    }
    std::cout.precision(11);
    std::cout << solution;


}
