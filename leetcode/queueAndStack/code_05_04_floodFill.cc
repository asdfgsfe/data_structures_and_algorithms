class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty() || image[0].empty() || sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
		{
			return {};
		}
		vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), false));
		FillProcess(image, sr, sc, newColor, image[sr][sc], visited);
		return image;
	}

	void FillProcess(vector<vector<int>>& image, int r, int c, int newColor, int preColor, vector<vector<int>>& visited)
	{
		if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || visited[r][c] || image[r][c] != preColor)
		{
			return;
		}
		visited[r][c] = true;
		image[r][c] = newColor;
		FillProcess(image, r + 1, c, newColor, preColor, visited);
		FillProcess(image, r, c + 1, newColor, preColor, visited);
		FillProcess(image, r - 1, c, newColor, preColor, visited);
		FillProcess(image, r, c - 1, newColor, preColor, visited);
	}
};