两个列表的最小索引总和
假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。

示例 1:

输入:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
输出: ["Shogun"]
解释: 他们唯一共同喜爱的餐厅是“Shogun”。
示例 2:

输入:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
输出: ["Shogun"]
解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
提示:

两个列表的长度范围都在 [1, 1000]内。
两个列表中的字符串的长度将在[1，30]的范围内。
下标从0开始，到列表的长度减1。
两个列表都没有重复的元素。
相关标签
数组
哈希表
字符串

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xhfact/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		if (list1.empty() || list2.empty())
		{
			return {};
		}
		unordered_map<string, int> eateryToIds;
		for (int i = 0; i < list1.size(); ++i)
		{
			eateryToIds[list1[i]] = i;
		}
		//用于记录最小的id 后面直接通过最小的id 哪去数组的列表
		unordered_map<int, vector<int>> sumToIds;
		int minId = 0x7fffffff;
		for (int i = 0; i < list2.size(); ++i)
		{
			auto id = eateryToIds.find(list2[i]);
			if (id != eateryToIds.end() && minId >= id->second + i)
			{
				minId = id->second + i;
				sumToIds[minId].emplace_back(i);
			}
		}
		vector<string> eaterys;
		const vector<int>& ids = sumToIds[minId];
		for (int id : ids)
		{
			eaterys.emplace_back(list2[id]);
		}
		return eaterys;
	}
};


//下面这种方法是记录共同词语和最小id 然后查询最小id
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.empty() || list2.empty()) {
            return {};
        }
        unordered_map<string, int> indexs;
        for (int i = 0; i < list1.size(); ++i) {
            if (!indexs.count(list1[i])) {
                indexs[list1[i]] = i;
            }
        }
        int minIndexSum = 0x7fffffff;
        vector<pair<string, int>> bestRets;
        for (int i = 0; i < list2.size(); ++i) {
            auto it = indexs.find(list2[i]);
            if (it == indexs.end()) {
                continue;
            }
            if (i + it->second <= minIndexSum) {
                minIndexSum = i + it->second;
                bestRets.emplace_back(pair<string, int>{list2[i], minIndexSum});
            }
        }
        vector<string> rets;
        for (auto& pair : bestRets) {
            if (pair.second == minIndexSum) {
                rets.emplace_back(std::move(pair.first));
            }
        }
        return rets;
    }
};
