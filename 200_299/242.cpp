#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        
        for (const auto& c : s) {
            freq[c - 'a']++;
        }
        
        for (const auto& c : t) {
            if (--freq[c - 'a'] < 0) return false;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    auto result = sol.isAnagram("anagram", "nagaram");
    cout << boolalpha << result << '\n';
}
