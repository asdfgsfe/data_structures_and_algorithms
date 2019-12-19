 class Solution {
 public:
	 int maxSideLength(vector<vector<int>>& mat, int threshold) {
		 if (mat.empty() || mat[0].empty())
		 {
			 return 0;
		 }
		 //���ռ����ۼӺͼ�������ظ��ķ���
		 vector<vector<int>> sums(mat.size(), vector<int>(mat[0].size(), 0));
		 sums[0][0] = mat[0][0];
		 for (int i = 0; i < mat.size(); ++i)
		 {
			 for (int j = 0; j < mat[0].size(); ++j)
			 {
				 sums[i][j] = mat[i][j] + (i > 0 ? sums[i - 1][j] : 0) + (j > 0 ? sums[i][j - 1] : 0);
				 sums[i][j] -= i > 0 && j > 0 ? sums[i - 1][j - 1] : 0;
			 }
		 }
		 //���ռ���ĳ���������ķ���
		 int maxSize = min(mat.size(), mat[0].size());
		 for (int b = maxSize; b > 0; --b)
		 {
			 for (int i = 0; i + b <= mat.size(); ++i)
			 {
				 for (int j = 0; j + b <= mat[0].size(); ++j)
				 {
					 int sum = sums[i + b - 1][j + b - 1];
					 if (j > 0)
					 {
						 sum -= sums[i + b - 1][j - 1];
					 }
					 if (i > 0)
					 {
						 sum -= sums[i - 1][j + b - 1];
					 }
					 if (i > 0 && j > 0)
					 {
						 sum += sums[i - 1][j - 1];
					 }
					 if (sum <= threshold)
					 {
						 return b;
					 }
				 }
			 }
		 }
		 return 0;
	 }
 };