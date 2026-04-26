#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        for (int course = 0; course < numCourses; course++) {
            unordered_set<int> visited { course };
            if (!dfs(course, graph, visited)) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(int node, vector<vector<int>>& graph, unordered_set<int>& visited) {
        for (int prereq : graph[node]) {
            if (visited.count(prereq)) return false;
            visited.insert(prereq);

            if (!dfs(prereq, graph, visited)) return false;
        }
        graph[node].clear();
        return true;
    }
};

int main() {
    // not solved
    int numCourses = 3;
    vector<vector<int>> prerequisites { {0,1}, {0,2}, {1,2} };
    Solution sol;
    cout << boolalpha << sol.canFinish(numCourses, prerequisites) << '\n';
}
