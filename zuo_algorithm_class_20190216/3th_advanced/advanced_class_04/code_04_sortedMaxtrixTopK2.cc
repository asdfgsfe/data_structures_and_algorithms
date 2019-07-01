vector<int> MatrixTopK(const vector<vector<int>>& matrix, int k)
{
	if (matrix.empty() || maxtirx[0].empty())
	{
		return vector<int>();
	}
	vector<vector<int>> candicate(n, vector<int>(2));
	for (int i = 0; i < n; ++i)
	{
		candicate.emplace_back({i, matrix[i].size() - 1});
		std::push_heap(candicate.begin(), candicate.end(), 
			[&matrix](const vector<int>& lhs, const vector<int>& rhs) ->bool
			{
				return maxtirx[lhs[0]][lhs[1]] < matrix[rhs[0][rhs[1]];
			});
	}
	vector<int> topK(k);
	for (int i = 0; i < k && !candicate.empty(); ++i)
	{
		int row = candicate.front().front();
		int col = candicate.front().back();
		topk.emplace_back(matrix[row][col]);
		std::swap(candicate.front(), candicate.back());
		if (col == 0)
		{
			candicate.pop_back();
		}
		else
		{
			--candicate.back().back();
		}
		std::push_heap(candicate.begin(), candicate.end(), 
			[&matrix](const vector<int>& lhs, const vector<int>& rhs) ->bool
			{
				return maxtirx[lhs[0]][lhs[1]] < matrix[rhs[0][rhs[1]];
			});
	}
	return topk;
}