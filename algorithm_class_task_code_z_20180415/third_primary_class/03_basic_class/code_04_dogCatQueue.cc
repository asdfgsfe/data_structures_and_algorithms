#include <iostream>
#include <deque>
#include <string>
#include <deque>
#include <memory>

class Pet
{
public:
    Pet(const std::string& type)
        : type_(type)
    {

    }

    virtual std::string Type() const
    {
        return type_;
    }

private:
    std::string type_;
};

class Dog : public Pet
{
public:
    Dog(const std::string& name)
        : Pet(name)
    {
        
    }

    std::string Type() const
    {
        return std::string ("dog");
    }

};

class Cat : public Pet
{
public:
    Cat(const std::string& name) 
        : Pet(name)
    {
        
    }

    std::string Type() const
    {
        return std::string ("cat");
    }
};


class Pet;
class PetEnterQueue
{
public:
    PetEnterQueue(const std::shared_ptr<Pet>& pet, long count)
        : pet_(pet), count_(count)
    {

    }
    
    const long Count() const
    {
        return count_;
    }

    std::string Type() const
    {
        return pet_->Type();
    }

    std::shared_ptr<Pet> GetPet() const
    {
        return pet_;
    }

private:
    std::shared_ptr<Pet> pet_;
    long count_;
};


class DogCatQueue
{
public:
    DogCatQueue()
        : count_(0)
    {
        
    }

    void Add(const std::shared_ptr<Pet>& pet)
    {
        if (pet->Type().compare("dog") == 0)
        {
            std::shared_ptr<PetEnterQueue> tmpPtr(new PetEnterQueue(pet, ++count_));
            dogQue_.push_back(tmpPtr);
        }
        else if (pet->Type().compare("cat") == 0)
        {
            std::shared_ptr<PetEnterQueue> tmpPtr(new PetEnterQueue(pet, ++count_));
            catQue_.push_back(tmpPtr);
        }
    }

    Pet PollAll()
    {
        if (!dogQue_.empty() && !catQue_.empty())
        {
            if (dogQue_.front()->Count() < catQue_.front()->Count())
            {
                return GetDogAndPop();
            }
            else
            {
                return GetCatAndPop();
            }
        }
        else if (!dogQue_.empty())
        {
            return GetDogAndPop();
        }
        else if (!catQue_.empty())
        {
            return GetCatAndPop();
        }

        return Pet("unknowType");
    }

    Pet PollDog()
    {
        if (!dogQue_.empty())
        {
            return GetDogAndPop();
        }

        return Pet("unknowType");
    }
    
    Pet PollCat()
    {
        if (!catQue_.empty())
        {
            return GetCatAndPop();
        }

        return Pet("nukonwType");
    }

    bool IsEmpty() const
    {
        return dogQue_.empty() && catQue_.empty();
    }


    bool IsDogEmpty() const
    {
        return dogQue_.empty();
    }

    bool IsCatEmpty() const
    {
        return catQue_.empty();
    }

private:
    Pet& GetCatAndPop()
    {
        std::shared_ptr<Pet> tmp = catQue_.front()->GetPet();
        catQue_.pop_front();
        return *(tmp.get());
    }

    Pet& GetDogAndPop()
    {
        std::shared_ptr<Pet> tmp = dogQue_.front()->GetPet();
        dogQue_.pop_front();
        return *(tmp.get());
    }

    std::deque<std::shared_ptr<PetEnterQueue> > dogQue_;
    std::deque<std::shared_ptr<PetEnterQueue> > catQue_;
    long count_;
};


int main(void)
{
    DogCatQueue test;

    std::shared_ptr<Pet> dog1(new Dog("dog1"));
    std::shared_ptr<Pet> dog2(new Dog("dog2"));
    std::shared_ptr<Pet> dog3(new Dog("dog3"));

    std::shared_ptr<Pet> cat1(new Cat("cat1"));
    std::shared_ptr<Pet> cat2(new Cat("cat2"));
    std::shared_ptr<Pet> cat3(new Cat("cat3"));

    test.Add(dog1);
    test.Add(dog2);
    test.Add(dog3);
    test.Add(cat1);
    test.Add(cat2);
    test.Add(cat3);

    test.Add(dog1);
    test.Add(cat1);
    test.Add(dog2);
    test.Add(cat2);
    test.Add(dog3);
    test.Add(cat3);

    
    //while (!test.IsDogEmpty())
      //  std::cout << test.PollDog().Type() << std::endl;

    while (!test.IsEmpty())
        std::cout << test.PollAll().Type() << std::endl;

    return 0;
}
