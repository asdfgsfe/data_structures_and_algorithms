������Ʊ�����ʱ�� II
����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����

ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 7
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 3 �죨��Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
     ����ڵ� 4 �죨��Ʊ�۸� = 3����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ������, ��ʽ������ܻ������ = 6-3 = 3 ��
ʾ�� 2:

����: [1,2,3,4,5]
���: 4
����: �ڵ� 1 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �� ����Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
     ע���㲻���ڵ� 1 ��͵� 2 ����������Ʊ��֮���ٽ�����������
     ��Ϊ��������ͬʱ�����˶�ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ��
ʾ�� 3:

����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��

//̰���㷨�������������ޣ�����ͼ��ˣ�ֻҪ��Ǯ��������
class Solution {
public:
	    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int profit = 0;
		for (int i = 0; i < prices.size() - 1; ++i)
		{
            if (prices[i + 1] > prices[i])
            {
                profit += prices[i + 1] - prices[i];
            }
		}
        return profit;
    }
};

//dp�ⷨ ���ǻᳬʱò�����dp������ ����������㿪ʼ��������
class Solution {
public:
	    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int profit = 0;
        vector<int> dp(prices.size() + 1, 0);
		for (int i = dp.size() - 2; i >= 0; --i)
		{
			for (int j = i; j < prices.size(); ++j)
			{
                dp[i] = std::max(dp[i], dp[j + 1] + prices[j] - prices[i]);
                profit = std::max(profit, dp[i]);
            }
		}
        return profit;
    }
};

//�ݹ�
class Solution {
public:
	int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            profit = std::max(profit, BuyProcess(prices, i, i + 1));
        }
        return profit;
    }
    
    int BuyProcess(const vector<int>& prices, int i, int j)
    {
        if (j == prices.size())
        {
            return 0;
        }
        assert(i < j);
        int profit = 0;
        for (int end = j; end < prices.size(); ++end)
        {
            profit = std::max(profit, BuyProcess(prices, end + 1, end + 1) + prices[end + 1] - prices[i]);
        }
        return profit;
    }

//ԭʼdp
	int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        int profit = 0;
		vector<vector<int>> dp(prices.size() + 1, vector<int>(prices.size() + 1), 0);
		for (int i = dp.size() - 2; i >= 0; --i)
		{
			for (int j = dp.size() - 2; j >= 0; --j)
			{
				for (int end = j; end < prices.size(); ++end) //������Ϊ�����Ż���ȥ ��j�ı�������
				{
					dp[i][j] = dp[end + 1][end + 1] + prices[end + 1] - prices[i];
				}
			}
		}
        return dp[0][1];
    }
};

