421. 数组中两个数的最大异或值
给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。

进阶：你可以在 O(n) 的时间解决这个问题吗？

 

示例 1：

输入：nums = [3,10,5,25,2,8]
输出：28
解释：最大运算结果是 5 XOR 25 = 28.
示例 2：

输入：nums = [0]
输出：0
示例 3：

输入：nums = [2,4]
输出：6
示例 4：

输入：nums = [8,10,2]
输出：10
示例 5：

输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
输出：127
 

提示：

1 <= nums.length <= 2 * 104
0 <= nums[i] <= 231 - 1
通过次数23,711提交次数38,918

class Solution {
class Trie {
public:
    struct Node {
        int path;
        int end;
        vector<Node*> nexts;

        Node() : path(0), end(0), nexts(2, nullptr) {}
    };

    Trie() : root_(new Node) {}

    void Insert(int n) {
        Node* node = root_;
        for (int i = 31; i >= 0; --i) {
            int path = (n >> i) & 0x01;
            if (!node->nexts[path]) {
                node->nexts[path] = new Node;
            }
            node = node->nexts[path];
            ++node->path;
        }
        ++node->end;
    }

    //其实等于与数组中的每个数字进行了异或运算，
    //因为insert仅仅是将 该数字插入到树中
    int MaxXor(int n) {
        int maxXor = 0;
        Node* node = root_;
        for (int i = 31; i >= 0; --i) {
            int path = (n >> i) & 0x01;
            int best = (i == 31) ? path : path ^ 1;
            best = node->nexts[best] ? best : best ^ 1;
            maxXor |= (best ^ path) << i;
            node = node->nexts[best];
        }
        return maxXor;
    }

private:
    Node* root_;
};


public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.empty()) {
            return 0x80000000;
        }
        Trie trie;
        int maxXor = 0;
        for (int n : nums) {
            trie.Insert(n);
            maxXor = std::max(maxXor, trie.MaxXor(n));
        }
        return maxXor;
    }
};
