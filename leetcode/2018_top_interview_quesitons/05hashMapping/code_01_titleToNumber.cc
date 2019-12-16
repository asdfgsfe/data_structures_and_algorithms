 class Solution {
 public:
	 int titleToNumber(string s) {
		 unordered_map<char, int> charToNums;
		 for (int i = 0; i < 26; ++i)
		 {
			 charToNums['A' + i] = i + 1;
		 }
		 long long num = 0;
		 for (char ch : s)
		 {
			 num = num * 26 + charToNums[ch];
		 }
		 return (int)num;
	 }
 };