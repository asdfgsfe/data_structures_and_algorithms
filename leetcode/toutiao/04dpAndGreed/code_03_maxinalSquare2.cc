//�������� ֻ��������sum������ ���ž��Ǳ��˵Ĵ�
//��һ���� 0 �� 1 ��ɵĶ�ά�����ڣ��ҵ�ֻ���� 1 ����������Σ��������������

ʾ��:

����: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

���: 4

//�����ۼӺ��ж��ڲ�ȫ����1
//����һ�������м���ĳһ���ۼӺ���һ�� ��i��j���ۼӺ͵��� dp[j] - dp[i] dp[i]��ʾ��0��i���ۼӺ�
�������������һ����ά����͵ļ�������֮ǰ�ǵ���Range Sum Query - Immutable ����ͼ��������졣
����֮ǰ�ǵ���Ļ���������֪���������ʵҲ�ǻ�������ҩ������Ҫ����һ���ۼ�����͵����飬
Ȼ����ݱ߽�ֵ�ļӼ��������������������֮�͡���������ά��һ����ά����dp��
����dp[i][j]��ʾ�ۼ�����(0, 0)��(i, j)��������������е�����֮�ͣ�
��ô��ʱ���������Ҫ�������(r1, c1)��(r2, c2)�ľ�������ʱ��
ֻ��dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1]���ɣ�
����Ĵ����������������˸����к͸����У������±����Щ�仯���μ��������£�
class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) 
	{
        if (matrix.empty() || matrix[0].empty()) return;
        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
    
private:
    vector<vector<int> > dp;
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) 
        {
            return 0;
        }
        int m = matrix.size(); 
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for (int i = 0; i < matrix.size(); ++i) 
        {
            for (int j = 0; j < matrix[i].size(); ++j) 
            {
                int t = matrix[i][j] - '0';
                if (i > 0) 
                {
                    t += sum[i - 1][j];
                }
                if (j > 0)
                {
                    t += sum[i][j - 1];
                }
                if (i > 0 && j > 0)
                {
                    t -= sum[i - 1][j - 1];
                }
                sum[i][j] = t;
                int cnt = 1;
                for (int k = min(i, j); k >= 0; --k) 
                {
                    int d = sum[i][j];
                    if (i - cnt >= 0) d -= sum[i - cnt][j];
                    if (j - cnt >= 0) d -= sum[i][j - cnt];
                    if (i - cnt >= 0 && j - cnt >= 0) d += sum[i - cnt][j - cnt];
                    if (d == cnt * cnt) res = max(res, d);
                    ++cnt;
                }
            }
        }
        return res;
    }
};
