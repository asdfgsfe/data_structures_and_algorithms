��ͬ·��
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����

������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������

���ܹ��ж�������ͬ��·����



���磬��ͼ��һ��7 x 3 �������ж��ٿ��ܵ�·����

˵����m �� n ��ֵ�������� 100��

ʾ�� 1:

����: m = 3, n = 2
���: 3
����:
�����Ͻǿ�ʼ���ܹ��� 3 ��·�����Ե������½ǡ�
1. ���� -> ���� -> ����
2. ���� -> ���� -> ����
3. ���� -> ���� -> ����
ʾ�� 2:

����: m = 7, n = 3
���: 28

//dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            dp[i][n - 1] = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            dp[m - 1][i] = 1;
        }
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};

//recursion
class Solution {
public:
    int uniquePaths(int m, int n) {
        return WalkProcess(0, 0, m, n);
    }
    
    int WalkProcess(int i, int j, int m, int n)
	{
		if (i >= m - 1 || j >= n - 1)
		{
			return 0;
		}
		return WalkProcess(i + 1, j, m, n) + WalkProcess(i, j + 1, m, n) + 1;
	}
};