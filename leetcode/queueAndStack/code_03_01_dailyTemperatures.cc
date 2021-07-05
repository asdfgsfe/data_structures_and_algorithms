//每日温度

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		if (T.empty())
		{
			return {};
		}
		//单调栈 右边第一个比他大的 需要单调递减的栈
		stack<int> dates;
		vector<int> diffs(T.size(), 0);
		int p = 0;
		for (int i = 0; i < T.size(); ++i)
		{
			//while 中一定是弹出 连续的弹出 而且一般记录的是id
			while (!dates.empty() && T[dates.top()] < T[i])
			{
				int pre = dates.top();
				dates.pop();
				diffs[pre] = i - pre;
			}
			dates.push(i);
		}
		return diffs;
	}
};
