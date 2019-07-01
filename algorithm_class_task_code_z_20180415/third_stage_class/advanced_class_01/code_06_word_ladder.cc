#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <assert.h>

void ShortestPaths(const std::string& cur, 
                   const std::string& end, 
                   const std::unordered_map<std::string, std::vector<std::string>>& nexts,
                   const std::unordered_map<std::string, int>& distance,
                   std::vector<std::string>& solution,
                   std::vector<std::vector<std::string>>& result)
{
  solution.push_back(cur);
  if (end == cur)
  {
    result.push_back(solution);
  }
  else 
  {
    for (auto next = nexts.at(cur).begin(); next != nexts.at(cur).end(); ++next)
    {
      if (distance.at(*next) == distance.at(cur) + 1)
      {
        ShortestPaths(*next, end, nexts, distance, solution, result);
      }
    }
  }
  solution.pop_back();
}

std::unordered_map<std::string, int>
Distance(const std::string& beginWord, 
         const std::unordered_map<std::string, std::vector<std::string>>& nexts)
{
  std::queue<std::string> que;
  que.push(beginWord);
  std::unordered_map<std::string, int> distance;
  distance[beginWord] = 0;
  std::unordered_set<std::string> set;
  set.insert(beginWord);
  while (!que.empty())
  {
    std::string cur = que.front();
    que.pop();
    assert(nexts.find(cur) != nexts.end());
    for (auto it = nexts.at(cur).begin(); it != nexts.at(cur).end(); ++it)
    {
      if (set.find(cur) == set.end())
      {
        distance[*it] = distance[cur] + 1;
        que.push(*it);
        set.insert(*it);
      }
    }
  }
  return distance;
}

std::vector<std::string>
GetNext(std::string& word, const std::unordered_set<std::string>& dictionary)
{
  std::vector<std::string> res;
  for (char cur = 'a'; cur <= 'z'; ++cur)
  {
    for (int i = 0; i < word.length(); ++i)
    {
      if (word[i] != cur)
      {
        char tmp = word[i];
        word[i] = cur;
        if (dictionary.find(word) != dictionary.end())
        {
          res.push_back(word);
        }
        word[i] = tmp;
      }
    }
  }
  return res;
}

std::unordered_map<std::string, std::vector<std::string>>
GenerateNexts(const std::list<std::string>& wordList)
{
  std::unordered_set<std::string> dictionary;
  std::unordered_map<std::string, std::vector<std::string>> nexts;
  for (auto it = wordList.begin(); it != wordList.end(); ++it)
  {
    nexts[*it] = GetNext(*it, dictionary);
  }
  return nexts;
}

std::vector<std::vector<std::string>> FindLadders(const std::string& beginWord, 
                                                         const std::string& endWord,
                                                         std::list<std::string>& wordList)
{
  wordList.push_back(beginWord);
  std::unordered_map<std::string, std::vector<std::string>> nexts = GenerateNexts(wordList);
  std::unordered_map<std::string, int> distance = Distance(beginWord, nexts);
  std::vector<std::string> pathList;
  std::vector<std::vector<std::string>> result;
  ShortestPaths(beginWord, endWord, nexts, distance, pathList, result);
  return result;
}

void PrintVector(const std::vector<std::string>& v)
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
  std::string beginWord = "hit";
  std::string end = "cog";
  std::list<std::string> wordList;
  wordList.push_back("hot");
  wordList.push_back("dot");
  wordList.push_back("dog");
  wordList.push_back("lot");
  wordList.push_back("log");
  wordList.push_back("cog");

  std::vector<std::vector<std::string>> res = FindLadders(beginWord, end, wordList);
  for (auto it = res.begin(); it != res.end(); ++it)
  {
    PrintVector(*it);
  }

  return 0;
}
