//146. LRU 缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


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
                //这行容易丢 注意一定要删除掉节点
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
