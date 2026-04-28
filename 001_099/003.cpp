#include <unordered_set>
#include "utils.hpp"


int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    size_t l = 0, result = 0;
    for (size_t r = 0; r < s.size(); r++) {
        while (st.count(s[r])) st.erase(s[l++]);
        st.insert(s[r]);
        result = max(result, r - l + 1);
    }
    return static_cast<int>(result);
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << '\n'; 
}