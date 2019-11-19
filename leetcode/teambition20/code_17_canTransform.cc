//��LR�ַ����н��������ַ�
//��һ���� 'L', 'R' �� 'X' �����ַ���ɵ��ַ���������"RXXLRXRXL"���н����ƶ�������
//һ���ƶ�����ָ��һ��"LX"�滻һ��"XL"��������һ��"XR"�滻һ��"RX"��+
//�ָ�����ʼ�ַ���start�ͽ����ַ���end�����д���룬���ҽ�������һϵ���ƶ�����ʹ��start����ת����endʱ�� ����True��
//
//ʾ�� :
//
//����: start = "RXXLRXRXL", end = "XRLXXRRLX"
//	��� : True
//	���� :
//���ǿ���ͨ�����¼�����startת����end:
//	RXXLRXRXL ->
//		XRXLRXRXL ->
//		XRLXRXRXL ->
//		XRLXXRRXL ->
//		XRLXXRRLX
//		ע�� :
//
//	1 <= len(start) = len(end) <= 10000��
//		start��end�е��ַ���������'L', 'R'��'X'��


//ע�Ȿ��Lֻ�������ƶ� Rֻ�������ƶ�
class Solution
{
public:
	bool canTransform(string start, string end) {
		if (start.size() != end.size())
		{
			return false;
		}
		int i = 0;
		int j = 0;
		while (i < start.size() && j < end.size())
		{
			while (start[i] == 'X')
			{
				++i;
			}
			while (end[j] == 'X')
			{
				++j;
			}
			//�����������X�ַ���ͬ�����޳���X֮��Ĵ���Ȼ��ͬ�������Ǵ�ġ�
			if (start[i] != end[j])
			{
				return false;
			}
			//ͬΪL������start��λ����������end����λ�ã�Ҳ�Ǵ�ģ�L���ܺ���
			if (start[i] == 'L' && i < j)
			{
				return false;
			}
			if (start[i] == 'R' && i > j)
			{
				return false;
			}
			++i;
			++j;
		}
		return true;
	}
};