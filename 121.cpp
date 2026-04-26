#include "utils.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0], best_profit = 0; 
        for (auto price : prices) {
            best_profit = max(best_profit, price - min_price);
            min_price = min(min_price, price);
        }
        return best_profit;
    }
};

int main() {
    vector<int> prices { 7,1,5,3,6,4 };
    Solution sol;
    auto result = sol.maxProfit(prices);
    cout << result << '\n';  
}
