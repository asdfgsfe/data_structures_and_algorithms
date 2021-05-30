class LRUCache {
    
    struct ListNode
    {
        int key;
        int val;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode() = default;
        ListNode(int k, int v)
            : key(k), val(v), next(nullptr), prev(nullptr)
            {
                
            }
    };
    
    class List
    {
    public:
        void AddNode(ListNode* node)
        {
            if (!node)
            {
                return;
            }
            if (!head_)
            {
                assert(!tail_);
                head_ = node;
                tail_ = node;
                return;
            }
            tail_->next = node;
            node->prev = tail_;
            tail_ = node;
        }
        
        void MoveNodeToTail(ListNode* node)
        {
            if (!node || !head_ || !tail_ || head_ == tail_ || tail_ == node)
            {
                return;
            }
            if (head_ == node)
            {
                head_ = head_->next;
                head_->prev = nullptr;
                tail_->next = node;
                node->prev = tail_;
                node->next = nullptr;
                tail_ = node;
                return;
            }
            node->prev->next = node->next;
            node->next->prev = node->prev;
            tail_->next = node;
            node->prev = tail_;
            node->next = nullptr;
            tail_ = node;
        }
        
        ListNode* RemoveHeadNode()
        {
            if (!head_)
            {
                assert(!tail_);
                return nullptr;
            }
            ListNode* tmp = head_;
            if (head_ == tail_)
            {
                head_ = nullptr;
                tail_ = nullptr;
                return tmp;
            }
            head_ = head_->next;
            head_->prev = nullptr;
            return tmp;
        }
        
    private:
        ListNode* head_ = nullptr;
        ListNode* tail_ = nullptr;
    };
    
public:
    LRUCache(int capacity) 
        : capacity_(capacity),
          data_(),
          timeAxis_()
    {
                
    }
    
    int get(int key) {
        if (!data_.count(key))
        {
            return -1;
        }
        ListNode* node = data_[key];
        timeAxis_.MoveNodeToTail(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (data_.count(key))
        {
            ListNode* node = data_[key];
            node->val = value;
            timeAxis_.MoveNodeToTail(node);
            return;
        }
        ListNode* node = new ListNode(key, value);
        timeAxis_.AddNode(node);
        data_[key] = node;
        if (data_.size() <= capacity_)
        {
            return;
        }
        ListNode* deleteNode = timeAxis_.RemoveHeadNode();
        assert(data_.count(deleteNode->key));
        data_.erase(deleteNode->key);
        delete deleteNode;
    }
    
private:
    const int capacity_;
    unordered_map<int, ListNode*> data_;
    List timeAxis_; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/tencent/x57w6h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
