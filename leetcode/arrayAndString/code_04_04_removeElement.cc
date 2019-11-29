class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
        {
			return 0;
        }
		int p = 0;
		int n = 0;
		while (n < nums.size())
		{
			while (n < nums.size() && nums[n] == val)
			{
				++n;
			}
			while (n < nums.size() && nums[n] != val)
			{
				if (p != n)
				{
					nums[p] = nums[n];
				}
				++p;
				++n;
			}
		}
		return p;
    }
};