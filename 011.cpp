#include "utils.hpp"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int best = 0;
        int l = 0, r = static_cast<int>(height.size()) - 1;
        while (l < r) {
            int curr = (r - l) * min(height[l], height[r]);
            best = max(best, curr);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return best;
    }
};

int main() {
    vector<int> height { 1,8,6,2,5,4,8,3,7 };
    Solution solution;
    auto result = solution.maxArea(height);
    cout << result << '\n';
}