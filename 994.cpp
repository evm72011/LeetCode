#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        vector<pair<int,int>> curr;

        auto rows = static_cast<int>(grid.size());
        auto cols = static_cast<int>(grid[0].size());        
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    curr.push_back({r, c});
                }
            }
        
        while (!curr.empty()) {
            auto tmp = getNext(grid, curr);
            curr = move(tmp);
            if (!curr.empty()) result++;
        }

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    return -1;
                }
            }
        return result;
    }
private:
    vector<pair<int,int>> getNext(vector<vector<int>>& grid, vector<pair<int,int>> curr) {
        vector<pair<int,int>> next;
        auto rows = static_cast<int>(grid.size());
        auto cols = static_cast<int>(grid[0].size());
        
        for (auto p: curr) {
            auto [r, c] = p;
            
            if (r > 0 && grid[r - 1][c] == 1) {
                next.push_back({ r - 1, c });
                grid[r - 1][c] = 2;
            }
            if (r < rows - 1 && grid[r + 1][c] == 1) {
                next.push_back({ r + 1, c });
                grid[r + 1][c] = 2;
            }
            if (c > 0 && grid[r][c - 1] == 1) {
                next.push_back({ r, c - 1 });
                grid[r][c - 1] = 2;
            }
            if (c < cols - 1 && grid[r][c + 1] == 1) {
                next.push_back({ r, c + 1 });
                grid[r][c + 1] = 2;
            }
        }
        return next;
    }
};

int main() {
    vector<vector<int>> grid {
        { 2,1,1 },
        { 0,1,1 },
        { 1,0,1 }
    };
    Solution sol;
    cout << sol.orangesRotting(grid) << '\n';
}