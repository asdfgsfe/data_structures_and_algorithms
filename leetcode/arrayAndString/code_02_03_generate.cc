class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows < 1)
		{
			return {};
		}
		vector<vector<int>> rows;
		rows.emplace_back(vector<int>(1, 1));
		for (int i = 1; i < numRows; ++i)
		{
			vector<int> row(i + 1);
			row[0] = 1;
			row[i] = 1;
			for (int j = 1; j < row.size() - 1; ++j)
			{
				row[j] = rows[i - 1][j - 1] + rows[i - 1][j];
			}
			rows.emplace_back(std::move(row));
		}
		return rows;
	}
};