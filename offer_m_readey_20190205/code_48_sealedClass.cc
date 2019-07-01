template<typename T>
class SealedClass
{
public:
  static const T& Instance() const
  {
    SealedClass instance_;
    return *this;
  }

private:
  SealedClass() {}
  ~SealedClass() {}
  static T instance_;
};

class SealedClass
{
public:
  static SealedClass* Instance() const
  {
    return new SealedClass();
  }
  static DestoryInstance(SealedClass* pInstance)
  {
    delete pInstance;
  }
private:
  SealedClass() {}
  ~SealedClass() {}
};

template<typename T>
class MakeSealed
{
  friend T;
private:
  MakeSealed() {}
  ~MakeSealed() {}
};

class SealedClass2 : virtual public MakeSealed<SealedClass2>
{
public:
  SealedClass2() {}
  ~SealedClass2() {}
};
