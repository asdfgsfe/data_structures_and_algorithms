class myString
{
  explicit myString(char* pStr == "")
  {}
  
  ~myString()
  {
    delete[] pStr;
  }

  myString(const myString& other)
  {
    if (this != &other)
    {
      pStr = new char[strlen(other.pStr) + 1];
      strcpy(pStr, other.pStr);
    }
  }

  myString& operator=(const myString& other)
  {
    if (this != &other)
    {
      myString tmp(other);
      char* pTmp = tmp.pStr;
      tmp.pStr = pStr;
      pStr = pTmp;
    }
    return *this;
  }

  const myString* operator&() const
  {
    return this;
  }
  
  myString* operator&()
  {
    return const_cast<myString*>(&);
  }

private:
  char* pStr;
};

