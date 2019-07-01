 ��������С·����
����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�

���磬���������Σ�

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
�Զ����µ���С·����Ϊ 11������2 + 3 + 5 + 1 = 11����

˵����

��������ֻʹ�� O(n) �Ķ���ռ䣨n Ϊ�����ε��������������������⣬��ô����㷨��ܼӷ֡�

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
        {
            return 0;
        }
        return SumProcess(triangle, 0, 0);
    }
    
    int SumProcess(const vector<vector<int>>& triangle, int i, int j)
    {
        if (i == triangle.size() || j == triangle[i].size())
        {
            return 0;
        }
        return triangle[i][j] + std::min(SumProcess(triangle, i + 1, j), SumProcess(triangle, i + 1, j + 1));
    }
};


//perfect
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
        {
            return 0;
        }
        vector<int> dp = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};