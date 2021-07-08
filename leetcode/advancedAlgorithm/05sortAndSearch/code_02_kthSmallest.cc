有序矩阵中第K小的元素
给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。

 

示例 1：

输入：matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
输出：13
解释：矩阵中的元素为 [1,5,9,10,11,12,13,13,15]，第 8 小元素是 13
示例 2：

输入：matrix = [[-5]], k = 1
输出：-5
 

提示：

n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
题目数据 保证 matrix 中的所有行和列都按 非递减顺序 排列
1 <= k <= n2
相关标签
数组
二分查找
矩阵
排序
堆（优先队列）

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xdnjqd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty() || k < 1 || k > matrix.size() * matrix.size()) {
            return 0x80000000;
        }
        vector<int> topk;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (topk.size() < k) {
                    topk.push_back(matrix[i][j]);
                    HeapInsert(topk, topk.size() - 1);
                    continue;
                }
                if (matrix[i][j] >= topk[0]) {
                    break;
                }
                topk[0] = matrix[i][j];
                Percdown(topk, 0, topk.size());
            }
        }
        return topk[0];
    }

    void Percdown(vector<int>& topk, int i, int n) {
        int child = 2 * i + 1;
        while (child < n) {
            if (child + 1 != n && topk[child + 1] > topk[child]) {
                ++child;
            }
            if (topk[child] <= topk[i]) {
                return;
            }
            std::swap(topk[child], topk[i]);
            i = child;
            child = 2 * i + 1;
        }
    }

    void HeapInsert(vector<int>& topk, int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (topk[p] >= topk[i]) {
                return;
            }
            std::swap(topk[p], topk[i]);
            i = p;
        }
    }
};
