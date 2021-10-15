// names scores
// "COLIN" = 53
// != 324536 (sort & multiply), 870869298 (include final name)
// 871198282

#include <iostream>  // cout
#include <fstream>   // read file
#include <vector>    // store names
#include <algorithm> // sort names

int main () {
    std::ifstream input("res/0022.txt");
    char letter;
    int solution = 0;
    std::vector<std::vector<char>> namelist;
    std::vector<char> name;

    while (input >> letter) { // read by char
        if (letter != '"' && letter != ',') {
            name.push_back(letter);

        } else if (letter == ',') {
            namelist.push_back(name);
            name.clear();
        }
    }
    namelist.push_back(name); // push final

    std::sort(namelist.begin(), namelist.end());
    // can sort nested, apparently

    for (int ind=0; ind < namelist.size(); ++ind) {
        int value = 0;
        for (auto ch: namelist[ind]) {
            value += ch - 'A' + 1;
        }
        solution += (value * (ind + 1));
    }
    std::cout << solution;
}
