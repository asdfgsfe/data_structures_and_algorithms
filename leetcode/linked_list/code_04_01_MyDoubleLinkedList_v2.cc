//不同点在于定义了 tail指针

class MyLinkedList {
struct ListNode {
    int val;
    ListNode* next;
    ListNode* pre;

    ListNode(int v) : val(v), next(nullptr), pre(nullptr) {}
};

public:
    /** Initialize your data structure here. */
    MyLinkedList() {

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size_) {
            return -1;
        }
        ListNode* node = head_;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
        return node ? node->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        ++size_;
        if (!head_) {
            head_ = node;
            tail_= head_;
            return;
        }
        node->next = head_;
        head_->pre = node;
        head_ = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ++size_;
        if (!head_) {
            head_ = node;
            tail_ = node;
            return;
        }
        tail_->next = node;
        node->pre = tail_;
        tail_ = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size_) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index == size_) {
            addAtTail(val);
            return;
        }
        ListNode* node = head_;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = node;
        newNode->pre = node->pre;
        node->pre->next = newNode;
        node->pre = newNode;
        ++size_;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size_) {
            return;
        }
        if (head_ == tail_) {
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
            --size_;
            return;
        }
        if (index == 0) {
            ListNode* tmp = head_;
            head_ = head_->next;
            head_->pre = nullptr;
            delete tmp;
            --size_;
            return;
        }
        if (index == size_ - 1) {
            ListNode* tmp = tail_;
            tail_ = tail_->pre;
            tail_->next = nullptr;
            tmp->pre = nullptr;
            delete tmp;
            --size_;
            return;
        }
        ListNode* node = head_;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = nullptr;
        node->pre = nullptr;
        delete node;
        --size_;
    }

    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

private:
    ListNode* head_ = nullptr;
    ListNode* tail_ = nullptr;
    int size_ = 0;
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
