#include <limits.h>
#include "utils.hpp"

int minSubArrayLen(int target, vector<int>& nums) {
    size_t l = 0, res = INT_MAX;
    int sum = 0;
    for (size_t r = 0; r < nums.size(); r++) {
        sum += nums[r];
        while (sum >= target) {
            res = min(res, r - l + 1);
            sum -= nums[l++];
        } 
    }
    return res == INT_MAX ? 0 : static_cast<int>(res);
}

int main() {
    vector<int> nums { 2,3,1,2,4,3 };
    int target = 7;

    cout << minSubArrayLen(target, nums) << '\n';
}
