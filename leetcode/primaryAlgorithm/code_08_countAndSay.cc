 class Solution {
 public:
	 string countAndSay(int n) {
		 if (n < 2)
		 {
			 return n == 1 ? string("1") : string();
		 }
		 string num("1");
		 for (int i = 2; i <= n; ++i)
		 {
			 int p = 0;
			 int n = 0;
			 string next;
			 while (n < num.size())
			 {
				 while (n < num.size() && num[n] == num[p])
				 {
					 ++n;
				 }
				 next.push_back(n - p + '0');
				 next.push_back(num[p]);
				 p = n;
			 }
			 next.swap(num);
		 }
		 return num;
	 }
 };