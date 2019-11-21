#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>


using std::vector;
using std::string;
using std::set;

//暴力解超时 1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty())
        {
            return vector<vector<int>>();
        }
        vector<string> strNums(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            strNums[i] = std::to_string(nums[i]);
        }
        vector<vector<string>> sums;
        SumsProcess(strNums, 0, sums);
		set<string> unique;
        
        vector<vector<int>> threeSums;
		for (int i = 0; i < sums.size(); ++i)
        {
			vector<int> curSum;
			for (int j= 0; j < sums[0].size(); ++j)					
			{
				if (!sums[i][j].empty())
				{	
						curSum.emplace_back(atoi(sums[i][j].c_str()));
						//std::cout << " sij=" << sums[i][j] << " curS=" << curSum[j];
				}
							
			}
			std::cout << std::endl;
			std::sort(curSum.begin(), curSum.end());
			string tmp = std::to_string(curSum[0]) + "_" + std::to_string(curSum[1]) + "_" + std::to_string(curSum[2]);
			if (unique.find(tmp) == unique.end())
			{
				unique.insert(tmp);
				threeSums.emplace_back(curSum);
			}
			//std::cout << std::endl;
        }
        return threeSums;
    }
    
    void SumsProcess(vector<string>& nums, int cur, vector<vector<string>>& sums)
    {
        if (cur == nums.size())
        {
            if (IsTarget(nums))
            {
                sums.emplace_back(nums);
            }
            return;
        }
        SumsProcess(nums, cur + 1, sums);
        string tmp = nums[cur];
        nums[cur] = "";
        SumsProcess(nums, cur + 1, sums);
        nums[cur] = tmp;
    }
   
	void DumpVector(const vector<string>& nums)
	{
		for (const auto& num : nums)
		{
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}

    bool IsTarget(const vector<string>& nums)
    {
        //std::cout << "nums.size=" << nums.size() << " ";
				//DumpVector(nums);
		if (nums.size() < 3)
        {
            return false;
        }
        int emptyCnt = 0;
        int sum = 0;
        for (const string& num : nums)
        {
            if (!num.empty())
            {
                ++emptyCnt;
                sum += ::atoi(num.c_str());
            }
        }
				//std::cout << "emptyCnt=" << emptyCnt << " sum=" << sum << std::endl;
        if (emptyCnt == 3 && sum == 0)
        {
          //std::cout << "target:";
					//DumpVector(nums);  
					return true;
        }
        return false;
    }
};



//简短点的暴力解 2 先收集结果 最后去重 超时
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty())
        {
            return vector<vector<int>>();
        }
        vector<vector<int>> sums;
        vector<int> tmp;
        SumsProcess(nums, 0, 3, sums, tmp);
	    set<string> unique;  
        vector<vector<int>> threeSums;
		for (int i = 0; i < sums.size(); ++i)
        {
			std::sort(sums[i].begin(), sums[i].end());
		    string stmp = std::to_string(sums[i][0]) + "_" + std::to_string(sums[i][1]) + "_" + std::to_string(sums[i][2]);
			if (unique.find(stmp) == unique.end())
		    {
				unique.insert(stmp);
				threeSums.emplace_back(sums[i]);
			}
        }
        return threeSums;
    }
    
    void SumsProcess(vector<int>& nums, int cur, int aim, vector<vector<int>>& sums, vector<int> tmp)
    {
        if (aim == 0)
        {
            assert(tmp.size() == 3);
            if ((tmp[0] + tmp[1] + tmp[2]) == 0)
                sums.emplace_back(tmp);
			return;
        }
        if (cur == nums.size())
        {
            return;
        }
        tmp.push_back(nums[cur]);
        SumsProcess(nums, cur + 1, aim - 1, sums, tmp);
        tmp.pop_back();
        SumsProcess(nums, cur + 1, aim, sums, tmp);
    }
};





//简短点的暴力解3 掌握这种利用一个变量去切取自己想要子序列长度的方法
//暴力的遍历所有子序列
//在遍历的过程中去重
//timedout
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty())
        {
            return vector<vector<int>>();
        }
        vector<vector<int>> sums;
        vector<int> tmp;
        set<string> unique; 
        SumsProcess(nums, 0, 3, sums, tmp, unique); 
        return sums;
    }
    
    void SumsProcess(vector<int>& nums, int cur, int aim, vector<vector<int>>& sums, vector<int> tmp, set<string>& unique)
    {
        if (aim == 0 && tmp.size() == 3 && (tmp[0] + tmp[1] + tmp[2]) == 0)
        {
			std::sort(tmp.begin(), tmp.end());
			string stmp = std::to_string(tmp[0]) + "_" + std::to_string(tmp[1]) + "_" + std::to_string(tmp[2]);
			if (unique.find(stmp) == unique.end())
			{
				sums.emplace_back(tmp);
				unique.insert(stmp);
			}
            return;
        }
        if (cur == nums.size())
        {
            return;
        }
        tmp.push_back(nums[cur]);
        SumsProcess(nums, cur + 1, aim - 1, sums, tmp, unique);
        tmp.pop_back();
        SumsProcess(nums, cur + 1, aim, sums, tmp, unique);
    }
};


void Dump(const vector<vector<int>>& sums)
{
	for (const auto& sum : sums)
	{
		for (auto val : sum)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main(void)
{
	int n;
	std::cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < nums.size(); ++i)
	{
		std::cin >> nums[i];
	}	
	Solution sl;
	vector<vector<int>> res = sl.threeSum(nums);
	Dump(res);

	return 0;
}

