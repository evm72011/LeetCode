#include <algorithm>
#include "utils.hpp"

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        size_t prev_idx = 0;
        for (size_t i = 1; i < intervals.size(); i++) {
            const auto& prev = intervals[prev_idx];
            const auto& curr = intervals[i];

            auto overlap = prev[1] > curr[0];
            if (overlap) {
                prev_idx = (prev[1] < curr[1]) ? prev_idx : i;
                result++;
            } else {
                prev_idx = i;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> intervals {
        {1,2}, {2,3}, {3,4}, {1,3}
    };

    Solution sol;
    cout << sol.eraseOverlapIntervals(intervals) << '\n';
}