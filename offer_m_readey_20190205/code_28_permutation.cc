 void Permutation(string& str)
{
  if (str.empty())
  {
    return;
  }
  PermutationProcess(str, 0);
}

void PermutationProcess(string& str, int index)
{
  if (index == str.size())
  {
    std::cout << str << std::endl;
  }
  for (int i = index; i < str.size(); ++i)
  {
    std::swap(str[index], str[i]);
    PermutationProcess(str, index + 1);
    std::swap(str[index], str[i]);
  }
}

void Permutation(char* pStr)
{
  if (!pStr)
  {
    return;
  }
  PermutationProcess(pStr, pStr);
}

void PermutationProcess(char* pStr, char* pBegin)
{
  if (*pBegin == '\0')
  {
    printf("%s\n", pStr);
  }
  for (char* pCh = *pBegin; *pCh != '\0'; ++Ch)
  {
    char ch = *pBegin;
    *pBegin = *pCh;
    *pCh = ch;
    PermutationProcess(pStr, pBegin + 1);
    ch = *pBegin;
    *pBegin = *pCh;
    *pCh = ch;
  }
}
