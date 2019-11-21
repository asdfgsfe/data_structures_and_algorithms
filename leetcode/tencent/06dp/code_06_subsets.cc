子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

class Solution {
public:
    // 循环方法:
    // 可以直接从后遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集
    // 元素数0，对应[], 元素数1, 对应[]、[1], 元素数2，对应[]、[1]、[2]、[1,2]，
    // 每多一个元素, 所有子集 = 之前所有子集 + 之前所有子集加当前元素形成的新子集
    // 位图法:
    // 如果有N个元素，则对0~2^N-1循环，如果当前循环索引的第i个bit位为1，则把第i个元素加进当前子集
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result = {{}};
        //result.push_back(vector<int>{});
        for(auto var : nums)
		{
            int tmpLen = result.size();
            for(int i = 0; i < tmpLen; ++i)
			{
                vector<int> tmp = result[i];
                tmp.push_back(var);
                result.push_back(tmp);
            }
        }
        return result;
    }
};