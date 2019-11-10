文本左右对齐
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (words.empty() || maxWidth < 1)
        {
            return {};
        }
        vector<string> text;
        int pre = 0;
        int next = 0;
        int width = 0;
        int best = 0;
        while (next < words.size())
        {
            while (next < words.size() && width + words[next].size() + next - pre <= maxWidth)
            {
                width += words[next++].size();
            }
            int lack = maxWidth - width;
            string line;
            while (pre < next)
            {
                line += words[pre];
                if (lack <= 0)
                {
                    ++pre;
                    continue;
                }
                int need = 0;
                if (next == words.size())
                {
                    need = next - pre == 1 ? lack : 1;
                }
                else
                {
                    need = lack;
                    if (next - pre - 1 > 0)
                    {
                        need = lack / (next - pre - 1);
                        need = lack % (next - pre - 1) == 0 ? need : 1 + need;
                    }
                }
                line.append(need, ' ');
                ++pre;
                lack -= need;
            }
            text.emplace_back(std::move(line));
            width = 0;
        }
        return text;
    }
};

