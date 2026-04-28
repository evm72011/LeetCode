#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutiveMy(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }

        int best_len = 0;
        while (!st.empty()) {
            int l = 0, r = 0;
            int curr = *st.begin();
            while (st.count(curr - l)) {
                if (l != 0) st.erase(curr - l);
                l++;
            }
            while (st.count(curr + r)) {
                if (r != 0) st.erase(curr + r);
                r++;
            }
            st.erase(curr);
            int sub_len = r + l - 1;
            best_len = max(best_len, sub_len);
        }
        return best_len;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int best = 0;

        for (int x : st) {
            if (st.count(x - 1)) continue;  // не начало последовательности

            int y = x, len = 1;
            while (st.count(y + 1)) {
                y++;
                len++;
            }
            best = max(best, len);
        }
        return best;
    }
};

int main() {
    vector<int> nums { 100,4,200,1,3,2 };
    Solution sol;
    cout << sol.longestConsecutive(nums) << '\n';
}