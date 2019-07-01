//可以不用递归o(n*n)的遍历就能搞定子序列
void Process(const vector<string>& numbers, int i, vector<vector<string>>& sequences)
{
  if (i == numbers.size())
  {
    sequences.emplace_back(numbers);
    return;
  }
  Process(numbers, i + 1, sequences);
  string tmp;
  std::swap(numbers[i], tmp);
  Process(numbers, i + 1, sequences);
  std::swap(numbers[i], tmp);
}

//先利用递归求出所有的子序列 然后从子序列中选出最长且递增的 就是答案
vector<vector<string>> AllSubsequence(const vector<string>& numbers)
{
  if (numbres.empty())
  {
    return vector<vector<string>>();
  }
  vector<vector<string>> sequences;
  Process(numbers, 0, sequences);
  vector<string> res;
  int maxLen = 0;
  for (const auto& sequence : sequences)
  {
    bool isIncr = false;
    for (int i = 1; i < sequence.size(); ++i)
    {
      if (sequence[i - 1] >= sequence[i])
      {
        isIncr = true;
        break;
      }
    }
    if (isIncr && maxLen < sequence.size())
    {
      maxLen = sequence.size();
      res = sequence;
    }
  }
  return sequence;
}

//最长递增子序列工4种方法
//1.递归 选出所有的子序列 在挑出最长的 与递增的 子序列用要当前位置与不要当前位置值来搞
//2.递归 在递归的过程中选出以每个位置结尾的情况下最长的递增子序列长度 在选出一个全局最大的
//3.在二的基础上进行dp优化o(n*n)
//4.在三的基础上 利用ends数组队内部for进行优化logn n*log(n)