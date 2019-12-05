class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (valToId.count(val))
		{
			return false;
		}
		assert(valToId.size() == idToVal.size());
		int size = valToId.size();
		valToId[val] = ++size;
		idToVal[size] = val;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		auto delId = valToId.find(val);
		if (delId == valToId.end())
		{
			return false;
		}
		int lastId = valToId.size();
		int lastVal = idToVal[lastId];
		idToVal[delId->second] = lastVal;
		valToId[lastVal] = delId->second;
		valToId.erase(val);
		idToVal.erase(lastId);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		assert(valToId.size() == idToVal.size());
		if (valToId.empty())
		{
			return 0x7fffffff;
		}
		//srand(::time(NULL));
		int id = rand() % valToId.size() + 1;
		assert(idToVal.count(id));
		return idToVal[id];
	}
private:
	unordered_map<int, int> valToId;
	unordered_map<int, int> idToVal;
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet* obj = new RandomizedSet();
* bool param_1 = obj->insert(val);
* bool param_2 = obj->remove(val);
* int param_3 = obj->getRandom();
*/