bool IsNumber(const char* pDigit)
{
  if (!pDight)
  {
    return false;
  }
  if (*pDigit == '-' || *pDight == '+')
  {
    ++pDight;
  }
  if (*pDigit == '\0')
  {
    return false;
  }

  ScanDigits(&pDigit);
  bool number = true;
  if (*pDigit != '\0')
  {
    if (*pDigit == '.')
    {
      ++pDigit;
      ScanDigits(&pDigit);
      if (*pDigit == 'e' || *pDigit == 'E')
      {
        number = IsExponential(&pDigit);
      }
    }
    else if (*pDigit == 'e' || *pDigit == 'E')
    {
      number = IsExponential(&pDigit);
    }
    else
    {
      number = false;
    }
  }
  return number && *pDigit == '\0';
}

bool IsExponential(const char** pDigit)
{
  if (**pDigit != 'e' && **pDigit != 'E')
  {
    return false;
  }
  if (**pDigit == '-' || **pDigit == '+')
  {
    ++(*pDigit);
  }
  ScanDigits(pDigit);
  return **pDigit == '\0';
}

void ScanDigits(const char** pDigit)
{
  while (*pDigit != '\0' && *pDigit <= '9' && *pDigit >= '0')
  {
    ++(*pDigit);
  }
}
