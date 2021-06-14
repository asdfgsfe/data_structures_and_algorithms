对角线遍历
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

 

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/cuxq3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
		{
			return {};
		}
		int m = matrix.size() - 1;
		int n = matrix[0].size() - 1;
		int dR = 0;
		int dC = 0;
		int tR = 0;
		int tC = 0;
		bool fromUp = true;
		vector<int> nums;
		while (dR <= m && dC <= n)
		{
			//std::cout << dR << " " << dC << " " << tR << " " << tC << std::endl;
			PrintEdge(matrix, dR, dC, tR, tC, fromUp, nums);
			dC = dR == m ? dC + 1 : dC;
			dR = dR == m ? dR : dR + 1;
			tR = tC == n ? tR + 1 : tR;
			tC = tC == n ? tC : tC + 1;
			fromUp = !fromUp;
		}
		return nums;
	}

	void PrintEdge(const vector<vector<int>>& m, int dR, int dC, int tR, int tC, bool fromUp, vector<int>& nums)
	{
		if (fromUp)
		{
			while (dR >= tR && dC <= tC)
			{
				nums.emplace_back(m[dR--][dC++]);
			}
		}
		else
		{
			while (tR <= dR && tC >= dC)
			{
				nums.emplace_back(m[tR++][tC--]);
			}
		}
	}
};
