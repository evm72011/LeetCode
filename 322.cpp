#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (mp.count(amount)) return mp[amount];

        int result = INT_MAX;

        for (int coin : coins) {
            int sub = coinChange(coins, amount - coin);

            if (sub == -1) continue;

            result = min(result, sub + 1);
        }

        mp[amount] = (result == INT_MAX ? -1 : result);
        return mp[amount];
    }

private:
    unordered_map<int,int> mp;
};

class Solution_ {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int coin : coins) {
            auto target = amount - coin;
            
            auto result = coinChange(coins, target);
            if (result < 0) continue;
            pq.push(1 + result);
        }    

        return pq.size() > 0 ? pq.top() : -1;
    }
};

int main() {
    vector<int> coins { 1, 2, 5 }; 
    int amount = 11;
    Solution sol;
    cout << sol.coinChange(coins, amount) << '\n';
}