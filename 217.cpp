#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (const auto& i : nums) {
            if (!st.insert(i).second) return true;
        }
        return false;
    }
};

int main() {
    vector<int> data { 1,2,3,1 };

    Solution sol;
    auto result = sol.containsDuplicate(data);
    cout << boolalpha << result << '\n';
}