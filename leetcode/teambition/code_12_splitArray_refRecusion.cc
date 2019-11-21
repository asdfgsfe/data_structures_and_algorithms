class Solution {
public:
	//不知道为什么错 但是感觉是对的
	int splitArray(vector<int>& nums, int m) {
		if (nums.empty() || m < 1)
		{
			return 0;
		}
		return SplitProcess(nums, 0, m);
	}

	long long SplitProcess(const vector<int>& nums, int i, int m)
	{
		long long maxSum = 0;
		long long minSum = 0x8000000000000000;
		for (int s = i; s < nums.size(); ++s)
		{
			minSum = std::max(minSum, (long long)nums[i]);
			maxSum += nums[i];
		}
		if (m == 1)
		{
			return minSum;
		}
		if (m == nums.size() - i)
		{
			return maxSum;
		}
		long long sum = 0;
	    long long curMin = 0x7fffffffffffffff;
		for (int s = i; s <= nums.size() - i - m; ++s)
        {
            sum += nums[s];
			long long nextSum = SplitProcess(nums, s + 1, m - 1);
			nextSum = std::max(sum, nextSum);
			curMin = std::min(curMin, nextSum);
		}
		return curMin;
	}
};

//参考答案
class Solution {
public:    
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        int leftsum = 0;
        int rightsum = 0;
        int result = INT_MAX;
        int curres = 0;
        vector<int> rightvec;
        int sumnum = 0;
        int maxnum = 0;
        for(int i=0; i<len; ++i)
        {
            maxnum = max(maxnum, nums[i]);
            sumnum = sumnum + nums[i];
        }
        if(m == 1)
            return sumnum;
        if(m == len)
            return maxnum;
        for(int i=0; i<(len-m+1); ++i)
        {
            leftsum = leftsum + nums[i];
            rightvec.assign((nums.begin()+i+1), nums.end());
            rightsum = splitArray(rightvec, m-1);
            if(leftsum > rightsum)
                curres = leftsum;
            else
                curres = rightsum;
            if(curres < result)
                result = curres;
        }
        return result;
    }
};