//�ٷ���������һ����̬�滮
//��Ȼ�������Ĵ���̣ܶ��������㷨�����Ǻ�������ơ�
//���ǻ��ö�̬�滮��������������е����������У��ٷ��ش�֮ǰ�ټ�ȥ�����С�
//������ dp[k] ��ʾ S[0 .. k] ������ɵĲ�ͬ�����е���Ŀ��
//��� S �е������ַ�������ͬ������ S = "abcx"����ô״̬ת�Ʒ��̾��Ǽ򵥵� dp[k] = dp[k-1] * 2��
//���� dp[2] = 8�������� ("", "a", "b", "c", "ab", "ac", "bc", "abc") �� 8 ����ͬ�������У��� dp[3] 
//����Щ�����е�ĩβ���� x���Ϳ��Եõ������ 8 ����ͬ�������У�
//�� ("x", "ax", "bx", "cx", "abx", "acx", "bcx", "abcx")����� dp[3] = 8 * 2 = 16��
//���� S ������ͬ��ĸ��ʱ�򣬾�Ҫ�����ظ������������ˣ����統 S = "abab" ʱ�������У�
//dp[0] = 2�������� ("", "a")��
//dp[1] = 4�������� ("", "a", "b", "ab")��
//dp[2] = 7�������� ("", "a", "b", "aa", "ab", "ba", "aba")��
//dp[3] = 12�������� ("", "a", "b", "aa", "ab", "ba", "bb", "aab", "aba", "abb", "bab", "abab")��
//���� dp[2] ת�Ƶ� dp[3] ʱ������ֻ���� dp[2] �е� ("b", "aa", "ab", "ba", "aba") ��ĩβ���� b��
//�����Ե� ("", "a")����Ϊ���ǻ�õ��ظ��������С����ǿ��Է��֣������ ("", "a") �պþ��� dp[0]��
//Ҳ������һ������ b ֮ǰ�������м��ϡ�������Ǿ͵õ������µ�״̬ת�Ʒ��̣�
//dp[k] = 2 * dp[k - 1] - dp[last[S[k]] - 1]
//���ڼ��� dp[k] ʱ�����ȻὫ dp[k - 1] ��Ӧ�������е�ĩβ��� S[k] �õ������ dp[k - 1] �������У�
//����ȥ�ظ����ֵ���������Ŀ�������Ŀ��Ϊ��һ����� S[k] ֮ǰ����������Ŀ dp[last[S[k]] - 1]��

//https://leetcode-cn.com/problems/distinct-subsequences-ii/solution/bu-tong-de-zi-xu-lie-ii-by-leetcode/
//�ռ�o(n) ʱ��o(n) ���þ�֤ѹ���������Կռ�����Ż���o(1)
class Solution {
    public int distinctSubseqII(String S) {
        int MOD = 1_000_000_007;
        int N = S.length();
        int[] dp = new int[N+1];
        dp[0] = 1;

        int[] last = new int[26];
        Arrays.fill(last, -1);

        for (int i = 0; i < N; ++i) {
            int x = S.charAt(i) - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if (last[x] >= 0)
                dp[i+1] -= dp[last[x]];
            dp[i+1] %= MOD;
            last[x] = i;
        }

        dp[N]--;
        if (dp[N] < 0) dp[N] += MOD;
        return dp[N];
    }
}

//��������
//���ظ��ַ��ĵ������
// a	2^1 = 2 (�����˿մ�)
// ab	2^2 = 4
// abc  2^3 = 8
//��dp[i] = 2^(i + 1) ����iλ������±� ����dp[i] = 2 * dp[i - 1]

//���ظ��ַ��������
// a	a 2^1 = 2 (�����˿մ�)
// ab	a,b,ab	2^2 = 4
// aba  a,ab,aa,aba,b,ba	����aba������a����� �����ڼ��������еĹ������ظ�������a���������� 
//��last��ʾ�ַ�a�ϴγ����������е�λ�� 
//�� dp[i] = 2 * dp[i - 1] - dp[last]


