class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex < 1)
		{
			return {1};
		}
		vector<int> row(rowIndex + 1);
		row[0] = 1;
		for (int i = 1; i <= rowIndex; ++i)
		{
			row[i] = 1;
			int pre = row[0];
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