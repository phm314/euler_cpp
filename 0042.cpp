// coded triangle numbers
// SKY : 55 : true
// != 172
// == 162 (correct triangle numbers)

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> tri_nums();
bool is_trinum(int n);
std::vector<int> tris;

int main () {
    tris = tri_nums();
    int solution = 0;

    std::ifstream input ("res/0042.txt");
    std::unordered_map<int, int> valmap;
    char ch;
    int namevalue = 0;

    while (input >> ch) {
        if (ch == ',') {
            ++valmap[namevalue];
            namevalue = 0;
        } else {
            if (ch == '"')
                continue;
            namevalue += ch - 'A' + 1;
        }
    }
    ++valmap[namevalue]; // last value
    for (auto x: valmap) {
        if (is_trinum(x.first)) {
            solution += x.second;
        }
    }
    std::cout << solution;
}

std::vector<int> tri_nums() {
    std::vector<int> result;
    int term = 0;
    for (int add=1; add<30; ++add) {
        result.push_back(term+=add);
    }
    return result;
}
bool is_trinum(int n) {
    if (std::find(tris.begin(), tris.end(), n) != tris.end())
        return true;
    return false;
}











