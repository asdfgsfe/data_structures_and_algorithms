//感觉贪心就是资源无限多 而你能获取的次数有限制 在有限制的情况下拿取最多的 
//贪心就2中解法 1.排序 2.堆结构
//动态规划就是资源有限多 而你能获取的次数无限制 无限次尝试 最后找到一种最叼的方法
int LessMoney(const vector<int>& gold)
{
	if (gold.empty())
	{
		return 0;
	}
	int lessMoney = 0;
	std::make_heap(gold.begin(), gold.end(), std::greater<int>());
	while (gold.size() > 1)
	{
		int size = 2;
		int curMoney = 0;
		while (--size)
		{
			assert(!gold.empty());
			curMoney += gold.front();
			std::pop_heap(gold.begin(), gold.end(), std::greater<int>());
			gold.pop_back();
		}
		gold.push_back(curMoney);
		std::push_heap(gold.begin(), gold.end(), std::greater<int>());
		lessMoney += curMoney;
	}
	return lessMoney;
}