#include <stdio.h>

void ReplaceBankSpace(char* str, int length)
{
  if (str == nullptr || length < 0)
  {
    return;
  }
  int numSpace = 0;
  int originLen = 0;
  int i = 0;
  while (str[i] != '\0')
  {
    ++originLen;
    if (str[originLen] == ' ')
    {
      ++ numSpace;
    }
    ++i;
  }
  int newLength = originLen + numSpace * 2;
  if (newLength >= length)
  {
    return;
  }
  while (originLen >= 0 && newLength > originLen)
  {
    if (str[originLen] == ' ')
    {
      str[newLength--] = '0';
      str[newLength--] = '2';
      str[newLength--] = '%';
    }
    else
    {
      str[newLength--] = str[originLen];
    }
    --originLen;
  }
}

int main(void)
{
  char str[100] = "we are happy.";
  ReplaceBankSpace(str, 100);
  printf("%s\n", str);
  return 0;
}
