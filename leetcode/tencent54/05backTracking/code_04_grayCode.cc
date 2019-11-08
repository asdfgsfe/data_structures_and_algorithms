���ױ���
���ױ�����һ������������ϵͳ���ڸ�ϵͳ�У�������������ֵ����һ��λ���Ĳ��졣

����һ�����������λ���ķǸ����� n����ӡ����ױ������С����ױ������б����� 0 ��ͷ��

ʾ�� 1:

����: 2
���: [0,1,3,2]
����:
00 - 0
01 - 1
11 - 3
10 - 2

���ڸ����� n������ױ������в���Ψһ��
���磬[0,2,3,1] Ҳ��һ����Ч�ĸ��ױ������С�

00 - 0
10 - 2
11 - 3
01 - 1
ʾ�� 2:

����: 0
���: [0]
����: ���Ƕ�����ױ������б����� 0 ��ͷ��
     ����������λ��Ϊ n �ĸ��ױ������У��䳤��Ϊ 2n���� n = 0 ʱ������Ϊ 20 = 1��
     ��ˣ��� n = 0 ʱ������ױ�������Ϊ [0]��

class Solution {
public:
	vector<int> grayCode(int n) {
		if (n < 0 || n > 32)
		{
			return {};
		}
		int code = 0;
		vector<int> codes = {code};
		unordered_set<int> visited;
		visited.emplace(code);
		CodeProcess(n, codes, visited);
		return codes;
	}

	void CodeProcess(int n, vector<int>& codes, unordered_set<int>& visited)
	{
		assert(!codes.empty());
		int preCode;
		int m;
		for (m = 0; m < n; ++m)
		{
			preCode = codes.back();
			preCode ^= (1 << m);
			if (!visited.count(preCode))
			{
				break;
			}
		}
		if (m == n)
		{
			return;
		}
		codes.emplace_back(preCode);
		visited.emplace(preCode);
		CodeProcess(n, codes, visited);
	}
};