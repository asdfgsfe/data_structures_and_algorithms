˼·�����ݲ���low��high��λ���������λ����Χ��˳������ʱ�临�ӶȺ�low��high��λ����С�йأ�
Ҳ��ʱ�临�Ӷ�Ϊo(1)�ɣ�������ɶ��Բ���ô�ã���Ҷ�ָ����

class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
		//����ֵ
		List<Integer> result = new ArrayList<>();
		//�洢������ֵ��λ��
		int lowBits = 0, highBits = 0;
		//��������ֵ������
		int low2 = low, high2 = high;
		//��λ��
		while (low != 0) {
			lowBits++;
			low = low / 10;
		}
		while (high != 0) {
			highBits++;
			high = high / 10;
		}
		//˼·������������ֵ��λ�����������������˳����
		//���Ƚ�������������ڲ�����λ����Χ��
		for (int i = lowBits; i <= highBits; i++) {
			int value = 0;
			//k����ÿһλ�Ŀ���ȡֵ��1��9 ��������12345 23456������
			for (int k = 1; k <= 9; k++) {
				//��ǰ�˳�ѭ���ı�־
				boolean flag = false;
				//����˳������Ҫ����һλ��ȡֵΪ��һλ+1����Ҫ��index����1
				int index = k;
				//j����λ��
				for (int j = i; j > 0; j--) {
					//������������ȡֵ����9�����˳�ѭ��
					if (index > 9) {
						flag = true;
						break;
					}
					//λ���ı����Ҫ�޸�value��ֵ
					value = value * 10 + index;
					//��һλ����ֵ����1
					index++;
				}
				//��λ�����������ҹ����˳�����ڲ�����Χ�ڣ�����ӵ�����ֵ������
				//�Ż��ĵط����ڴӹ̶����ȵ�λ������Сֵ��ʼȥ��ʼ���� �����Ƿ���[low, high]���жϸ����ֺϷ�
				if (!flag && (value >= low2 && value <= high2)) {
					result.add(value);
				}
				//���㣬��Ӱ�칹����һ��˳����
				value = 0;
			}
		}
		return result;
	}
}