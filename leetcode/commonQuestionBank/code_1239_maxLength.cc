1239. 串联字符串的最大长度
给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。

请返回所有可行解 s 中最长长度。

 

示例 1：

输入：arr = ["un","iq","ue"]
输出：4
解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
示例 2：

输入：arr = ["cha","r","act","ers"]
输出：6
解释：可能的解答有 "chaers" 和 "acters"。
示例 3：

输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
输出：26
 

提示：

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] 中只含有小写英文字母

class Solution {
public:
    int maxLength(vector<string>& arr) {
        if (arr.empty()) {
            return 0;
        }
        vector<int> chars(26, 0);
        return MaxProcess(arr, 0, chars, 0);
    }

	//数组的子序列操作 要当前值与不要当前值 然后选择最大的、
	//for 利用回溯的手法 来递归
	//chars用于去重复
	//从顶层到底的计算长度
    int MaxProcess(const vector<string>& arr, int i, vector<int>& chars, int len) {
        if (i == arr.size()) {
            return len;
        }
        int outLen = MaxProcess(arr, i + 1, chars, len);
        for (int j = 0; j < arr[i].size(); ++j) {
            if (chars[arr[i][j] - 'a'] == 0) {
                chars[arr[i][j] - 'a'] = 1;
                continue;
            }
            for (int k = 0; k < j; ++k) {
                chars[arr[i][k] - 'a'] = 0;
            }
            return outLen;
        }
        int inLen = MaxProcess(arr, i + 1, chars, len + arr[i].size());
        for (int j = 0; j < arr[i].size(); ++j) {
            chars[arr[i][j] - 'a'] = 0;
        }
        return std::max(outLen, inLen);
    }
};
