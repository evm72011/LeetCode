#include <stack>
#include "utils.hpp"


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> answer (temps.size());
        stack<int> st;

        auto size = static_cast<int>(temps.size());
        for (int i = 0; i < size; i++) {
            while (!st.empty() && temps[st.top()] < temps[i]) {
                int prev = st.top();
                answer[prev] = i - prev;
                st.pop();
            }

            st.push(i);
        }
        return answer;
    }
};

int main() {
    vector<int> temps { 73,74,75,71,69,72,76,73 };
    Solution sol;
    auto result = sol.dailyTemperatures(temps);
    print(result); 
}