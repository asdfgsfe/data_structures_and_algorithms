��ĸ��λ�ʷ���
����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����

ʾ��:

����: ["eat", "tea", "tan", "ate", "nat", "bat"]
���:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
˵����

���������ΪСд��ĸ��
�����Ǵ������˳��

���ߣ����� (LeetCode)
���ӣ�https://leetcode-cn.com/leetbook/read/hash-table/xxo631/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.empty())
		{
			return {};
		}
		unordered_map<string, vector<string>> records;
		for (const string& str : strs)
		{
			int build[26];
            memset(build, 0, sizeof build);
			for (char ch : str)
			{
				++build[ch - 'a'];
			}
			string pattern;
			for (int i = 0; i < 26; ++i)
			{
				pattern += "_" + std::to_string(build[i]);
				//��֪��Ϊɶ���ܹ� �������ڴ泬��������
				//pattern += (i + 'a ') + "_" + std::to_string(build[i]) + "_";
			}
			records[pattern].emplace_back(str);
		}
		vector<vector<string>> groups;
		for (auto& record : records)
		{
			groups.emplace_back(std::move(record.second));
		}
		return groups;
	}
};

//����ac�汾
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }
        unordered_map<string, vector<string>> words;
        for (const auto& str : strs) {
            vector<int> builder(26, 0);
            for (char c : str) {
                ++builder[c - 'a'];
            }
            string tmp;
            for (int i = 0; i < builder.size(); ++i) {
                tmp.push_back(builder[i] + 'a');
                tmp.push_back('_');
            }
            words[std::move(tmp)].emplace_back(str);
        }
        vector<vector<string>> rets;
        for (auto& word : words) {
            rets.emplace_back(std::move(word.second));
        }
        return rets;
    }
};
