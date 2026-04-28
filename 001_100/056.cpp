#include "utils.hpp"
#include <algorithm>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        auto prev = intervals[0];
        for(const auto& curr : intervals) {
            auto overlap = prev[1] >= curr[0];
            if (overlap) {
                prev[1] = max(prev[1], curr[1]);
            } else {
                result.push_back(prev);
                prev = curr;
            }
        }
        result.push_back(prev);
        return result;
    }
};

int main() {
    vector<vector<int>> intervals { 
        {1,3}, {2,6}, {8,10}, {15,18}
    };
    Solution sol;

    auto result = sol.merge(intervals);
    print(result);
}
