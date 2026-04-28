#include "utils.hpp"

class NumArray {
public:
    NumArray(vector<int>& nums): prefix(nums.size() + 1, 0) {
        for (size_t i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
private:
    vector<int> prefix;
};

int main() {
    vector<int> nums { -2,0,3,-5,2,-1 };
    NumArray na(nums);
    cout << na.sumRange(0,2) << '\n';
    cout << na.sumRange(2,5) << '\n';
    cout << na.sumRange(0,5) << '\n';
}