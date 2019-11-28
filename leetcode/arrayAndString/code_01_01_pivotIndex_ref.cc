//¿Õ¼äo(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int sumleft = 0;
        int len = size(nums);
        for(int i=0;i<len;i++)
            sum += nums[i];
        for(int i=0;i<len;i++)
        {
            if(sumleft*2+nums[i]==sum)
                return i;
            sumleft+=nums[i];
        }
        return -1;
    }
};