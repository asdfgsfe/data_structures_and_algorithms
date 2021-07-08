//贪心二分答案的方法
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
	//大于等于m个 向左边走
    bool MGTKNum(const vector<vector<int>>& matrix, int m, int k) {
        int r = matrix.size() - 1;
        int c = 0;
        int num = 0;
        while (r >= 0 && c < matrix[0].size()) {
            if (matrix[r][c] <= m) {
                num += r + 1; //如果当前小于 那么则会一列全部小于
                ++c;
            } else {
                --r;
            }
        }
        return num >= k;
    }
};
