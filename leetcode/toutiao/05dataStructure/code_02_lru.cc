class LRUCache {
public:
    LRUCache(int capacity) 
        : capacity_(capacity), listHead_(), keyToNodes_()
    {

    }
    
    int get(int key) 
    {
        auto node = keyToNodes_.find(key);
        if (node == keyToNodes_.end())
        {
            return -1;
        }
        listHead_.MoveNodeToTail(node->second);
        assert(node->second);
        return node->second->val;
    }
    
    void put(int key, int value) 
    {
        auto node = keyToNodes_.find(key);
        if (node != keyToNodes_.end())
        {
            listHead_.MoveNodeToTail(node->second);
            assert(node->second);
            node->second->val = value;
        }
        else
        {
            Node* cur = new Node(key, value);
            listHead_.AddNode(cur);
            keyToNodes_[key] = cur;
            if (keyToNodes_.size() > capacity_)
            {
                Node* unused = listHead_.RemoveHead();
                assert(unused);
                keyToNodes_.erase(unused->key);
                delete unused;
            }
        }
    }

    struct Node
    {
        Node(int k, int v)
            : key(k), val(v), next(nullptr), pre(nullptr)
        {}
        int key;
        int val;
        Node* next;
        Node* pre;
    };
    
    class DoubleList
    {
    public:
        DoubleList()
            : head_(nullptr), tail_(nullptr)
            {}
        
        void AddNode(Node* node)
        {
            if (!node)
            {
                return;
            }
            if (!head_)
            {
                head_ = node;
                tail_ = node;
            }
            else
            {
                node->pre = tail_;
                tail_->next = node;
                tail_ = node;
            }
        }
        
        Node* RemoveHead()
        {
            Node* node = head_;
            if (head_ == tail_)
            {
                head_ = nullptr;
                tail_ = nullptr;
            }
            else 
            {
                head_ = head_->next;
                head_->pre = nullptr;
                node->next = nullptr;
            }
            return node;
        }
        
        void MoveNodeToTail(Node* node)
        {
            if (!node || node == tail_)
            {
                return;
            }
            assert(head_ != tail_);
            if (node == head_)
            {
                head_ = head_->next;
                head_->pre = nullptr;
            }
            else
            {
                assert(node->pre);
                node->pre->next = node->next;
                assert(node->next);
                node->next->pre = node->pre;
            }
            tail_->next = node;
            node->pre = tail_;
            node->next = nullptr;
            tail_ = node;
        }
        
    private:
        Node* head_;
        Node* tail_;
    };
private:
    int capacity_;
    DoubleList listHead_;
    unordered_map<int, Node*> keyToNodes_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
