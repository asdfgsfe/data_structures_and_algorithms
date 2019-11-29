class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt = nums[i] == 1 ? cnt + 1 : 0;
            max = std::max(max, cnt);
        }
        return max;
    }
};