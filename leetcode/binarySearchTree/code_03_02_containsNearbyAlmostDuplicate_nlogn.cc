class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
	    set<long long> set;
	    for (int i = 0; i < nums.size(); ++i) 
	    {
			//lower_bound���ڵ���
		    auto s = set.lower_bound((long long)nums[i] - (long long)t);
		    if (s != set.end() && *s <= (long long)nums[i] + (long long)t) 
		    {
			    return true;
		    }

		    set.insert(nums[i]);
		    if (set.size() > k) 
		    {
			    set.erase(nums[i - k]);
		    }
	    }
	    return false;
    }
};

//����o(n)���㷨
//https://leetcode-cn.com/problems/contains-duplicate-iii/solution/220-by-ikaruga/