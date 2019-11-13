//�������� + ����ջ
class Solution {
	struct Entry
	{
		int lMin;
		int rMin;
		Entry() = default;
		Entry(int l, int r)
			: lMin(l), rMin(r)
		{}
	};
public:
	int sumSubarrayMins(vector<int>& A) {
	    Entry lrMin[A.size()];
		stack<int> ids;
		// �ҵ�һ��Ԫ����߱���С��λ�� 
		// �ҵ�һ��Ԫ���ұ߱���С��λ�� for (int i = 0; i < A.size(); ++i)
		{
			while (!ids.empty() && A[i] <= A[ids.top()])
			{
				int cur = ids.top();
				ids.pop();
				lrMin[cur] = Entry(ids.empty() ? -1 : ids.top(), i);
			}
			ids.push(i);
		}
		while (!ids.empty())
		{
			int cur = ids.top();
			ids.pop();
			lrMin[cur] = Entry(ids.empty() ? -1 : ids.top(), A.size());
		}
		long long sum = 0;
		for (int i = 0; i < A.size(); ++i)
		{
            sum += (i - lrMin[i].lMin) * (lrMin[i].rMin - i) * A[i];            
		}
		return sum % 1000000007;
	}
};