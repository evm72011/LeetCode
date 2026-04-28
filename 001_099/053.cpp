#include "utils.hpp"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], result = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};

int main() {
    vector<int> nums { -2,1,-3,4,-1,2,1,-5,4 };
    Solution sol;
    auto result = sol.maxSubArray(nums);
    cout << result << '\n';
}
