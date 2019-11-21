class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
		if (A.empty())
		{
			return 0;
		}
		long long minSum = 0;
		//��ÿ��λ�ÿ�ͷ���������������Сֵ ��������������Сֵ��� ���Ǵ� N*N
		for (int i = 0; i < A.size(); ++i)
		{
			int minVal = A[i];
			for (int j = i; j < A.size(); ++j)
			{
				minVal = std::min(minVal, A[j]);
				minSum += minVal;
			}
		}
		return minSum % 1000000007;
    }
};