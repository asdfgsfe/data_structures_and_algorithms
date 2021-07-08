class LRUCache {
struct ListNode {
    int key;
    int val;
    ListNode* pre;
    ListNode* next;

    ListNode(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {}
};

struct DoubleList {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    void AddNode(ListNode* node) {
        if (!node) {
            return;
        }
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->pre = tail;
            tail = node;
        }
    }

    void MoveToTail(ListNode* node) {
        if (!head || head == tail || tail == node) {
            return;
        }
        if (head == node) {
            head = head->next;
            head->pre = nullptr;
        } else {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        tail->next = node;
        node->pre = tail;
        tail = node;
        node->next = nullptr;
    }

    ListNode* DeleteHead() {
        if (!head) {
            return nullptr;
        }
        ListNode* tmp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->pre = nullptr;
            tmp->next = nullptr;
        }
        return tmp;
    }
};

public:
    LRUCache(int capacity) : capacity_(capacity) {

    }
    
    int get(int key) {
        auto it =  nodes_.find(key);
        if (it == nodes_.end()) {
            return -1;
        }
        list_.MoveToTail(it->second);
        return it->second->val;
    }
    
    void put(int key, int value) {
        auto it = nodes_.find(key);
        if (it != nodes_.end()) {
            it->second->val = value;
            list_.MoveToTail(it->second);
            return;
        }
        ListNode* node = new ListNode(key, value);
        list_.AddNode(node);
        nodes_[key] = node;
        if (nodes_.size() <= capacity_) {
            return;
        }
        ListNode* deleteNode = list_.DeleteHead();
        nodes_.erase(deleteNode->key);
        delete deleteNode;
    }

private:
    unordered_map<int, ListNode*> nodes_;
    DoubleList list_;
    const int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
