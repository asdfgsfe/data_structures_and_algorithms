 class Solution {
 public:
	 vector<vector<int>> fourSum(vector<int>& nums, int target) {
		 if (nums.empty())
		 {
			 return {};
		 }
		 vector<vector<int>> answer;
		 std::sort(nums.begin(), nums.end());
		 for (int i = 0; i < nums.size(); ++i)
		 {
			 if (i > 0 && nums[i] == nums[i - 1])
			 {
				 continue;
			 }
			 for (int j = i + 1; j < nums.size(); ++j)
			 {
				 if (j > i + 1 && nums[j] == nums[j - 1])
				 {
					 continue;
				 }
				 int sum = nums[i] + nums[j];
				 int l = j + 1;
				 int r = nums.size() - 1;
				 while (l < r)
				 {
					 if (nums[l] + nums[r] == target - sum)
					 {
						 vector<int> ids{ nums[i], nums[j], nums[l++], nums[r--] };
						 answer.emplace_back(ids);
						 while (l < r && nums[l] == nums[l - 1])
						 {
							 ++l;
						 }
						 while (l < r && nums[r] == nums[r + 1])
						 {
							 --r;
						 }
					 }
					 else if (nums[l] + nums[r] > target - sum)
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
		 return answer;
	 }
 };