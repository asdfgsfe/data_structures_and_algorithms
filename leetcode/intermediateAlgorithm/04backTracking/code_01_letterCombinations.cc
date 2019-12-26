 class Solution {
 public:
	 vector<string> letterCombinations(string digits) {
		 if (digits.empty())
		 {
			 return {};
		 }
		 unordered_map<char, string> numToChars{ { '2', "abc" },{ '3', "def" },{ '4', "ghi" },
												{'5', "jkl"},{ '6', "mno" },{ '7', "pqrs" },
												{'8', "tuv"},{ '9', "wxyz" } };
		 bool ret = true;
		 return CombinationsProcess(digits, 0, ret, numToChars);
	 }

	 vector<string> CombinationsProcess(const string& digits, int i, bool& ret, const unordered_map<char, string>& numToChars)
	 {
		 if (i == digits.size())
		 {
			 return {};
		 }
		 auto it = numToChars.find(digits[i]);
		 if (it == numToChars.end())
		 {
			 ret = false;
			 return {};
		 }
		 const string& chars = it->second;
		 vector<string> combinations;
		 for (char ch : chars)
		 {
			 vector<string> next = CombinationsProcess(digits, i + 1, ret, numToChars);
			 if (!ret)
			 {
				 return {};
			 }
			 string cur(1, ch);
			 if (next.empty())
			 {
				 combinations.emplace_back(cur);
			 }
			 else
			 {
				 for (string& n : next)
				 {
					 combinations.emplace_back(cur + n);
				 }
			 }
		 }
		 return combinations;
	 }
 };