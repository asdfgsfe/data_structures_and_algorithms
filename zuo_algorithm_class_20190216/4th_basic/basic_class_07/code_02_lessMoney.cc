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
		int curMoney = gold.front();
		std::pop_heap(gold.begin(), gold.end(), std::greater<int>());
		gold.pop_back();
		curMoney += gold.front();
		std::pop_heap(gold.begin(), gold.end(), std::greater<int>());
		gold.pop_back();
		gold.push_back(curMoney);
		std::push_heap(gold.begin(), gold.end(), std::greater<int>());
		lessMoney += curMoney;
	}
	return lessMoney;
}