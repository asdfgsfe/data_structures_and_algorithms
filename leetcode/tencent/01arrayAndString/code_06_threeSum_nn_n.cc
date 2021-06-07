
//题目在全是0的情况下 会超时
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }
        vector<vector<int>> sums;
        unordered_set<string> visited;
        //固定a数字 变成两数之和为a
        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int> numToIds;
            //找b+c = a
            for (int j = i + 1; j < nums.size(); ++j) {
                int n = -(nums[i] + nums[j]);
                if (numToIds.count(n)) {
                    vector<int> tmp{nums[i], nums[j], n};
                    std::sort(tmp.begin(), tmp.end());
                    string s = std::to_string(tmp[0]) + "_" + std::to_string(tmp[1]) + "_" + std::to_string(tmp[2]);
                    if (!visited.count(s)) {
                        sums.emplace_back(std::move(tmp));
                        visited.emplace(std::move(s));
                    }
                }
                numToIds[nums[j]] = j;
            }
        }
        return sums;
    }
};

三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
 

提示：

0 <= nums.length <= 3000
-105 <= nums[i] <= 105


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/tencent/xxst6e/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
