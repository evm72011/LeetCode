#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);

        dp[0] = 0;

        for (int a = 1; a <= amount; ++a) {
            for (int coin : coins) {
                if (coin <= a) {
                    dp[a] = min(dp[a], dp[a - coin] + 1);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins { 1, 2, 5 }; 
    int amount = 11;
    Solution sol;
    cout << sol.coinChange(coins, amount) << '\n';
}