class Solution
{
public:
	int distinctSubseqII(string S)
	{
		if (S.empty())
		{
			return 0;
		}
		const static int mod = 1000000007;
		vector<int> dp(S.size() + 1, 0);
		dp[0] = 1;
		vector<int> last(26, -1); //ע�������Ȳ���last[S[0] - 'a'] = 0; ��������һ��dp[S[0] - 'a']
		for (int i = 1; i < dp.size(); ++i)
		{
			dp[i] = dp[i - 1] * 2 % mod;
			int id = S[i - 1] - 'a';
			if (last[id] >= 0)
			{
				dp[i] = (dp[i] + mod - dp[last[id]]) % mod;
			}
			last[id] = i - 1;
		}

		return dp[dp.size() - 1] - 1;
	}
};

//���Ž�
from collections import defaultdict
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        dp = defaultdict(int)
        
        res = 0
        for c in S:
            res, dp[c] = 2 * res - dp[c] + 1, res + 1
			#res = 2 * res - dp[c] + 1
			#dp[c] = res + 1
        
        return res % (10 ** 9 + 7)

����dp������ʱ�临�Ӷȴ�O(N^2)��O(N)
Rui Ban
������ 3 ����ǰ
246 �Ķ�
����
˼·һ
����������һ�㿼�ǽ�β���ַ���ͨ�����ƹ����ظ������⡣

�Ⱦ���������

��s = "abc"��ֱ�۵��뷨����dp[i]Ϊs[:i+1]����s[i]��β���������������������׵õ����ƹ�ϵ��

dp[i+1] = dp[0] + dp[1] + ... + dp[i] + 1������"" + s[i]���������

���û���ظ�Ԫ�أ����ּ�������ȷ�ģ�������Ҫ������α����ظ����㡣

������Ҫ˼�����ǣ��ظ���������β����ġ�

�����������: s="abb"

dp[0]: {"a"}

dp[1]: {"ab", "b"}

dp[2]: {"ab", "abb", "bb", "b"}

�����dp[0]�ĺ�������a��β��������������dp[1]��dp[2]�ĺ���ֱ���ab�к�abb����b��β������������������Ȼdp[2]�ǰ�����dp[1]�ģ�������Ϊab��abb���Ӵ�������dp[1]Ҳ��dp[2]���Ӽ���

����ڼ���ʱ������ÿһ���ַ���Ӧͳ�����µĽ�����������е��Ӽ���

�������˼·������д���ⷨһ��ʱ�临�Ӷ�O(N^2)

˼·��
��˼·һ�У�dp[i]�ĺ�����s[:i+1]����s[i]��β��������������������ÿ���ַ�����ֻ����i����dp[i]��

�����޸�dp�Ķ��壬ʹdp[c]�ĺ���Ϊ��s�����ַ�c��β�����������������������ƹ�ʽ����дΪ��

dp[s[i]] = dp[a] + dp[b] + ... + dp[z] + 1

������s�����ս��Ϊres = dp[a] + dp[b] + ... + dp[z]

����ⷨ���ⷨ����ʱ�临�Ӷ�O(26*N)

˼·��
��˼·���У�ÿ�ε�������Ҫ����dp[a] + dp[b] + ... + dp[z]�����Ա�����������ʹ���ӶȽ�һ�����͵�O(N)

��res = dp[a] + dp[b] + ... + dp[z]�� ����ƹ�ʽΪ��

new_dp[s[i]] = res + 1

new_res = res - dp[s[i]] + new_dp[s[i]]
        = res * 2 - dp[s[i]] + 1
����ⷨ���ⷨ��

���
�ⷨһ
from collections import defaultdict
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        dp = [1] * len(S)
        for i in range(1, len(S)):
            used = set()
            for j in range(i-1, -1, -1):
                if S[j] not in used:
                    dp[i] += dp[j]
                    used.add(S[j])
        res = 0
        u = set()
        for j in range(len(S)-1, -1, -1):
            if S[j] not in u:
                res += dp[j]
                u.add(S[j])    
        return res % (10**9 + 7)
�ⷨ��
from collections import defaultdict
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        dp = defaultdict(int)
        
        for c in S:
            dp[c] = sum(dp.values()) + 1
        
        return sum(dp.values()) % (10 ** 9 + 7)
�ⷨ��
from collections import defaultdict
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        dp = defaultdict(int)
        
        res = 0
        for c in S:
            res, dp[c] = 2 * res - dp[c] + 1, res + 1
        
        return res % (10 ** 9 + 7)