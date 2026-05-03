#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t size = word2.size();
        vector<int> dp(size + 1, 0);

        for (size_t i = 0; i < size; ++i) {

        }
    }
};

int main() {
    string word1 {"horse"}, word2 {"ros"};
    Solution sol;
    cout << sol.minDistance(word1, word2) << '\n';
}
