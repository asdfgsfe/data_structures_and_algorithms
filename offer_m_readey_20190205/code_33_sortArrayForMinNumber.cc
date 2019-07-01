void MinNumber1(vector<int>& numbers)
{
  if (numners.size() < 2)
  {
    return;
  }
  vector<string> strN(numbers.size());
  for (int i = 0; i < numbers.size(); ++i)
  {
    strN[i] = std::to_string(numbers[i]);
  }
  Process(strN, 0);
}

void Process(vector<string>& strN, int index, vector<string>& minNumber)
{
  if (index == strN.size())
  {
    SelectMinNumber(minNumber, strN);;
    return;
  }
  for (int i = index; i < strN.size(); ++i)
  {
    std::swap(strN[index], strN[i]);
    Process(strN, index + 1);
    std::swap(strN[index], strN[i]);
  }
}

void SelectMinNumber(vector<string>& minNumber, const vector<string>& curNum)
{
  if (minNumber.empty())
  {
    minNumber = curNum;
    return;
  }
  assert(minNumber.size() == curNum.size());
  string minStr = ConnectToString(minNumber);
  string curStr = ConnectToString(curNum);
  minNumber = curStr < minStr ? curNum : minNumber;
}

void MinNumber2(vector<int>& numbers)
{
  if (numbers.size() < 2)
  {
    return;
  }
  vector<string> strN(numbers.size());
  for (int i = 0; i < numbers.size(); ++i)
  {
    strN[i] = std::to_string(numbers[i]);
  }
  std::sort(strN.begin(), strN.end(), [&](const string& lhs, const string& rhs) ->bool
      {
        string s1 = lhs + rhs;
        string s2 = rhs + lhs;
        return s1 < s2;
      });
}

char* g_strN1 = new char[2 * 10 + 1];
char* g_strN2 = new char[2 * 10 + 1];

void MinNumber3(int* numbers, int len)
{
  if (!numbers || len < 2)
  {
    return;
  }
  char* strN1 = new char[2 * 10 + 1];
  char* strN2 = new char[2 * 10 + 1];
  char** strN = (char**)(new int[len]);
  for (int i = 0; i < numbers.size(); ++i)
  {
    strN[i] = new char[2 * 10 + 1];
    sprintf(strN[i], "%d", numbers[i]);
  }
  qsort(strN, len, sizeof(char*), Compare);
  for (int i = 0; i < strN; ++i)
  {
    printf("%s", strN[i]);
  }
  for (int i = 0; i < strN[i]; ++i)
  {
    delete strN[i];
  }
  delete strN;
}

int Compare(const void* strN1, const void* strN2)
{
  strcpy(g_strN1, *(const char**)strN1);
  strcat(g_strN1, *(const char**)strN2);

  strcpy(g_strN2, *(const char**)strN2);
  strcat(g_strN2, *(const char**)strN1);
  return strcmp(strN1, strN2);
}
