#include <unordered_map>
#include "utils.hpp"

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,size_t> seen;
    for (size_t i = 0; i < nums.size(); i++) {
        auto need = target - nums[i];
       
        if (auto it = seen.find(need); it != seen.end()) {
            return { 
                static_cast<int>(i), 
                static_cast<int>(it->second)
            };
        }
        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums { 2,7,11,15 };
    int target = 9;
    print(twoSum(nums, target));
}