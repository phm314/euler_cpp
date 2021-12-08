// poker hands
// == 376

#include <iostream>  // cout
#include <fstream>   // ifstream
#include <string>    // string
#include <sstream>   // stringstream
#include <vector>    // vector
#include <utility>   // pair
#include <map>       // map
#include <algorithm> // sort


// Card = ( rank, suit )
using Card = std::pair<int, char>;

std::vector<std::vector<int>> score_hand(std::vector<Card> hand);

int main(int argv, char* arc[]) {
    int solution = 0;
    std::map<char, int> values;
    int i = 0;
    for (auto x: "23456789TJQKA") {
        values[x] = i;
        ++i;
    }
    std::ifstream file("res/0054.txt");
    std::string line;
    
    // read line by line
    while (std::getline(file, line)) {
        std::vector<Card> hand;
        std::stringstream lineStream(line);
        char rank, suit;

        while (lineStream >> rank >> suit) {
            Card pair ( (int) values[rank], suit);
            hand.push_back(pair);
        }
        auto player1 = std::vector<Card> (hand.begin(), hand.begin() + 5);
        auto player2 = std::vector<Card> (hand.begin() + 5, hand.end());
        
        auto p1score = score_hand(player1);
        auto p2score = score_hand(player2);

        if (p1score[0] > p2score[0]) {
            ++solution;
        } else if (p1score[0] == p2score[0]) {
            bool betterpair = false;
            for (int ind=0; ind<p1score[1].size(); ++ind) {
                if (p1score[1][ind] > p2score[1][ind]) {
                    ++solution;
                    betterpair = true;
                    break;
                } else if (p1score[1][ind] < p2score[1][ind]) {
                    betterpair = true;
                    break;
                }
            } 
            if (!betterpair) {
                for (int ind=0; ind<p1score[2].size(); ++ind) {
                   if (p1score[2][ind] > p2score[2][ind]) {
                       ++solution;
                       break;
                   } else if (p1score[2][ind] < p2score[2][ind]) {
                       break;
                   }
                } 
            }
        }
    }
    std::cout << solution << "\n";
}

std::vector<std::vector<int>> score_hand(std::vector<Card> hand) {
    /* High Card = 0
     * OneP, TwoP, ThreeK = 1, 2, 3
     * Str, Flu, FH, FourK = 4, 5, 6, 7
     * Str + Flu, RF = 8, 9
     *
     * Flush -> Straight -> Royal/ StrFlu?
     * FourK/ FH -> Flush / Straight?
     * ThreeK/ TwoP ?
     * OneP? -> High Card
     */
    std::vector<std::vector<int>> ret;
    std::vector<int> score = { 0 };
    std::vector<int> pairhighs;
    std::vector<int> resthighs;

    std::map<char, int> suitcounts;
    std::map<int, int> rankcounts;

    for (const auto& pair: hand) {
       ++suitcounts[pair.second];
       ++rankcounts[pair.first];
    }
      
    std::sort(hand.begin(), hand.end());
    
    bool straight = 0;
    bool flush = 0;

    // Check for flush and straight but don't score as such until higher hand
    // ranks have been checked
    if (suitcounts.size() == 1) {
        flush = true;
    }
    if (rankcounts.size() == 5) {
        if (hand[4].first - hand[0].first == 4) {
            // wrap straight
            straight = true;
        }
    }
    if (straight && flush) {
        // Royal or StrFlu
        if (hand[0].first == 8 && hand[4].first == 12) {
            score[0] = 9;
        } else {
            score[0] = 8;
        }
    }
    if (rankcounts.size() == 2) {
        // 2 dif. cards = fourK or FH
        for (const auto& elem: rankcounts) {
            if (elem.second == 4) {
                score[0] = 7;
                pairhighs.push_back(elem.first);
            } else if (elem.second == 3) {
                score[0] = 6;
                pairhighs.insert(pairhighs.begin(), elem.first);
            } else if (elem.second == 2) {
                pairhighs.push_back(elem.first);
            } else if (elem.second == 1) {
                resthighs.insert(resthighs.begin(), elem.first);
            }
        }
    } else if (!score[0] && (straight || flush)) {
        score[0] = (flush) ? 5 : 4;
    }
    
    if (rankcounts.size() == 3) {
        // ThreeK or TwoP
        for (const auto& elem: rankcounts) {
            if (elem.second == 3) {
                score[0] = 3;
                pairhighs.insert(pairhighs.begin(), elem.first);
            } else if (elem.second == 1) {
                resthighs.insert(resthighs.begin(), elem.first);
            } else if (elem.second == 2) {
                score[0] = 2;
                pairhighs.push_back(elem.first);
            }
        }
    } else if (rankcounts.size() == 4) {
        // OneP
        score[0] = 1;
        for (const auto& elem: rankcounts) {
            if (elem.second == 2) {
                pairhighs.insert(pairhighs.begin(), elem.first);
            } else {
                resthighs.insert(resthighs.begin(), elem.first);
            }
        }
    }

    if (!score[0]) {
        // High Card
        for (const auto& elem: rankcounts) {
            resthighs.insert(resthighs.begin(), elem.first);
        }
    }

    ret.push_back(score);
    ret.push_back(pairhighs);
    ret.push_back(resthighs);
    return ret;
}

