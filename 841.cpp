#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);

        dfs(0, rooms, visited);

        return all_of(
            visited.begin(),
            visited.end(),
            [](bool x) { return x; }
        ); 
    }

    bool canVisitAllRoomsIt(vector<vector<int>>& rooms) {
        stack<int> st;
        vector<bool> visited(rooms.size(), false);

        st.push(0);
        while (!st.empty()) {
            int curr = st.top(); st.pop();
            
            if (visited[curr]) continue;
            visited[curr] = true;

            for (auto r : rooms[curr]) {
                st.push(r);
            }
        }    
        
        return all_of(
            visited.begin(),
            visited.end(),
            [](bool x) { return x; }
        ); 
    }

private:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        if (visited[room]) return;
        visited[room] = true;

        for (auto key: rooms[room]) {
            dfs(key, rooms, visited);
        };
    };
};

int main() {
    vector<vector<int>> rooms { {1},{2},{3},{} };
    Solution sol;
    cout << boolalpha << sol.canVisitAllRooms(rooms) << '\n';
    cout << boolalpha << sol.canVisitAllRoomsIt(rooms) << '\n';
}
