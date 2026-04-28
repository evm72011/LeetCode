#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        auto max_size = static_cast<size_t>(k);

        for (int x : nums) {
            pq.push(x);
            if (pq.size() > max_size) pq.pop();
        }
        return pq.top();
    }
};

int main() {
    vector<int> nums { 3,2,1,5,6,4 };
    Solution sol;
    cout << sol.findKthLargest(nums, 2) << '\n'; 
}