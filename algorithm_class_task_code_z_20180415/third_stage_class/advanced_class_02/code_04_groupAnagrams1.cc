#include <string.h>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using std::string;
using std::vector;
using std::unordered_map;

vector<vector<string>> GroupAnsgrams1(const vector<string>& wordList)
{
  unordered_map<string, vector<string>> wordMap;
  for (auto it = wordList.begin(); it != wordList.end(); ++it)
  {
    string tmp = *it;
    std::sort(tmp.begin(), tmp.end());
    if (wordMap.find(tmp) == wordMap.end())
    {
      vector<string> v;
      wordMap[tmp] = std::move(v);
    }
    wordMap[tmp].push_back(*it);
  }
  
  vector<vector<string>> result;
  for (auto it = wordMap.begin(); it != wordMap.end(); ++it)
  {
    result.push_back(it->second);
  }
  return result;
}

vector<vector<string>> GroupAnsgrams2(const vector<string>& wordList)
{
  unordered_map<string, vector<string>> wordMap;
  for (auto it = wordList.begin(); it != wordList.end(); ++it)
  {
    short records[26];
    memset(records, 0, sizeof records);
    for (int i = 0; i != it->length(); ++i)
    {
      char ch = (*it)[i];
      records[ch - 'a']++;
    }

    string builder;
    for(int i = 0; i < 26; ++i)
    {
      const string& tmp = std::to_string(records[i]);
      builder.append(tmp).append("_");
    }
    if (wordMap.find(builder) == wordMap.end())
    {
      vector<string> tmp;
      wordMap[builder] = std::move(tmp);
    }
    wordMap[builder].push_back(*it);
  }

  vector<vector<string>> result;
  for (auto it = wordMap.begin(); it != wordMap.end(); ++it)
  {
    result.push_back(it->second);
  }
  return result;
}
void PrintVector(const vector<string>& v)
{
  std::cout << "[";
  for (auto it = v.begin(); it != v.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << "]" << std::endl;
}

int main(void)
{
  vector<string> wordList = {"eat", "tea", "tan", "ate", "nat","bat"};
  vector<vector<string>> result = GroupAnsgrams1(wordList);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    PrintVector(*it);
  }

  std::cout << "==============" << std::endl;
  result = GroupAnsgrams2(wordList);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    PrintVector(*it);
  }
  
  return 0;
}



