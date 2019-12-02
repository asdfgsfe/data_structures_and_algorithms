//不能aC感觉是remove函数有问题
class MyHashMap {
public:
	struct ListNode
	{
		int key;
		int val;
		ListNode* next;
		ListNode(int k, int v) : key(k), val(v), next(nullptr) {}
	};
	/** Initialize your data structure here. */
	MyHashMap()
		: buckets_(10000)
	{
		for (int i = 0; i < buckets_; ++i)
		{
			nodes_[i] = nullptr;
		}
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		int bucket = key % buckets_;
		ListNode* head = nodes_[bucket];
		while (head)
		{
			if (head->key == key)
			{
				head->val = value;
				return;
			}
			head = head->next;
		}
		ListNode* node = new ListNode(key, value);
		node->next = nodes_[bucket];
		nodes_[bucket] = node;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int bucket = key % buckets_;
		if (!nodes_[bucket])
		{
			return -1;
		}
		ListNode* head = nodes_[bucket];
		while (head)
		{
			if (head->key == key)
			{
				return head->val;
			}
			head = head->next;
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int bucket = key % buckets_;
		if (!nodes_[bucket])
		{
			return;
		}
		//就是在这里有问题
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
			head->val = head->next->val;
			head->next = head->next->next;
			head->next = nullptr;
			delete delNode;
			delNode = nullptr;
		}
	}

private:
	const int buckets_;
	ListNode* nodes_[10000];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

//参考答案 利用数组解决冲突
 class MyHashMap {
public:
    /** Initialize your data structure here. */
    int a[100000];
    int b[100000]={0};
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        a[key]=value;
        b[key]=1;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(b[key]==0)return -1;
        else return a[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(b[key]==1){
            a[key]=0;
            b[key]=0;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */