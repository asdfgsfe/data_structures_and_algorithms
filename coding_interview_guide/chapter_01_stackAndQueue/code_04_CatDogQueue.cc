class Pet
{
public:
	Pet(string type)
		: type_(std::move(type))
	{
		
	}

	virtual const string& Type() const
	{
		return type_;
	}

	virtual ~Pet() {}
private:
	string type_;
};

class Cat : public Pet
{
public:
	Cat() 
		: Pet("Cat")
	{}
	
	virtual ~Cat() {}
};

class Dog : public Pet
{
public:
	Dog() 
		: Pet("Dog")
	{}

	virtual ~Dog() {}
};

class PetEnterQue
{
public:
	PetEnterQue(int count, const Pet* pet)
		: count_(count), pet_(pet)
	{}

private:
	int count_;
	Pet* pet_;
};

class CatDogQueue
{
public:
	CatDogQueue()
		: count_(0)
	{}

	void Add(const string& type)
	{
		++count_;
		if (type == "cat")
		{
			Pet* pet = new Cat;
			cats_.push(PetEnterQue(count_, pet));
		}
		else if (type == "dog")
		{
			Pet* pet = new Dog;
			dogs_.push(PetEnterQue(count_, pet));
		}
	}

	Pet* PollDog() const
	{
		assert(!dogEmpty());
		Pet* pet = dogs.front().pet_;
		dogs.pop();
		return pet;
	}

	Pet* PollCat() const
	{
		assert(!catEmpty());
		Pet* pet = cats.fron().pet_;
		cats.pop();
		return pet;
	}

	Pet* PollAll() const
	{
		assert(!Empty());
		if (cats_.empty())
		{
			return PollDog();
		}
		if (dos_.empty())
		{
			return PollCat();
		}
		int catCount = cats.front().count_;
		int dogCount = dogs.front().count_;
		if (catCount < dogsCount)
		{
			Pet* pet = cats.front().pet_;
			cats.pop();
			return pet;
		}
		Pet* pet = dogs.front().pet_;
		dogs.pop();
		return pet;
	}

	bool CatEmpty() const
	{
		return cats_.empty();
	}

	bool DogEmpty() const
	{
		return dogs_.empty();
	
	
	bool Empty() const
	{
		return CatEmpty() && DogEmpty();
	}

private:
	int count_;
	queue<PetQnterQue> cats_;
	queue<PetQnterQue> dogs_;
};
