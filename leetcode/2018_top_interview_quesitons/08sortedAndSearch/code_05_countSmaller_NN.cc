 class Solution {
 public:
	 vector<int> countSmaller(vector<int>& nums) {
		 if (nums.empty())
		 {
			 return {};
		 }
		 vector<int> count(nums.size(), 0);
		 for (int i = nums.size() - 2; i >= 0; --i)
		 {
			 for (int j = i + 1; j < nums.size(); ++j)
             {
                if (nums[i] > nums[j])
			    {
				    ++count[i];
			    }
             }
		 }
		 return count;
	 }
 };