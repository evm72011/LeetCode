#include <queue>
#include "utils.hpp"

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        auto target = image[sr][sc];
        if (target == color) return image;

        queue<pair<int,int>> q;
        q.push({ sr, sc });

        auto rows = static_cast<int>(image.size());
        auto cols = static_cast<int>(image[0].size());

        while (!q.empty()) {
            auto [ r, c ] = q.front(); q.pop();
            if (image[r][c] != target) continue;
            image[r][c] = color;

            if (r > 0) q.push({ r - 1, c });
            if (r < rows - 1) q.push({ r + 1, c });
            if (c > 0) q.push({ r, c - 1 });
            if (c < cols - 1) q.push({ r, c + 1 });
        }
        return image;
    }
};

int main() {
    vector<vector<int>> image {{1,1,1}, {1,1,0}, {1,0,1}};
    Solution sol;
    auto res = sol.floodFill(image, 1, 1, 2);
    print(res);
}
