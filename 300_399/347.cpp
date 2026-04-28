#include <unordered_map>
#include <queue>
#include "utils.hpp"


struct PairComparer {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        return a.second > b.second;
    }    
};

class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        result.reserve(k);

        unordered_map<int,int> freqs;
        for (const auto& num: nums) {
            freqs[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, PairComparer> pq;
        auto size = static_cast<size_t>(k);
        for (const auto& [val, freq]: freqs) {
            pq.push({ val, freq });
            if (pq.size() > size) pq.pop();
        }

        while (!pq.empty()) {
            auto [val, freq] = pq.top();
            pq.pop();
            result.push_back(val);
        }
        return result;
    }
};

int main() {
    vector<int> nums { 1,1,1,2,2,3 };
    Solution sol;
    auto res = sol.topKFrequent(nums, 2);
    print(res);
}
