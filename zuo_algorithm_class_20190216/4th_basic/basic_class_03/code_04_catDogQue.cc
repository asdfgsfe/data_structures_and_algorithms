class Pet
{
public:
	Pet(const string& type)
		: type_(type)
	{}

	virtual const string& Type() const = 0;
	virtual ~Pet() {}

private:
	string type_;
};


class Dog : public Pet
{
public: 
	Dog()
		: Pet("Dog")
	{}

	virtual const string& Type() const
	{
		return type_;
	}
};

class Cat : public Pet
{
public:
	Cat()
		 : Pet("Cat")
	{}

	virtual const string& Type() const
	{
		return type_;
	}
};

class PetEnterQue : boost::noncopyable
{
public:
	PetEnterQue(int id, const Pet* pet)
		: curId_(id), pet_(pet)
	{}

private:
	int curId_;
	const Pet* pet_;
	//std::unique<Pet> pet_; fix
};

class DogCatQue
{
public:
	DogCatQue()
		: count_(0)
	{}
	
	void Push(const Pet* pet)
	{
		const string& type = pet->Type();
		switch (type)
		{
		case "Cat" :
			cats_.push(new PetEnterQue(count_++, pet));	
			break;
		case "Dog" :
			dogs_.push(new PetEnterQue(count_++, pet));
			break;
		default:
			break;
		}
	}

	const Pet* PollCat()
	{
		assert(!CatsEmpty());
		const Pet* cat = cats.front();
		cats.pop();
		return cat;
	}

	const Pet* PollDog()
	{
		assert(!DogsEmpty());
		const Pet* dog = dogs.front();
		dogs.pop();
		return dog;
	}

	const Pet* PollAll()
	{
		assert(!IsEmpty());
		if (DogsEmpty())
		{
			return PollCat();
		}
		if (CatsEmpty())
		{
			return PollDog();
		}
		if (cats.front() > dogs.front())
		{
			return PollCat();
		}
		return PollDog();
	}

	bool DogsEmpty() const
	{
		return dogs.empty();
	}
	bool CatsEmpty() const
	{
		return cats.empty();
	}
	bool Empty() const
	{
		return cats.empty() && dogs,empty();
	}
	
private:
	int count_;
	queue<const PetEnterQue*> cats_;
	queue<const PetEnterQue*> dogs_;
};