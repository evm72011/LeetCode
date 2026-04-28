#include "utils.hpp"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0];
        int l = 0, r = static_cast<int>(nums.size()) - 1;
        while (l <= r) {
            auto mid = l + (r - l) / 2;
            if (nums[l] <= nums[mid]) {
                // left sorted
                result = min(result, nums[l]);
                l = mid + 1;
            } else {
                // right sorted
                result = min(result, nums[mid]);
                r = mid - 1;
            }
        }
        return result;
    }

    int findMinCanonical(vector<int>& nums) {
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1; // left sorted. but the min is near the rotation point - we can emit the left 
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};

int main() {
    vector<int> nums { 3,4,5,1,2 };

    Solution sol;
    cout << sol.findMin(nums) << '\n';
    cout << sol.findMinCanonical(nums) << '\n';
}
