//���� 1������
//�㷨
//���������򵥵ķ�����ʹ�û��ݡ�
//Ϊ���ҵ��⣬���Ǽ���ַ�����s�������п���ǰ׺�Ƿ����ֵ��У�
//����ڣ��ȷ�˵ s1������ô���û��ݺ��������ʣ�ಿ�ֵ��ַ�����
//���ʣ�ಿ�ֿ����γ���Ч��֣������������ǰ׺ s1��
//�������ݵ��õ�ʣ�������� s-s1������ s1�ĺ��档���򣬷��ؿ��б�

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
			 //���ĵĵط������� ������ָܷ�ͷ��ؿ� һֱ������ȥ ע������ط���retrun���ŵ�
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


//c++���仰�����ķ���
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

//��̬�滮 ���ǲ���ac ��֪��Ϊɶ
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

//c++ dp����ac
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