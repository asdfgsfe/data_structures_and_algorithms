//对于多个数的问题 初级的想法是固定某一个或者某几个 然后去选择别的 一般与排序相互使
//http://www.goodtecher.com/zh/leetcode-15-3sum-%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C/kk=

//没有进行去重处理 去重处理逻辑有问题
//n * log(n) 二分查找的思想
//可以在计算完的基础上在进行去重  超时
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty())
        {
            return vector<vector<int>>();
        }
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> sums;
        for (int i = 0; i < nums.size(); ++i)
        {
            int l = 0;
            int r = nums.size() - 1;
            int aim = -nums[i];
            while (l < r)
            {
                if (nums[l] + nums[r] > aim)
                {
                    --r;
                }
                else if (nums[l] + nums[r] < aim)
                {
                    ++l;
                }
                else
                {
                    if (l != i && r != i)
                    {
                        vector<int> tmp(3);
                        tmp[0] = nums[l++];
                        tmp[1] = nums[i];
                        tmp[2] = nums[r--];
                        sums.push_back(tmp);
                    }
                    else if (l != i)
                    {
                        --r;
                    }
                    else
                    {
                        ++l;
                    }
                }
            }
        }
		//去重处理
        unordered_set<string> processed;
        vector<vector<int>> res;
        for (auto& sum : sums)
        {
            assert(sum.size() == 3);
            std::sort(sum.begin(), sum.end());
            string pre = std::to_string(sum[0]) + std::to_string(sum[1]) + std::to_string(sum[2]);
            if (processed.find(pre) == processed.end())
            {
                processed.emplace(pre);
                res.emplace_back(std::move(sum));
            }
        }
        return res;
    }
};