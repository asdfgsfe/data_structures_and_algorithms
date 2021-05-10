//�ͳ������ ��0�ֵ�ǰ���� 1�ֵ�ǰ���� 2���������Դ�ȥ��
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty())
        {
            return amount == 0 ? 0 : -1;
        }
        if (amount < 1)
        {
            return 0;
        }
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0x7fffffff));
        for (int i = 0; i < dp.size(); ++i)
        {
            dp[i][0] = 0;
        }
        for (int i = dp.size() - 2; i >=0; --i)
        {
            for (int j = 0; j < dp[0].size(); ++j)
            {
                for (int k = 0; j - coins[i] * k >= 0; ++k)
                {
                    if (dp[i + 1][j - coins[i] * k] != 0x7fffffff)
                    {
                        dp[i][j] = std::min(dp[i][j], dp[i + 1][j - coins[i] * k] + k);
                    }
                }
            }
        }
        return dp[0][amount] == 0x7fffffff ? -1 : dp[0][amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty())
        {
            return amount == 0 ? 0 : -1;
        }
        if (amount < 1)
        {
            return 0;
        }
        vector<int> dp(amount + 1, 0x7fffffff);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int coin : coins)
            {
                if (i >= coin && dp[i - coin] != 0x7fffffff)
                {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == 0x7fffffff ? -1 : dp[amount];
    }
};

//f(i) = f(i - c) + 1
//���ȣ������Ƕ��壺F(S)��S ����������СӲ������
//S��ʹ�õ�Ӳ����ֵ��[c0, c1, ...cn - 1]
//����ע�⵽���������һ�����ŵ��ӽṹ���ʣ����ǽ���κζ�̬�滮����Ĺؼ���
//���Ž���Դ�������������Ž⹹�������
//��ν�����ֽ�������⣿��������֪�� F(S) �����ڽ�� S ���ٵ�Ӳ���������һöӲ�ҵ���ֵ�� C��
//��ô��������������ӽṹ���·���ӦΪ��
//F(S) = F(S - C) + 1

���ӣ�https://leetcode-cn.com/problems/coin-change/solution/ling-qian-dui-huan-by-leetcode/
