class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k < 1)
        {
			return {};
        }
		if (k > nums.size())
		{
			return nums;
		}
		deque<int> window(k);
		for (int i = 0; i < k; ++i)
		{
			while (!window.empty() && nums[i] >= nums[window.back()])
			{
				window.pop_back();
			}
			window.push_back(i);
		}
		vector<int> maxNums;
		for (int i = k; i < nums.size(); ++i)
		{
			assert(!window.empty());
			maxNums.emplace_back(nums[window.front()]);
			while (!window.empty() && nums[i] >= nums[window.back()])
			{
				window.pop_back();
			}
			window.push_back(i);
			if (i - window.front() >= k) //大于等于是应为i - j 之间有i - j + 1个数字
			{
				window.pop_front();
			}
		}
        maxNums.emplace_back(nums[window.front()]); //容易丢掉最后一个窗口
		return maxNums;
    }
};