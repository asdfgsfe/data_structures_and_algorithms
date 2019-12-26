 class Solution {
 public:
	 int hammingDistance(int x, int y) {
		 uint32_t base = 1;
		 int cnt = 0;
		 for (int i = 1; i < 32; ++i)
		 {
			 if ((base & x) != (base & y))
			 {
				 ++cnt;
			 }
			 base = 1 << i;
		 }
		 return cnt;
	 }
 };