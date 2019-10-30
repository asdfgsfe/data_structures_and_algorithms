//计算长度
int MaxUniqueLen(const string& str)
{
  if (str.empty())
  {
    return 0;
  }
  vector<char> ids(256, -1);
  int pre = -1;
  int maxLen = 0;
  int curLen = 0;
  for (int i = 0; i < str.size(); ++i)
  {
    pre = std::max(pre, ids[str[i]]);
    curLen = i - pre;
    maxLen = curLen > maxLen ? curLen : maxLen;
    ids[str[i]] = i;
  }
  return maxLen;
}

//pre与i之间的为最长无重复子串 或者以i结尾 长为maxLen
//计算具体的最长string
string MaxUniqueString(const string& str)
{
  if (str.empty())
  {
    return string();
  }
  vector<char> ids(256, -1);
  int pre = -1;
  int curLen = 0;
  int maxLen = 0;
  int maxPre = -1;
  for (int i = 0; i < str.size(); ++i)
  {
    pre = std::max(pre, ids[str[i]]);
    curLen = i - pre;
    if (curLen > maxLen)
    {
      maxLen = curLen;
      maxPre = pre;
    }
    ids[str[i]] = i;
  }
  return str.substr(maxPre, maxLen);
}

//simple
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
        {
            return s.size();
        }
        vector<int> preIdxs(256, - 1);
        int len = 0;
        int pre = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            pre = std::max(pre, preIdxs[s[i]]);
            len = std::max(len, i - pre);
            preIdxs[s[i]] = i;
        }
        return len;
    }
};