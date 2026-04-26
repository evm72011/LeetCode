#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> best;
        best.reserve(nums.size());

        best.push_back(nums[0]);
        best.push_back(max(nums[0], nums[1]));
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