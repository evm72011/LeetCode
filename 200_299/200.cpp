#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        auto result = 0;
        auto rows = static_cast<int>(grid.size());
        auto cols = static_cast<int>(grid[0].size());
        
        for (int r = 0; r < rows; r++ )
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '0') continue;
                result ++;
                visitIsland(r, c, grid);
            }
        return result;
    }
private:
    void visitIsland(int row, int col, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({ row, col });

        auto rows = static_cast<int>(grid.size());
        auto cols = static_cast<int>(grid[0].size());

        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            if (grid[r][c] == '0') continue;
            grid[r][c] = '0';

            if (r > 0 && grid[r - 1][c] == '1') q.push({ r - 1, c });
            if (r < rows - 1 && grid[r + 1][c] == '1') q.push({ r + 1, c });
            if (c > 0 && grid[r][c - 1] == '1') q.push({ r, c - 1 });
            if (c < cols - 1 && grid[r][c + 1] == '1') q.push({ r, c + 1 });
        }
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution sol;
    cout << sol.numIslands(grid) << '\n';
}
