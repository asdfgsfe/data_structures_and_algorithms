//�Ƚϰ汾��
//�Ƚ������汾�� version1 �� version2��
//��� version1 > version2 ���� 1����� version1 < version2 ���� - 1�� ����֮�ⷵ�� 0��
//
//	����Լ���汾�ַ����ǿգ�����ֻ�������ֺ�.�ַ���
//
//	.�ַ�������С���㣬�������ڷָ��������С�
//
//	���磬2.5 ���ǡ������롱��Ҳ���ǡ���һ�뵽���������ǵڶ����еĵ����С�汾��
//
//	����Լ���汾�ŵ�ÿһ����Ĭ���޶����Ϊ 0��
//	���磬�汾�� 3.4 �ĵ�һ������汾���͵ڶ�����С�汾���޶��ŷֱ�Ϊ 3 �� 4����������͵��ļ��޶��ž�Ϊ 0��
//
//
//	ʾ�� 1:
//
//����: version1 = "0.1", version2 = "1.1"
//	��� : -1
//	ʾ�� 2 :
//
//	���� : version1 = "1.0.1", version2 = "1"
//	��� : 1
//	ʾ�� 3 :
//
//	���� : version1 = "7.5.2.4", version2 = "7.5.3"
//	��� : -1
//	ʾ�� 4��
//
//	���룺version1 = "1.01", version2 = "1.001"
//	�����0
//	���ͣ�����ǰ���㣬��01�� �� ��001�� ��ʾ��ͬ������ ��1����
//	ʾ�� 5��
//
//	���룺version1 = "1.0", version2 = "1.0.0"
//	�����0
//	���ͣ�version1 û�е������޶��ţ�����ζ�����ĵ������޶���Ĭ��Ϊ ��0����
//
//
//	��ʾ��
//
//	�汾�ַ������Ե� ��.�� �ָ��������ַ�����ɡ���������ַ���������ǰ���㡣
//	�汾�ַ������Ե㿪ʼ��������������в��������������ĵ㡣

class Solution {
public:
	int compareVersion(string version1, string version2) {
		if (version1.empty())
		{
			return version2.empty() ? 0 : -1;
		}
		if (version2.empty())
		{
			return version1.empty() ? 0 : 1;
		}
		int i = 0;
		int j = 0;
		while (i < version1.size() && j < version2.size())
		{
			int v1 = 0;
			while (i < version1.size() && version1[i] != '.')
			{
				v1 = v1 * 10 + version1[i++] - '0';
			}
			int v2 = 0;
			while (j < version2.size() && version2[j] != '.')
			{
				v2 = v2 * 10 + version2[j++] - '0';
			}
			if (v1 > v2)
			{
				return 1;
			}
			if (v1 < v2)
			{
				return -1;
			}
			++i;
			++j;
		}
		while (i < version1.size())
		{
			if (version1[i] != '.' && version1[i] != '0')
			{
				return 1;
			}
			++i;
		}
		while (j < version2.size())
		{
			if (version2[j] != '.' && version2[j] != '0')
			{
				return -1;
			}
			++j;
		}
		return 0;
	}
};
