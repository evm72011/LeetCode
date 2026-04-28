#include <iostream>

const int BAD = 1;

bool isBadVersion(int n) {
    return BAD <= n;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};

int main() {
    auto n = 2;

    Solution sol;
    std::cout << sol.firstBadVersion(n) << '\n';
}