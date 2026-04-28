#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> close_open {
            {')','('},
            {']','['},
            {'}','{'}
        };
        stack<char> order;

        for (auto c : s) {
            auto it = close_open.find(c);
            auto is_open = it == close_open.end();
            if (is_open) {
                order.push(c);
            } else {
                if (order.empty() || order.top() != it->second) return false;
                order.pop();
            }
        }

        return order.empty();
    }
};

int main() {
    Solution sol;
    cout << boolalpha << sol.isValid("()[]{}") << '\n';
}