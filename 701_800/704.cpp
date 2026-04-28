#include "utils.hpp"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = static_cast<int>(nums.size() - 1);
        while (l <= r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums {5};
    int target = -5;

    Solution sol;
    auto result = sol.search(nums, target);
    cout << result << '\n';
}