设计哈希映射
不使用任何内建的哈希表库设计一个哈希映射（HashMap）。

实现 MyHashMap 类：

MyHashMap() 用空映射初始化对象
void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xhqwd3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class MyHashMap {
struct Node {
    int val;
    int key;
    Node* next;

    Node(int v, int k) : val(v), key(k), next(nullptr) {}
};

public:
    /** Initialize your data structure here. */
    MyHashMap() : data_(100000, nullptr){

    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int i = key % data_.size();
        Node* node = data_[i];
        while (node) {
            if (node->key == key) {
                node->val = value;
                return;
            }
            node = node->next;
        }
        Node* tmp = new Node(value, key);
        tmp->next = data_[i];
        data_[i] = tmp;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int i = key % data_.size();
        Node* node = data_[i];
        while (node) {
            if (node->key == key) {
                return node->val;
            }
            node = node->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int i = key % data_.size();
        if (!data_[i]) {
            return;
        }
        if (data_[i]->key == key) {
            Node* node = data_[i];
            data_[i] = data_[i]->next;
            node->next = nullptr;
            delete node;
            return;
        }
        Node* node = data_[i];
        while (node && node->key != key) {
            node = node->next;
        }
        if (!node) {
            return;
        }
        if (!node->next) {
            delete node;
            node = nullptr;
            return;
        }
        Node* deleteNode = node->next;
        node->key = node->next->key;
        node->val = node->next->val;
        node->next = node->next->next;
        delete deleteNode;
    }

private:
    vector<Node*> data_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
