class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) {
			return 0;
        }
		if (k < 2) {
			return s.size();
		}
        int ret = 0;
        //t表示当前窗口中只能有几种类型的字符 1种 2种。。。 固定当前窗口种字符的类型来稿
		for (int t = 1; t <= 26; ++t) {
            int total = 0; //当前窗口实际的总字符类型
            int less = 0; //不满足出现次数大于等于k的字符种类数
            vector<int> cnt(26, 0);
            int l = 0; //窗口左边
            int r = 0; //窗口右边
            while (r < s.size()) { //在字符种类固定的情况下来寻找答案 扩窗口
                ++cnt[s[r] - 'a'];
                if (cnt[s[r] - 'a'] == 1) { //==1表示有新字符加入 total和less均+1
                    ++total;
                    ++less;
                }
                if (cnt[s[r] - 'a'] == k) {
                    //表示新家入的字符满足条件 所以减掉这种字符满足条件统计
                    //由于==1的时候加了1， 所以这个时候必须减1
                    --less;
                }
                //如果当前的字符个数大于固定窗口种的个数 说明窗口整体要向右边移动了
                //移动的目的就是保证 窗口中一定有固定的字符种类t个
                while (total > t) {
                    --cnt[s[l] - 'a'];
                    if (cnt[s[l] - 'a'] == k - 1) { //之前够 通过移动现在不够了
                        ++less;
                    }
                    if (cnt[s[l] - 'a'] == 0) { //全部移除了这种字符
                        --total;
                        --less;
                    }
                    ++l; //右移动
                }
                if (less == 0) { //表示这个窗里面有符合条件的答案
                    ret = std::max(ret, r - l + 1);
                }
                ++r; //右扩
            }
        }
        return ret;
    }
};

至少有K个重复字符的最长子串
给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。

 

示例 1：

输入：s = "aaabb", k = 3
输出：3
解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2：

输入：s = "ababbc", k = 2
输出：5
解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 

提示：

1 <= s.length <= 104
s 仅由小写英文字母组成
1 <= k <= 105

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xafdmc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
