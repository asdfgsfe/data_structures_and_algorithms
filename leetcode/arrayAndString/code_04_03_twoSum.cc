class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 2) 
        {
            return {};
        }
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r)
        {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
            {
                return {l + 1, r + 1};
            }
            if (sum > target)
            {
                --r;
            }
            else
            {
                ++l;    
            }
        }
        return {};
    }
};