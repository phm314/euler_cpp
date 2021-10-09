// maximum path sum ii
//
// 7273 ( copy paste )


#include <iostream>
#include <fstream>   // input
#include <vector>
#include <algorithm> // max

int main () {
    std::ifstream input("res/0067.txt");
    std::vector<std::vector<int>> tri;
    int len = 1;
    int prog = 0;
    std::vector<int> row;

    int num;
    while (input >> num) {
        ++prog;
        row.push_back(num);

        if (prog == len) {
            ++len;
            prog = 0;
            row.push_back(0);
            tri.push_back(row);
            row.clear();
        }
    }

    for (int r=tri.size()-2; r>=0; --r) {
        for (int i=0; i<=tri[r].size()-2;++i) {
            if (tri[r+1][i] > tri[r+1][i+1]) {
                tri[r][i] += tri[r+1][i];
            }
            else {
                tri[r][i] += tri[r+1][i+1];
            }
        }
    }
    for (auto x: tri) {
        for (auto i: x) {
            std::cout << i << " ";
        }
        std::cout << '\n';
    }
}
