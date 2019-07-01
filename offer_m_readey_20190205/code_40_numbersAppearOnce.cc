vector<int> NumbersAppearOnce(const vector<int>& numbers)
{
  if (numbers.size() < 3)
  {
    return numbers;
  }
  int eor = 0;
  for (int number : numbers)
  {
    eor ^= number;
  }
  int id = FirstBit1Index(eor);
  int eor1 = 0;
  int eor2 = 0;
  for (int number : numbers)
  {
    if (IsBit1(number, id))
    {
      eor1 ^= number;
    }
    else
    {
      eor2 ^= number;
    }
  }
  vector<int> twoNumbers(2);
  twoNumbers[0] = eor1;
  twoNumbers = eor2;
  return twoNumbers;
}

int FirstBit1Index(int number)
{
  int idBit = 0;
  while ((number & 1) == 0 && idBit < sizeof(int) * 8)
  {
    number >>= 1;
    ++idBit;
  }
  return idBIt;
}

bool IsBit1(int number, int id)
{
  number >>= id;
  return number & 1;
}
