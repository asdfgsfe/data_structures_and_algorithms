class MyLinkedList {
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int v) : val(v), next(nullptr) {}
	};

public:
	/** Initialize your data structure here. */
	MyLinkedList() : size_(0), head_(nullptr) {

	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= size_)
		{
			return -1;
		}
		ListNode* node = head_;
		for (int i = 0; i < index; ++i)
		{
			assert(node);
			node = node->next;
		}
		return node ? node->val : -1;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode* node = new ListNode(val);
		node->next = head_;
		head_ = node;
		++size_;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (!head_)
		{
			head_ = new ListNode(val);
			++size_;
			return;
		}
		ListNode* node = head_;
		while (node && node->next)
		{
			node = node->next;
		}
		node->next = new ListNode(val);
		++size_;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index > size_)
		{
			return;
		}
		if (index <= 0)
		{
			addAtHead(val);
			return;
		}
		ListNode* node = head_;
		for (int i = 0; i < index - 1; ++i)
		{
			assert(node);
			node = node->next;
		}
		ListNode* add = new ListNode(val);
        assert(node);
		add->next = node->next;
		node->next = add;
		++size_;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index >= size_)
		{
			return;
		}
		if (index == 0)
		{
			ListNode* delNode = head_;
			head_ = head_->next;
			--size_;
			delete delNode;
			return;
		}
		ListNode* node = head_;
		for (int i = 0; i < index - 1; ++i)
		{
			assert(node);
			node = node->next;
		}
		ListNode* delNode = node->next;
		assert(delNode);
		node->next = delNode->next;
        --size_;
		delete delNode;
	}

	int size_;
	ListNode* head_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


//  �������
//��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val �� next��
//val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/���á�
//���Ҫʹ��˫����������Ҫһ������ prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0-index �ġ�

//����������ʵ����Щ���ܣ�

//get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
//addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
//addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
//addAtIndex(index,val)���������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣
//��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣
//���indexС��0������ͷ������ڵ㡣
//deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣
 

//ʾ����

//MyLinkedList linkedList = new MyLinkedList();
//linkedList.addAtHead(1);
//linkedList.addAtTail(3);
//linkedList.addAtIndex(1,2);   //�����Ϊ1-> 2-> 3
//linkedList.get(1);            //����2
//linkedList.deleteAtIndex(1);  //����������1-> 3
//linkedList.get(1);            //����3
 

//��ʾ��

//����valֵ���� [1, 1000] ֮�ڡ�
//������������  [1, 1000] ֮�ڡ�
//�벻Ҫʹ�����õ� LinkedList �⡣