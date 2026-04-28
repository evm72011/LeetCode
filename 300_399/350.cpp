#include <unordered_map>
#include "utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        unordered_map<int,int> mp;
        for (const auto& x : nums1) {
            mp[x]++;
        }

        for (const auto& x : nums2) {
            if (auto it = mp.find(x); it != mp.end() && it->second > 0) {
                it->second--;
                result.push_back(x);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = { 1,2,2,1 };
    vector<int> nums2 = { 2,2 };

    Solution sol;
    auto result = sol.intersect(nums1, nums2);
    print(result);
}
