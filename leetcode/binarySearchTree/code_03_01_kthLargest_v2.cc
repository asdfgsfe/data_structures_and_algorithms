数据流中的第K大元素
设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：

KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
 

示例：

输入：
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
输出：
[null, 4, 5, 5, 8, 8]

解释：
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
 

提示：
1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
最多调用 add 方法 104 次
题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素
相关标签
堆
设计

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xpjovh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : data_(nums), k_(k) {
        //有可能数组当前的数字小于k
        int n = data_.size() > k_ ? k_ : data_.size();
        for (int i = n / 2; i >= 0; --i) {
            Percdown(data_, i, n);
        }
        //如果数组的数量多于k个 这里就是求topk
        for (int i = k_; i < data_.size(); ++i) {
            if (data_[i] > data_[0]) {
                std::swap(data_[i], data_[0]);
                Percdown(data_, 0, k_);
            }
        }
    }

    int add(int val) {
        data_.push_back(val);
        //data_.size() <= k_必须是<=
        if (val > data_[0] || data_.size() <= k_) {
            std::swap(data_[0], data_[data_.size() - 1]);
            Percdown(data_, 0, data_.size() > k_ ? k_ : data_.size());
        }
        return data_[0];
    }

private:
    void Percdown(vector<int>& data, int i, int n) {
        int child = 2 * i + 1;
        while (child < n) {
            if (child + 1 != n && data[child + 1] < data[child]) {
                ++child;
            }
            if (data[i] < data[child]) {
                return;
            }
            std::swap(data[i], data[child]);
            i = child;
            child = 2 * i + 1;
        }
    }

private:
    vector<int> data_;
    const int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
