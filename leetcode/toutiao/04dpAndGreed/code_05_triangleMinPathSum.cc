 //120 ��������С·����
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

//���䶯̬�滮
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }
        vector<vector<int>> dp(triangle.size() + 1, vector<int>(triangle.size() + 1, 0));
        for (int i = dp.size() - 2; i >= 0; --i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};

//perfect ����ѹ��
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
