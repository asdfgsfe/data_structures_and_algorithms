//不知道哪里有错误 不能Ac
class MyHashSet {
public:
	struct ListNode
	{
		int key;
		ListNode* next;
		ListNode(int v) : key(v), next(nullptr) {}
	};
	/** Initialize your data structure here. */
	MyHashSet()
		: buckets_(10000)
	{
		for (int i = 0; i < buckets_; ++i)
		{
			nodes_[i] = nullptr;
		}
	}

	void add(int key) {
		if (contains(key))
		{
			return;
		}
		int bucket = key % buckets_;
		ListNode* node = new ListNode(key);
		if (nodes_[bucket])
		{
			node->next = nodes_[bucket];
		}
		nodes_[bucket] = node;
	}

	void remove(int key) {
		int bucket = key % buckets_;
		if (!nodes_[bucket])
		{
			return;
		}
		ListNode* head = nodes_[bucket];
		while (head && head->key != key)
		{
				head = head->next;
		}
		if (!head)
		{
			return;
		}
		if (head == nodes_[bucket] || !head->next)
		{
			nodes_[bucket] = head == nodes_[bucket] ? head->next : nodes_[bucket];
			delete head;
			head = nullptr;
		}
		else
		{
			ListNode* delNode = head->next;
			head->key = head->next->key;
			head->next = head->next->next;
            head->next = nullptr;
			delete delNode;
			delNode = nullptr;
		}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		int bucket = key % buckets_;
		if (!nodes_[bucket])
		{
			return false;
		}
		ListNode* head = nodes_[bucket];
		while (head)
		{
			if (head->key == key)
			{
				return true;
			}
			head = head->next;
		}
		return false;
	}
private:
	const int buckets_;
	ListNode* nodes_[10000];
};