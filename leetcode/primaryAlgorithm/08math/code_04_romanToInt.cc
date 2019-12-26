 class Solution {
 public:
	 int romanToInt(string s) {
		 if (s.empty())
		 {
			 return 0;
		 }
		 unordered_map<string, int> romaxNums{ { "I", 1 },{ "V", 5 },{ "X", 10 },{ "L", 50 },
		 { "C", 100 },{ "D", 500 },{ "M", 1000 },
		 { "IV", 4 },{ "IX", 9 },{ "XL", 40 },
		 { "XC", 90 },{ "CD", 400 },{ "CM", 900 } };
		 int number = 0;
		 for (int i = 0; i < s.size(); ++i)
		 {
			 bool isTwo = false;
			 if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')
			 {
				 auto curNum = romaxNums.find(s.substr(i, 2));
				 if (curNum != romaxNums.end())
				 {
					 number += curNum->second;
					 ++i;
					 isTwo = true;
				 }
			 }
			 if (!isTwo)
			 {
				 auto curNum = romaxNums.find(s.substr(i, 1));
				 if (curNum == romaxNums.end())
				 {
					 return 0;
				 }
				 number += curNum->second;
			 }
		 }
		 return number;
	 }
 };