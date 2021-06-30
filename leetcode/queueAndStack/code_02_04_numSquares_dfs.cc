//����ܽ���dfs ��Ҫ�뵽�ö�̬�滮�Ż� ������dfs�ᳬʱ
class Solution {
    public int numSquares(int n) {
        if (n < 3)
        {
			return n;
        }
		int cnt = 0x7fffffff;
		for (int i = sqrt(n); i >= 1; --i)
		{
			cnt = std::min(cnt, numSquares(n - i * i) + 1);
		}
		return cnt;
    }
}


//����ac ��ʵ���Ǽ��仰�����ķ���
class Solution {
public:
    int numSquares(int n) {
        if (n < 1) {
            return 0;
        }
        //dfs+dp �����������Ѿ�������� �Ͳ����ڼ�����
        unordered_map<int, int> dp;
        return SquareProcess(n, dp);
    }

    int SquareProcess(int n, unordered_map<int, int>& dp) {
        if (n == 0) {
            return 0;
        }
        auto it = dp.find(n);
        if (it != dp.end()) {
            return it->second;
        }
        int cnt = 0x7fffffff;
        for (int i = sqrt(n); i > 0; --i) {
            cnt = std::min(cnt, SquareProcess(n - i * i, dp));
        }
        dp[n] = 1 + cnt;
        return 1 + cnt;
    }
};
