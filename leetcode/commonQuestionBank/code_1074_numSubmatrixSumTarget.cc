class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int cnt = 0;
        //以每一行为底边 遍历矩阵
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> sum(matrix[0].size(), 0);
            //从下一行开始 j=i很关键
            for (int j = i; j < matrix.size();++j) {
                for (int k = 0; k < matrix[0].size(); ++k) {
                    sum[k] += matrix[j][k];
                }
                cnt += SubArraySumTarget(sum, target);
            }
        }
        return cnt;
    }

    //字数组中累积加和为t的字数组数量
    int SubArraySumTarget(const vector<int>& nums, int t) {
        if (nums.empty()) {
            return 0;
        }
        unordered_map<int, int> sums;
        sums[0] = 1;
        int pre = 0;
        int cnt = 0;
        for (int n : nums) {
            pre += n;
            auto it = sums.find(pre - t);
            if (it != sums.end()) {
                cnt += it->second;
            }
            ++sums[pre];
        }
        return cnt;
    }
};


1074. 元素和为目标值的子矩阵数量
给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。

子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。

如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），那么这两个子矩阵也不同。



示例 1：



输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
输出：4
解释：四个只含 0 的 1x1 子矩阵。
示例 2：

输入：matrix = [[1,-1],[-1,1]], target = 0
输出：5
解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
示例 3：

输入：matrix = [[904]], target = 0
输出：0


提示：

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
通过次数11,020提交次数17,357
