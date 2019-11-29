//借助桶排序选择 和借助sort排序选择的原理一样
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        uint16_t hash[20001] = {0};
        uint16_t small = 20001;
		uint16_t large = 0;
        for(auto &e: nums)
        {
            e += 10000;
            hash[e]++;
            small = min(small, uint16_t(e));
            large = max(large, uint16_t(e));
        }
        bool add = 1;
        int ans = 0;
        
        while(small < large+1)
		{
            //如果这个值出现了多次 那么只要一半就行 所以就有add = 1- add
			if(hash[small]-->0)
			{
                ans += add*(small - 10000);
                add = 1-add;
            }
            else
                small++;
        }
        return ans;
    }
};