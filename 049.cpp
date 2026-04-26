#include <string>
#include "utils.hpp"
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for (const auto& str : strs) {
            auto token = str;
            sort(token.begin(),token.end());
            mp[token].push_back(str);
        }

        vector<vector<string>> result;
        result.reserve(mp.size());
        for (auto& [_, value] : mp) {
            result.push_back(std::move(value));
        }
        return result;
    }
};

int main() {
    vector<string> strs { "eat","tea","tan","ate","nat","bat" };

    Solution sol;
    auto result = sol.groupAnagrams(strs);
    print(result);
}