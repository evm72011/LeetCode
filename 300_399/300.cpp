#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size(), 1);

        int res = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main() {
    vector<int> nums { 10,9,2,5,3,7,101,18 };
    Solution sol;
    cout << sol.lengthOfLIS(nums) << '\n';
}
