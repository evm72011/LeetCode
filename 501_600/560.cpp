#include <unordered_map>
#include "utils.hpp"


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> st;
        st[0] = 1;
        int result = 0;
        
        int sum = 0;
        for (int x : nums) {
            sum += x;
            int need = sum - k;
            //if (st.count(need)) {
            //    result += st[need];
            //}

            auto it = st.find(need);
                if (it != st.end()) {
                result += it->second;
            }

            st[sum]++;
        }
        return result;
    }
};

int main() {
    vector<int> nums { 1,2,3 };
    int k = 3;

    Solution sol;
    cout << sol.subarraySum(nums, k) << '\n';
}