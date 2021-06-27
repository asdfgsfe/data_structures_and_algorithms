两个数组的交集 II
给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
示例 2:

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
 

说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
我们可以不考虑输出结果的顺序。
进阶：

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
相关标签
数组
哈希表
双指针
二分查找
排序

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xx5hsd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty())
		{
			return {};
		}
		//记录所有的id， 也可以统计这个数字出现的次数 在下面的计算中减去出现的次数 直到次数为0
		unordered_map<int, vector<int>> numToIds;
		for (int i = 0; i < nums1.size(); ++i)
		{
			numToIds[nums1[i]].emplace_back(i);
		}
		unordered_map<int, int> visited;
		vector<int> intersection;
		for (int num : nums2)
		{
			auto ids = numToIds.find(num);
			auto preId = visited.find(num);
			if (ids != numToIds.end() && (preId == visited.end() || preId->second + 1< ids->second.size()))
			{
				intersection.emplace_back(num);
				visited[num] = preId == visited.end() ? 0 : preId->second + 1;
			}
		}
		return intersection;
	}
};
