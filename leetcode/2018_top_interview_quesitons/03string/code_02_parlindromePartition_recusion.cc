 class Solution {
 public:
	 vector<vector<string>> partition(string s) {
		 if (s.empty())
		 {
			 return {};
		 }
		 return PartitionProcess(s, 0);
	 }

	 vector<vector<string>> PartitionProcess(const string& str, int l)
	 {
		 if (l == str.size())
		 {
			 return {};
		 }
		 vector<vector<string>> allCnt;
		 for (int s = l; s < str.size(); ++s)
		 {
			 if (!IsPalindrome(str, l, s))
			 {
				 continue;
			 }
			 vector<vector<string>> nextCnts = PartitionProcess(str, s + 1);
			 if (nextCnts.empty())
			 {
				 allCnt.emplace_back(vector<string>(1, str.substr(l, s - l + 1)));
			 }
			 else
			 {
				 for (const vector<string>& cnt : nextCnts)
				 {
					 vector<string> oneCnt(1, str.substr(l, s - l + 1));
					 oneCnt.insert(oneCnt.end(), cnt.begin(), cnt.end());
					 allCnt.emplace_back(std::move(oneCnt));
				 }
			 }
		 }
		 return allCnt;
	 }

	 bool IsPalindrome(const string& str, int l, int r)
	 {
		 while (l <= r)
		 {
			 if (str[l++] != str[r--])
			 {
				 return false;
			 }
		 }
		 return true;
	 }
 };