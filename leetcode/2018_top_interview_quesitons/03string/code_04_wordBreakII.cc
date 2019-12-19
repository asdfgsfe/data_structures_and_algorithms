//方法 1：暴力
//算法
//解决此题最简单的方法是使用回溯。
//为了找到解，我们检查字符串（s）的所有可能前缀是否在字典中，
//如果在（比方说 s1），那么调用回溯函数并检查剩余部分的字符串。
//如果剩余部分可以形成有效拆分，这个函数返回前缀 s1，
//并将回溯调用的剩余结果（即 s-s1）跟在 s1的后面。否则，返回空列表。

 class Solution {
 public:
	 vector<string> wordBreak(string s, vector<string>& wordDict) {
		 unordered_set<string> dict;
		 for (string& word : wordDict)
		 {
			 dict.emplace(std::move(word));
		 }
		 return BreakProcess(s, 0, dict);
	 }

	 vector<string> BreakProcess(const string& str, int i, const unordered_set<string>& dict)
	 {
		 vector<string> words;
		 if (i == str.size())
		 {
			 //核心的地方在这里 如果不能分割就返回空 一直返回下去 注意这个地方不retrun的优点
			 words.emplace_back(string());
		 }
		 for (int s = i; s < str.size(); ++s)
		 {
			 string word = str.substr(i, s - i + 1);
			 if (dict.count(word))
			 {
				 vector<string> nextWords = BreakProcess(str, s + 1, dict);
				 for (string& next : nextWords)
				 {
					 words.emplace_back(word + (next.empty() ? string() : string(" ")) + std::move(next));
				 }
			 }
		 }
		 return words;
	 }
 };


//c++记忆话搜索的方法
 class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        string s1;
        vector<string>word;
        if (s.size()>100)
            return word;
        vector<string> c;
        wordmatch(s,wordDict,s1,word,c);
        return word;
    }
    void wordmatch(string s,vector<string>& wordDict,string s1,vector<string>& word,vector<string>& c){
    // if(find(c.begin(),c.end(),s)!=c.end())
    //     return;
    // bool flag=true;
    for(int j=0;j<wordDict.size();j++)
    {
        if(s.substr(0,wordDict[j].size()).compare(wordDict[j])==0)
        {
            if(s.size()==wordDict[j].size()){
                string b;
                b=s1+wordDict[j];
                word.push_back(b);
                // flag=false;
                continue;
            }
            string a;
            a=s1+wordDict[j]+" ";
            wordmatch(s.substr(wordDict[j].size()),wordDict,a,word,c);
            // flag=false;

        }
    }
    // if(flag)
    //     c.push_back(s);
    return ;
}
};

//动态规划 但是不能ac 不知道为啥
public class Solution {
   public List<String> wordBreak(String s, Set<String> wordDict) {
       LinkedList<String>[] dp = new LinkedList[s.length() + 1];
       LinkedList<String> initial = new LinkedList<>();
       initial.add("");
       dp[0] = initial;
       for (int i = 1; i <= s.length(); i++) {
           LinkedList<String> list = new LinkedList<>();
           for (int j = 0; j < i; j++) {
               if (dp[j].size() > 0 && wordDict.contains(s.substring(j, i))) {
                   for (String l : dp[j]) {
                       list.add(l + (l.equals("") ? "" : " ") + s.substring(j, i));
                   }
               }
           }
           dp[i] = list;
       }
       return dp[s.length()];
   }
}

//c++ dp不能ac
 class Solution {
 public:
	 vector<string> wordBreak(string s, vector<string>& wordDict) {
		 unordered_set<string> dict;
		 for (string& word : wordDict)
		 {
			 dict.emplace(std::move(word));
		 }
		 vector<vector<string>> dp(s.size() + 1);
		 dp[0] = vector<string>(1, "");
		 for (int i = 1; i < dp.size(); ++i)
		 {
			 vector<string> words;
			 for (int j = 0; j < i; ++j)
			 {
				 if (!dp[j].empty() && dict.count(s.substr(j, i - j)))
				 {
					 for (string& word : dp[j])
					 {
						 words.emplace_back(std::move(word)  + (word.empty() ? "" : " ") + s.substr(j, i - j));
					 }
				 }
			 }
			 dp[i] = words;
		 }
		 return dp.back();
	 }
 };