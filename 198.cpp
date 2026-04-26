#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> best(nums.size(), 0);

        best[0] = nums[0];
        best[1] = max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size(); ++i) {
            best[i] = max(
                best[i - 1],
                best[i - 2] + nums[i]
            );

        }
        return best.back();
    }
};

int main() {
    vector<int> nums { 1,2,3,1 };
    Solution sol;
    cout << sol.rob(nums) << '\n';
}