class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
        {
			return 0;
        }
		int sold = 0;
		int hold = 0x80000000;
		int rest = 0;
		for (int price : prices)
		{
			int preSold = sold;
			sold = hold + price;
			hold = std::max(hold, rest - price);
			rest = std::max(rest, preSold);
		}
		return max(rest, sold);
    }
};

//不是很理解
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/309-zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-q/