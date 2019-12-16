class Solution {
private:
    struct node {
        int x, y;
        int t;
        int hp;
        node(int a, int b, int c, int _t) : x(a), y(b), hp(c), t(_t) {}
    };
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        bool vis[m][n][k + 1] = {};
        queue <node> q;
        vis[0][0][k] = 1;
        q.push(node(0, 0, k, 0));
        while(!q.empty()) {
            node u = q.front();
            q.pop();
            if (u.x == m - 1 && u.y == n - 1) {
                return u.t;
            }
            for (int i = 0; i < 4; i++) {
                int tx = u.x + dx[i], ty = u.y + dy[i];
                if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
                    if (!vis[tx][ty][u.hp]) {
                        if (grid[tx][ty] != 1) {
                            q.push(node(tx, ty, u.hp, u.t + 1));
                            vis[tx][ty][u.hp] = 1;
                        }
                        else if (grid[tx][ty] == 1 && u.hp > 0) {
                            q.push(node(tx, ty, u.hp - 1, u.t + 1));
                            vis[tx][ty][u.hp] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

作者：baker221
链接：https://leetcode-cn.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/solution/cbfs-by-baker221/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。