#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (char c : num) {
            while (!st.empty() && st.top() > c && k > 0) {
                k--;
                st.pop();
            }
            st.push(c);
        }

        while (k > 0) {
            st.pop();
            k--;
        }

        string result(st.size(), '0');
        while (!st.empty()) {
            result[st.size() - 1] = st.top();
            st.pop();
        }
        return removeLeadingZeros(result);
    }
private:
    string removeLeadingZeros(string str) {
        int i = 0;
        while (i < str.size() && str[i] == '0') {
            ++i;
        }

        string result = str.substr(i);
        return result.empty() ? "0" : result;
    }
};

int main() {
    string num = "10200";
    Solution sol;
    cout << sol.removeKdigits(num, 1) << '\n';
}