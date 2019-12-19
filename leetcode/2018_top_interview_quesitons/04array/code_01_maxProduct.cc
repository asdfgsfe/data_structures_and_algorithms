 class Solution {
 public:
	 int maxProduct(vector<int>& nums) {
		 if (nums.empty())
		 {
			 return 0;
		 }
		 long long maxM = nums[0];
		 long long minM = nums[0];
		 long long answer = nums[0];
		 for (int i = 1; i < nums.size(); ++i)
		 {
			 long long n1 = nums[i] * maxM;
			 long long n2 = nums[i] * minM;
			 maxM = std::max((long long)nums[i], std::max(n1, n2));
			 minM = std::min((long long)nums[i], std::min(n1, n2));
			 answer = std::max(answer, maxM);
		 }
		 return answer;
	 }
 };