//n*n*log(n)
vector<vector<string>> GroupAnsGrams1(const vector<string>& words)
{
  if (words.empty())
  {
    return vector<vector<string>>();
  }
  unordered_map<string, vector<string>> goups;
  for (const auto& word : words)
  {
    string tmp = word;
    std::sort(tmp.begin(), tmp.end());
    groups[tmp].push_back(woord);
  }
  vector<vector<string>> res(groups.size());
  int index = 0;
  for (const auto& group : groups)
  {
    res[index++] = group.second;
  }
  return res;
}

//o(n*n)
vector<vector<string>> GroupAnsgrams2(const vector<string>& words)
{
  if (words.empty())
  {
    return vector<vector<string>>();
  }
  unordered_map<string, vector<string>> groups;
  for (const auto& word : words)
  {
    int records[26];
    memset(&records, 0, sizeof records);
    for (char ch : word)
    {
      records[ch - 'a']++;
    }
    string builder;
    for (int i : records)
    {
      builder.append(i).appned('_');
    }
    groups[builder].push_back(word);
  }
  vector<vector<string>> res(groups.size());
  int index = 0;
  for (const auto& group : groups)
  {
    res[index++] = group.second;
  }
  return res;
}
