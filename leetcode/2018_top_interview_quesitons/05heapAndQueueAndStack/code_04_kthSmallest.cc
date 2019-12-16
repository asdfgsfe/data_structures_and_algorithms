 class Solution {
 public:
	 int kthSmallest(vector<vector<int>>& matrix, int k) {
		 if (matrix.empty() || matrix[0].empty() || k > matrix.size() * matrix[0].size())
		 {
			 return 0x80000000;
		 }
		 vector<int> topk;
		 for (int i = 0; i < matrix.size(); ++i)
		 {
			 for (int j = 0; j < matrix[0].size(); ++j)
			 {
				if (topk.size() < k)
				{
					topk.push_back(matrix[i][j]);
					std::push_heap(topk.begin(), topk.end(), std::less<int>());
					continue;
				}
				if (matrix[i][j] > topk.front())
				{
					break;
				}
				if (matrix[i][j] < topk.front())
				{
					std::pop_heap(topk.begin(), topk.end(), std::less<int>());
					topk.back() = matrix[i][j];
					std::push_heap(topk.begin(), topk.end(), std::less<int>());
				}
			 }
		 }
		 return topk.front();
	 }
 };