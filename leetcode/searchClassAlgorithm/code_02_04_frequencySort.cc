 class Solution {
 public:
	 string frequencySort(string s) {
		 if (s.empty())
		 {
			 return string();
		 }
		 vector<pair<char, int>> charCnt(256);
		 for (char ch : s)
		 {
			 charCnt[ch].first = ch;
			 ++charCnt[ch].second;
		 }
		 std::sort(charCnt.begin(), charCnt.end(), 
			 [](const pair<int, int>& lhs, const pair<int, int>& rhs)
			 {
				return lhs.second > rhs.second;
			 });
		 int p = 0;
		 for (int i = 0; i < charCnt.size() && charCnt[i].second != 0; ++i)
		 {
			 while (charCnt[i].second-- > 0)
			 {
				 s[p++] = charCnt[i].first;
			 }
		 }
		 return s;
	 }
 };