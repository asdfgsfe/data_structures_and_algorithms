朋友圈
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。

 

示例 1：


输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2
示例 2：


输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
输出：3
 

提示：

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] 为 1 或 0
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
相关标签
深度优先搜索
广度优先搜索
并查集
图


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xdxc56/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty() || isConnected[0].empty()) {
            return 0;
        }
        vector<int> unionSet(isConnected.size());
        for (int i = 0; i < unionSet.size(); ++i) {
            unionSet[i] = i;
        }
        int cnt = isConnected.size();
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = i + 1; j < isConnected.size(); ++j) {
                if (isConnected[i][j] == 0) {
                    continue;
                }
                int fi = GetFather(unionSet, i);
                int fj = GetFather(unionSet, j);
                if (fi != fj) {
					//这里很关键 一定是把fj挂到fi下面 而不是i=fj 要把两个集合合并
                    unionSet[fi] = fj;
                    --cnt;
                }
            }
        }
        return cnt;
    }

    int GetFather(vector<int>& unionSet, int child) {
        int father = child;
        while (father != unionSet[father]) {
            father = unionSet[father];
        }
        unionSet[child] = father;
        return father;
    }
};
