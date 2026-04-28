#include "utils.hpp"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t pos = 0;

        for (int x : nums) {
            if (x == 0) continue;
            nums[pos++] = x;
        }

        while (pos < nums.size()) {
            nums[pos++] = 0;
        }
    }
       
};

int main() {
    vector<int> nums { 0,1,0,3,12 };
    Solution sol;
    sol.moveZeroes(nums);
    print(nums);  
}
