#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size(); ++i) {
            int best = max(
                prev1,
                prev2 + nums[i]
            );

            prev2 = prev1;
            prev1 = best;

        }
        return prev1;
    }
};

int main() {
    vector<int> nums { 1,2,3,1 };
    Solution sol;
    cout << sol.rob(nums) << '\n';
}