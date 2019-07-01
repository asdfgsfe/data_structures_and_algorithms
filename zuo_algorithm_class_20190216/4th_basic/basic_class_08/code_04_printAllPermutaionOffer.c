#include <stdio.h>

void PermutaionProcess(char* pStr, char* pBegin)
{
  if (*pBegin == '\0')
  {
    printf("%s\n", pStr);
    return;
  }
  for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
  {
    char tmp = *pCh;
    *pCh = *pBegin;
    *pBegin = tmp;
    PermutaionProcess(pStr, pBegin + 1);
    tmp = *pCh;
    *pCh = *pBegin;
    *pBegin = tmp;
  }
}

void Permutaion(char* pStr)
{
  if (pStr == nullptr || *pStr == '\0')
  {
    return;
  }
  PermutaionProcess(pStr, pStr);
}

int main(void)
{
  char* pStr = "abc";
  Permutaion(pStr);

  return 0;
}
