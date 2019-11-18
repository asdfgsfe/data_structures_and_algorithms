class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
		if (A.empty())
		{
			return 0;
		}
		long long minSum = 0;
		//以每个位置开头的情况下子数组最小值 将所有子数组最小值相加 就是答案 N*N
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