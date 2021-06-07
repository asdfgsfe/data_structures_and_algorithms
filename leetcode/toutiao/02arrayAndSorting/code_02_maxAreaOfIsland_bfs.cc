//答案多一个不知道是哪里的问题
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }
                int area = 0;
                queue<pair<int, int>> paths;
                paths.emplace(pair<int, int>{i, j});
                while (!paths.empty()) {
                    pair<int, int> cur = paths.front();
                    paths.pop();
                    grid[cur.first][cur.second] = 2;
                    ++area;
                    if (cur.first + 1 < grid.size() && grid[cur.first + 1][cur.second] == 1) {
                        paths.emplace(pair<int, int>{cur.first + 1, cur.second});
                    }
                    if (cur.first - 1 >= 0 && grid[cur.first - 1][cur.second] == 1) {
                        paths.emplace(pair<int, int> {cur.first - 1, cur.second});
                    }
                    if (cur.second + 1 < grid[0].size() && grid[cur.first][cur.second + 1] == 1) {
                        paths.emplace(pair<int, int> {cur.first, cur.second + 1});
                    }
                    if (cur.second - 1 >= 0 && grid[cur.first][cur.second - 1] == 1) {
                        paths.emplace(pair<int, int>{cur.first, cur.second - 1});
                    }
                }
                maxArea = std::max(maxArea, area);
            }
        }
        return maxArea;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                int cur = 0;
                queue<int> queuei;
                queue<int> queuej;
                queuei.push(i);
                queuej.push(j);
                while (!queuei.empty()) {
                    int cur_i = queuei.front(), cur_j = queuej.front();
                    queuei.pop();
                    queuej.pop();
                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
                        continue;
                    }
                    ++cur;
                    grid[cur_i][cur_j] = 0;
                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        queuei.push(next_i);
                        queuej.push(next_j);
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/max-area-of-island/solution/dao-yu-de-zui-da-mian-ji-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
