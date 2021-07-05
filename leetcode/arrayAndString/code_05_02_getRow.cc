杨辉三角 II
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/ctyt1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return {};
        }
        vector<int> row(rowIndex + 1, 1); //初始化操作
        for (int i = 0; i < row.size(); ++i) {
			//直接跳过 第一个和最后一个数字 从后往前遍历
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j - 1] + row[j];
            }
        }
        return row;
    }
};



class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex < 1)
		{
			return {1};
		}
		vector<int> row(rowIndex + 1);
		row[0] = 1; //可以不用这些初始化步骤
		for (int i = 1; i <= rowIndex; ++i)
		{
			row[i] = 1;
			int pre = row[0]; //把row[j -1] 记录下来 如果从后往前遍历 就没有这个问题了 见上面代码
			for (int j = 1; j < i; ++j)
			{
				int cur = row[j];
				row[j] = row[j] + pre;
				pre = cur;
			}
		}
		return row;
	}
};
