#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 0) return 0;
        if (mp.count(n)) return mp[n];

        int n_1 = climbStairs(n - 1);
        int n_2 = climbStairs(n - 2);
        return mp[n] = n_1 + n_2;
    }
private:
    unordered_map<int,int> mp {{1,1}, {2,2}};
};

int main() {
    Solution sol;
    cout << sol.climbStairs(3) << '\n';
}
