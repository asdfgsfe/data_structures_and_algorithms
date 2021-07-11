class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int num = 0 ;
        queue<pair<int, int>> nodes;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != '1') {
                    continue;
                }
                ++num;
                grid[i][j] = '2';
                nodes.emplace(i, j);
                while (!nodes.empty()) {
                    pair<int, int> cur = nodes.front();
                    nodes.pop();
                    //grid[cur.first][cur.second] = '2';
                    if (cur.first > 0 && grid[cur.first - 1][cur.second] == '1') {
                        nodes.emplace(cur.first - 1, cur.second);
                        grid[cur.first - 1][cur.second] = '2';
                    }
                    if (cur.first < grid.size() - 1 && grid[cur.first + 1][cur.second] == '1') {
                        nodes.emplace(cur.first + 1, cur.second);
                        grid[cur.first + 1][cur.second] = '2';
                    }
                    if (cur.second > 0 && grid[cur.first][cur.second - 1] == '1') {
                        nodes.emplace(cur.first, cur.second - 1);
                        grid[cur.first][cur.second - 1] = '2';
                    }
                    if (cur.second + 1 < grid[0].size() && grid[cur.first][cur.second + 1] == '1') {
                        nodes.emplace(cur.first, cur.second + 1);
                        grid[cur.first][cur.second + 1] = '2';
                    }
                }
            }
        }
        return num;
    }
};
