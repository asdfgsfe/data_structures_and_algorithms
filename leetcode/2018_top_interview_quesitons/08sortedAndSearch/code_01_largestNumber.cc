 class Solution {
 public:
	 string largestNumber(vector<int>& nums) {
		 if (nums.empty())
		 {
			 return "";
		 }
		 std::sort(nums.begin(), nums.end(),
			 [](int lhs, int rhs)
		 {
			 string l = std::to_string(lhs) + std::to_string(rhs);
			 string r = std::to_string(rhs) + std::to_string(lhs);
			 return l > r;
		 });
		 string maxNum;
		 for (int num : nums)
		 {
			 maxNum += std::to_string(num);
		 }
         assert(!maxNum.empty());
		 return maxNum[0] == '0' ? maxNum.substr(0, 1) : maxNum;
	 }
 };