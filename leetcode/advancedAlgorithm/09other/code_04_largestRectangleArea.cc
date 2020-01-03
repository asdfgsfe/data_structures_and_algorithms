class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
        {
            return 0;
        }
        stack<int> increase;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!increase.empty() && heights[increase.top()] >= heights[i])
            {
                int m = increase.top();
                increase.pop();
                maxArea = std::max(maxArea, (i - (increase.empty() ? -1 : increase.top()) - 1) * heights[m]);
            }
            increase.push(i);
        }
        while (!increase.empty())
        {
            int m = increase.top();
            increase.pop();
            maxArea = std::max(maxArea, ((int)heights.size() - (increase.empty() ? -1 : increase.top()) - 1) * heights[m]);
        }
        return maxArea;
    }
};

//单调栈 左边第一个比他小的 右边第一个比他小的 单调递增的栈