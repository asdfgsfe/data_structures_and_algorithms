宝石与石头
 给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。

示例 1:

输入: J = "aA", S = "aAAbbbb"
输出: 3
示例 2:

输入: J = "z", S = "ZZ"
输出: 0
注意:

S 和 J 最多含有50个字母。
 J 中的字符不重复。
相关标签
哈希表
字符串

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xx2a0c/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if (J.empty() || S.empty())
        {
            return 0;
        }
        vector<int> charNums(256, 0);
        for (char ch : S)
        {
            ++charNums[ch];
        }
        int cnt = 0;
        for (char ch : J)
        {
            cnt += charNums[ch];
        }
        return cnt;
    }
};

//hash表
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        if (jewels.empty() || stones.empty()) {
            return 0;
        }
        unordered_set<int> jewelGroup;
        for (char c : jewels) {
            jewelGroup.emplace(c);
        }
        int n = 0;
        for (char c : stones) {
            if (jewelGroup.count(c)) {
                ++n;
            }
        }
        return n;
    }
};
