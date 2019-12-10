vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int> > q;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
                q.push({ i, j }); //Put all 0s in the queue.
            }

    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
            if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                    dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                    q.push({ new_r, new_c });
                }
            }
        }
    }
    return dist;
}

//方法 2：广度优先搜索
//想法
//一种更好的暴力：
//搜寻整个矩阵太过于浪费，因此我们使用广度优先搜索去限制搜索空间。
//只要 0 出现在广度优先搜索时，我们就知道这个 0 是最近的。因此，只需要考虑下一个 1。
//再次考虑：
//但在这种方法中，我们只能够更新一个 1 的距离，这可能在某种程度上，更大程度提高方法 1 的复杂度。
//但是，如果我们从 0 开始广度优先搜索并且更新路径上所有的 1，这会优化我们的算法。
//算法
//对于广度优先搜索，保存一个队列 q 维护下一个需要检查的点。
//我们将所有的 0 放入 q 中。
//初始地，对于每个为 0 的节点距离都是 1，对于所有的 1 都是 INT_MAX，会根据广搜的结果更新。
//弹出队列中的元素，检查它的邻居。
//如果对于邻居 {i,j} 新计算的距离更小，将 {i,j} 加入队列 q 中同时更新距离 dist[i][j]。