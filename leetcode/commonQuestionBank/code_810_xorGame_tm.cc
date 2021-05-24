class Solution {
public:
    //超时
    bool xorGame(vector<int>& nums) {
        return AProcess(nums);
    }

    bool AProcess(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum ^= n;
        }
        if (sum == 0) {
            return true;
        }
        for (int i = 0; i < nums.size(); ++i) {
            sum ^= nums[i];
            if (sum != 0) {
                vector<int> tmp(nums.begin(), nums.begin() + i);
                tmp.insert(tmp.end(), nums.begin() + i + 1, nums.end());
                if (!BProcess(tmp)) {
                    return true;
                }
            }
            sum ^= nums[i];
        }
        return false;
    }

        bool BProcess(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum ^= n;
        }
        if (sum == 0) {
            return true;
        }
        for (int i = 0; i < nums.size(); ++i) {
            sum ^= nums[i];
            if (sum != 0) {
                vector<int> tmp(nums.begin(), nums.begin() + i);
                tmp.insert(tmp.end(), nums.begin() + i + 1, nums.end());
                if (!AProcess(tmp)) {
                    return true;
                }
            }
            sum ^= nums[i];
        }
        return false;
    }
};

//答案错误 但是感觉是对的 动态规划
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum ^= n;
        }
        if (sum == 0) {
            return true;
        }
        return AProcess(nums, 0, nums.size() - 1, sum);
    }

    bool AProcess(vector<int>& nums, int l, int r, int sum) {
        if (l > r || sum == 0) {
            return true;
        }
        // if (l > r) {
        //     return false;
        // }
        for (int i = l; i <= r; ++i) {
            sum ^= nums[i];
            if (sum != 0) {
                if (!BProcess(nums, l, i - 1, sum) || !BProcess(nums, i + 1, r, sum)) {
                    return true;
                }
            }
            sum ^= nums[i];
        }
        return false;
    }

    bool BProcess(vector<int>& nums, int l, int r, int sum) {
        if (l > r || sum == 0) {
            return true;
        }
        // if (l > r) {
        //     return false;
        // }
        for (int i = l; i <= r; ++i) {
            sum ^= nums[i];
            if (sum != 0) {
                if (!AProcess(nums, l, i - 1, sum) || !AProcess(nums, i + 1, r, sum)) {
                    return true;
                }
            }
            sum ^= nums[i];
        }
        return false;
    }
 
};


//官方答案
class Solution {
    public boolean xorGame(int[] nums) {
        if (nums.length % 2 == 0) {
            return true;
        }
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        return xor == 0;
    }
}


810. 黑板异或游戏
黑板上写着一个非负整数数组 nums[i] 。Alice 和 Bob 轮流从黑板上擦掉一个数字，Alice 先手。如果擦除一个数字后，剩余的所有数字按位异或运算得出的结果等于 0 的话，当前玩家游戏失败。 (另外，如果只剩一个数字，按位异或运算得到它本身；如果无数字剩余，按位异或运算结果为 0。）

换种说法就是，轮到某个玩家时，如果当前黑板上所有数字按位异或运算结果等于 0，这个玩家获胜。

假设两个玩家每步都使用最优解，当且仅当 Alice 获胜时返回 true。



示例：

输入: nums = [1, 1, 2]
输出: false
解释:
Alice 有两个选择: 擦掉数字 1 或 2。
如果擦掉 1, 数组变成 [1, 2]。剩余数字按位异或得到 1 XOR 2 = 3。那么 Bob 可以擦掉任意数字，因为 Alice 会成为擦掉最后一个数字的人，她总是会输。
如果 Alice 擦掉 2，那么数组变成[1, 1]。剩余数字按位异或得到 1 XOR 1 = 0。Alice 仍然会输掉游戏。


提示：

1 <= N <= 1000
0 <= nums[i] <= 2^16
