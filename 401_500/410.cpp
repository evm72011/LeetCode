#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for (auto x : nums) {
            l = max(l, x);
            r += x;
        }

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (splitsCount(nums, mid) <= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    int splitsCount(vector<int>& nums, int max_sum) {
        int sum = 0, res = 0;
        for (auto x : nums) {
            sum += x;
            if (sum == max_sum) {
                res++;
                sum = 0;
            }
            else if (sum > max_sum) {
                res++;
                sum = x;
            }
        }
        if (sum > 0) res++;
        return res;
    }
};

int main() {
    vector<int> nums { 1,2,3,4,5 }; ///
    Solution sol;

    cout << sol.splitArray(nums, 2) << '\n';
}