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


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xaicbc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-by-leetco/
//
//官方解释
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty() || k <= 0 || k > matrix.size() * matrix[0].size()) {
            return 0x80000000;
        }
        int l = matrix[0][0];
        int r = matrix.back().back();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (MGTKNum(matrix, m, k)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }

    //寻找小于m的数字有多少个， 如果恰好是k个， 那么就是答案
    //二分找出了m这个数字， 然后的策略就是判断这个数字是不是我想要的那个， 策略是：统计出数组中小于他的个数和k比较
    //因为不知道具体有多少个小于于，就只能从左下角或者右上角进行(m + n)的统计， 因次是排序的所以时间复杂度是线性
    //如果小于m的个数多余k，那么m肯定不是想要的答案， 要向小的方向走 大于则相反
    //二分答案 贪心的想法
    bool MGTKNum(const vector<vector<int>>& matrix, int m, int k) {
        int r = matrix.size() - 1;
        int c = 0;
        int num = 0;
        while (r >= 0 && c < matrix[0].size()) {
            if (matrix[r][c] <= m) {
                num += r + 1;
                ++c;
            } else {
                --r;
            }
        }
        return num >= k;
    }
};


