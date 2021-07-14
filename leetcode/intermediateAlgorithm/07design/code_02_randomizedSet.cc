class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (data_.count(val)) {
            return false;
        }
        int size = data_.size();
        data_[val] = size;
        help_[size] = val;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!data_.count(val)) {
            return false;
        }
        assert(data_.size() == help_.size());
        int lastId = data_.size() - 1;
        int deleteId = data_[val];
        int lastVal = help_[lastId];
        help_[deleteId] = lastVal;
        data_[lastVal] = deleteId;
        data_.erase(val);
        help_.erase(lastId);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int id = rand() % data_.size();
        return help_[id];
    }

private:
    unordered_map<int, int> data_;
    unordered_map<int, int> help_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

常数时间插入、删除和获取随机元素
设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。

insert(val)：当元素 val 不存在时，向集合中插入该项。
remove(val)：元素 val 存在时，从集合中移除该项。
getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xw5rt1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
