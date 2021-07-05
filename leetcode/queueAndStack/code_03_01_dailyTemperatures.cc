//ÿ���¶�

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		if (T.empty())
		{
			return {};
		}
		//����ջ �ұߵ�һ��������� ��Ҫ�����ݼ���ջ
		stack<int> dates;
		vector<int> diffs(T.size(), 0);
		int p = 0;
		for (int i = 0; i < T.size(); ++i)
		{
			//while ��һ���ǵ��� �����ĵ��� ����һ���¼����id
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
