class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() < 2)
		{
			return 0;
		}
		int area = 0;
		for (int i = 0; i < height.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				area = std::max(area, std::min(height[i], height[j]) * (i - j));
			}
		}
		return area;
	}
};