#include <stack>
#include <unordered_map>
#include "utils.hpp"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> next_greater;

        for (int x : nums2) {
            while (!st.empty() && st.top() < x) {
                next_greater[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        vector<int> answ(nums1.size(), -1);
        auto size = static_cast<int>(nums1.size());
        for (int i = 0; i < size; i++) {
            answ[i] = next_greater[nums1[i]];
        }
        return answ;
    }
};

int main() {
    vector<int> nums1 { 4,1,2 };
    vector<int> nums2 { 1,3,4,2 };

    Solution sol;
    auto result = sol.nextGreaterElement(nums1, nums2);
    print(result);
}
