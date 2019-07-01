class CharStatistics
{
public:
  CharStatistics()
    : index_(0), occurrence_(vector<int>(256, -1))
  {}

  void Insert(char ch)
  {
    if (occurrence_[ch] == -1)
    {
      occurrence_[ch] = index_;
    }
    else if (occurrence_ >= 0) 
    {
      occurrence_ = -2;
    }
    ++index_;
  }

  char FirstAppearOnce() const
  {
    char ch = '\0';
    int minIndex = 0x7fffffff;
    for (int i = 0; i < 256; ++i)
    {
      if (occurrence_[i] > 0 && occurrence_[i] < minIndex)
      {
        ch = (char)i;
        minIndex = occurrence_[i];
      }
    }
    return ch;
  }

private:
  vector<int> occurrence_;
  int index_;
};
