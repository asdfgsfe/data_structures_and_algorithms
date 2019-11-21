/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
	struct ReturnData
	{
		Node* head;
		Node* tail;
		ReturnData(Node* h, Node* t)
			: head(h), tail(t)
		{}
	};
public:
	Node * childData.tail(Node* head) {
		if (!head)
		{
			return nullptr;
		}
		return FlattenProcess(head).head;
	}

	ReturnData FlattenProcess(Node* head)
	{
		if (!head)
		{
			return ReturnData(nullptr, nullptr);
		}
		Node* node = head;
        Node* pre = nullptr;
		while (node && !node->child)
		{
            pre = node;
			node = node->next;
		}
        if (!node)
        {
            return ReturnData(head, pre);
        }
		Node* child = node->child;
		node->child = nullptr;
		Node* right = node->next;
		ReturnData childData = FlattenProcess(child);
		node->next = childData.head;
		childData.head->prev = node;
		if (right) 
        {
            right->prev = childData.tail;
        }
        if (childData.tail)
        {
		    childData.tail->next = right;
        }
		ReturnData rData = FlattenProcess(right);
		return ReturnData(head, rData.tail);
	}
};