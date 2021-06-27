class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if (A.empty() || B.empty() || C.empty() || D.empty())
        {
			return 0;
        }
		//这个条件完全可以不用
		if (A.size() != B.size() || B.size() != C.size() || C.size() != D.size())
		{
			return 0;
		}
		int cnt = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			for (int j = 0; j < B.size(); ++j)
			{
				for (int k = 0; k < C.size(); ++k)
				{
					for (int l = 0; l < D.size(); ++l)
					{
						if (A[i] + B[j] + C[k] + D[l] == 0)
						{
							++cnt;
						}
					}
				}
			}
		}
		return cnt;
    }
};
