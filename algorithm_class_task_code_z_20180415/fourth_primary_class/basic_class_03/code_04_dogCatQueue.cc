#include <iostream>
#include <queue>
#include <string>
#include <memory>
#include <exception>

using std::queue;
using std::string;

class Pet
{
public:
  Pet(const string& t, const string& name)
    : petType_(t), name_(name)
  {
  }

  const string& PetType() const
  {
    return petType_;
  }

  const string& Name() const
  {
    return name_;
  }
private:
  const string petType_;
  string name_;
};

class Dog : public Pet
{
public:
  Dog(const string& name)
    : Pet("dog", name)
  {}

};

class Cat : public Pet
{
public:
  Cat(const string& name)
    : Pet("cat", name)
  {}
};

class PetEnterQueue
{
public:
  PetEnterQueue(long c, const std::shared_ptr<const Pet>& pet)
    : count_(c), petPtr_(pet)
  {}
  long Count() const
  {
    return count_;
  }
  const Pet& GetPet() const
  {
    return *petPtr_;
  }

private:
  const long count_;
  std::shared_ptr<const Pet> petPtr_;
};

class DogCatQueue
{
public:
  DogCatQueue()
    : count_(0)
  {
  }

  void Push(const std::shared_ptr<const Pet>& petPtr)
  {
    if (petPtr->PetType() == "dog")
    {
      dogQue_.push(PetEnterQueue(++count_, petPtr));
    }
    else if (petPtr->PetType() == "cat")
    {
      catQue_.push(PetEnterQueue(++count_, petPtr));
    }
    else
    {
      throw("pet type error");
    }
  }

  const Pet& TopAll() const
  {
    if (!EmptyCat() && !EmptyDog())
    {
      if (dogQue_.front().Count() < catQue_.front().Count())
      {
        return dogQue_.front().GetPet();
      }
      else
      {
        return catQue_.front().GetPet();
      }
    }
    else if (!EmptyCat())
    {
      return catQue_.front().GetPet(); 
    }
    else if (!EmptyDog())
    {
      return dogQue_.front().GetPet();
    }
    else
    {
      throw ("queue empty!");
    }
  }

  void PopAll()
  {
    if (!EmptyCat() && !EmptyDog())
    {
      if (dogQue_.front().Count() < catQue_.front().Count())
      {
        dogQue_.pop();
      }
      else
      {
        catQue_.pop();
      }
    }
    else if (!EmptyCat())
    {
      catQue_.pop();
    }
    else if (!EmptyDog())
    {
      dogQue_.pop();
    }
    else
    {
      throw("queue empty!");
    }
  }

  const Pet& TopDog() const
  {
    return dogQue_.front().GetPet();
  }

  const Pet& TopCat() const
  {
    return catQue_.front().GetPet();
  }

  void PopDog()
  {
    if (EmptyDog())
    {
      throw ("dog queue empty");
    }
    dogQue_.pop();
  }
  
  void PopCat()
  {
    if (EmptyCat())
    {
      throw ("cat queue empty");
    }
    catQue_.pop();
  }

  bool Empty()
  {
    return EmptyCat() && EmptyDog();
  }

  bool EmptyCat() const
  {
    return catQue_.empty();
  }

  bool EmptyDog() const
  {
    return dogQue_.empty();
  }

  long Count() const
  {
    return count_;
  }

  int DogSize() const
  {
    return dogQue_.size();
  }

  int CatSize() const
  {
    return catQue_.size();
  }
private:
  long count_;
  queue<PetEnterQueue> dogQue_;
  queue<PetEnterQueue> catQue_;
};

int main(void)
{
  DogCatQueue test;
  std::shared_ptr<const Pet> dog1(new Dog("dog1"));
  std::shared_ptr<const Pet> cat1(new Cat("cat1"));
  std::shared_ptr<const Pet> dog2(new Dog("dog2"));
  std::shared_ptr<const Pet> cat2(new Cat("cat2"));
  std::shared_ptr<const Pet> dog3(new Dog("dog3"));
  std::shared_ptr<const Pet> cat3(new Cat("cat3"));

  test.Push(dog1);
  test.Push(cat1);
  test.Push(dog2);
  test.Push(cat2);
  test.Push(dog3);
  test.Push(cat3);

  test.Push(dog1);
  test.Push(cat1);
  test.Push(dog2);
  test.Push(cat2);
  test.Push(dog3);
  test.Push(cat3);

  test.Push(dog1);
  test.Push(cat1);
  test.Push(dog2);
  test.Push(cat2);
  test.Push(dog3);
  test.Push(cat3);
  try
  {  
    std::cout << test.Count() << std::endl;
    while (!test.EmptyDog()) 
    {
      std::cout << test.TopDog().PetType() << ":" << test.TopDog().Name() << std::endl;
      test.PopDog();
    }
    std::cout << test.Count() << std::endl;
    std::cout << "DogSize:" << test.DogSize() << std::endl;
    std::cout << "CatSize:" <<test.CatSize() << std::endl;
    std::cout << "Empty:" << test.Empty() << std::endl;
    std::cout << "EmptyDog:" << test.EmptyDog() << std::endl;
    std::cout << "EmptyCat:" << test.EmptyCat() << std::endl;
    while (!test.Empty()) 
    {
      std::cout << test.TopAll().PetType() << ":" << test.TopAll().Name() << std::endl;
      test.PopAll();
    }
  }
  catch(std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }
  
  return 0;
}
