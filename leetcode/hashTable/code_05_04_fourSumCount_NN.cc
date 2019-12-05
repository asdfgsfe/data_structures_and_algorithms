class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		if (A.empty() || B.empty() || C.empty() || D.empty())
		{
			return 0;
		}
		if (A.size() != B.size() || B.size() != C.size() || C.size() != D.size())
		{
			return 0;
		}
		unordered_map<long long, int> sumToTimes = TwoSum(A, B);
		int cnt = 0;
		for (int i = 0; i < C.size(); ++i)
		{
			for (int j = 0; j < D.size(); ++j)
			{
				int sum = C[i] + D[j];
                auto times = sumToTimes.find(-sum);
				if (times != sumToTimes.end())
				{
					cnt += times->second;
				}
			}
		}
		return cnt;
	}

	unordered_map<long long, int> TwoSum(const vector<int>& a, const vector<int>& b)
	{
		unordered_map<long long, int> sumToTimes;
		for (int i = 0; i < a.size(); ++i)
		{
			for (int j = 0; j < b.size(); ++j)
			{
				++sumToTimes[a[i] + b[j]];;
			}
		}
		return sumToTimes;
	}
};