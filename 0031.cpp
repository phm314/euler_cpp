

#include <iostream>

int nextcoin(int target, int i);

int main() {
    constexpr int values[]  = {1, 2, 5, 10, 20, 50, 100, 200};
    constexpr int target    = 200;
    int solution[target+1];
    for (int i=0; i<target; ++i) {
        for (int j=values[i]; j<=target; ++j) { 
            solution[j] += solution[j - values[i]];
        }
    }
    std::cout << solution;
}