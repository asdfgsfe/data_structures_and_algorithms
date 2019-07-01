class Pet
{
public:
  Pet(const string& type)
    : type_(type)
  {
  }
  string Type() const
  {
    return type_;
  }

  ~Pet()
  {}
private:
  sting type_;
};

struct Dog : public Pet
{
  Dog(const string& name)
    : Pet(name)
  {}
};

struct Cat : public Pet
{
  Cat(const string& name)
    : Pet(name)
  {}
};

struct PetEnterQue
{
  PetEnterQue(const Pet& pet, int count)
    : pet_(pet), count_(count)
  {}

const Pet& pet_;
const int count_;
};

class CatDogQueue
{
  CatDogQueue()
    : count_(0)
  {}

  void Add(const Pet& pet)
  {
    if (pet.Type() == "dog")
    {
      dQue.push(PetEnterQue(pet, ++count_));
    }
    else if (pet.Type() == "cat")
    {
      cQue.push(PetEnterQue(pet, ++count_)); 
    }
  }

  const Pet& PollAll()
  {
    assert(!Empty());
    if (!dQue.empty() && !cQue.emppty())
    {
	  return dQue.front().count_ > cQue.front().count_ ? dQue.front().pet_ : cQue.front().pet_;
    }
    if (!dQue.empty())
    {
      return dQue.front().pet_;
    }
    return cQue.front().pet_;
  }

private:
  queue<PetEnterQue> dQue_;
  queue<PetEnterQue> cQue_;
  int count_;
};
