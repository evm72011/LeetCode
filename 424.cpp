#include <string>
#include <array>
#include <iostream>


using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int,26> freq{};
        int best = 0, l = 0;

        for (int r = 0; r < s.size(); ++r) {
            freq[s[r] - 'A']++;

            int max_freq = 0;
            for (int x : freq) {
                max_freq = max(max_freq, x);
            }

            int win_size = r - l + 1;

            if (win_size - max_freq <= k) {
                best = max(best, win_size);
            } else {
                freq[s[l] - 'A']--;
                l++;
            }
        }

        return best;
    }
};
 
int main() {
    string s = "ABAB";
    Solution sol;
    cout << sol.characterReplacement(s, 2) << '\n';
}